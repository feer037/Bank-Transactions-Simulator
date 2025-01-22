#include <iostream>
#include <vector>
#include <thread>

#include "BankAccount.h"
#include "User.h"

int main() {
    BankAccount account(500.0);

    int numUsers;
    std::cout << "Enter the number of users: ";
    std::cin >> numUsers;
    std::cin.ignore();

    int numOperations;
    std::cout << "Enter the number of operations per user: ";
    std::cin >> numOperations;
    std::cin.ignore();

    std::vector<User> users;
    for (int i = 0; i < numUsers; ++i) {
        std::string name;
        std::cout << "Enter the name of User " << (i + 1) << ": ";
        std::getline(std::cin, name);
        users.push_back(User(name, &account, numOperations));
    }

    std::vector<std::thread> threads;
    for (auto& user : users) {
        threads.push_back(std::thread(&User::performRandomOperations, &user));
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
