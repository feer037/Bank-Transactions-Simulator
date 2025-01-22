#pragma once
#include <mutex>

class BankAccount {
  public:
    
    // Set an initial account balance
    BankAccount(double initial_account_balance);
    
    // Deposit money in the account
    void deposit(double ammount_to_deposit);
    
    // Withdraw money to the account
    bool withdraw(double ammount_to_withdraw);
    
    // Get the balance of the account
    double getBalance();
        
  private:
    double account_balance_;
    std::mutex bank_account_mutex;
public:

    BankAccount() = default;
};