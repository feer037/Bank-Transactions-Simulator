#include "BankAccount.h"


BankAccount::BankAccount(double initial_account_balance) :
    account_balance_(initial_account_balance)
{}

void BankAccount::deposit(double ammount_to_deposit) 
{
    std::lock_guard<std::mutex> lock(bank_account_mutex);
    account_balance_ += ammount_to_deposit;
}

bool BankAccount::withdraw(double ammount_to_withdraw)
{
    std::lock_guard<std::mutex> lock(bank_account_mutex);
    if (ammount_to_withdraw > account_balance_)
    {
        return false;
    }
    account_balance_ -= ammount_to_withdraw;
    return true;
}

double BankAccount::getBalance()
{
    std::lock_guard<std::mutex> lock(bank_account_mutex);
    return account_balance_;
}