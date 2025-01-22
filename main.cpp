#include <iostream>
#include <vector>
#include <thread>

#include "BankAccount.h"
#include "User.h"

int main () 
{
    double initial_ammount = 1000;
    std::cout << "Set the initial value, if it's empty, it will be 1000 by default" << std::endl;
    std::cin >> initial_ammount;

    BankAccount(initial_ammount);
}