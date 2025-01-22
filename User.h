#include <string>
#include "BankAccount.h"

class User {

  public:
    // Constructor
      User(const std::string& name, BankAccount* account, int numOperations);

    // Makes random operations as withdraw, deposit or account check
    void performRandomOperations();
    void logToConsole(const std::string& message);
  private:
    std::string  name_;
    BankAccount* account_;
    int numOperations_;

};