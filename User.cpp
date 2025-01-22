#include <iostream>
#include <random>
#include <iomanip>
#include <mutex>
#include <thread>
#include <chrono>

#include "User.h"

std::mutex cout_mutex;

User::User(const std::string& name, BankAccount* account, int numOperations) : name_(name), account_(account), numOperations_(numOperations) {}

void User::performRandomOperations() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3); // 1=Deposit, 2=Withdraw, 3=Check balance
    std::uniform_real_distribution<> amount_dis(10.0, 100.0);

    for (int i = 0; i < numOperations_; ++i) {
        int operation = dis(gen);
        double amount = amount_dis(gen);

        // Log de inicio de operación
        logToConsole("User " + name_ + " started their operation.");

        switch (operation) {
        case 1:  // Deposit
            account_->deposit(amount);
            logToConsole("User " + name_ + " performed a deposit of " + std::to_string(amount) +
                ". New balance: " + std::to_string(account_->getBalance()));
            break;

        case 2:  // Withdraw
            if (account_->withdraw(amount)) {
                logToConsole("User " + name_ + " performed a withdrawal of " + std::to_string(amount) +
                    ". New balance: " + std::to_string(account_->getBalance()));
            }
            else {
                logToConsole("User " + name_ + " attempted to withdraw " + std::to_string(amount) +
                    " but failed due to insufficient funds.");
            }
            break;

        case 3:  // Check balance
            logToConsole("User " + name_ + " checked the balance. Current balance: " +
                std::to_string(account_->getBalance()));
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void User::logToConsole(const std::string& message) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << std::fixed << std::setprecision(2) << message << std::endl;
}