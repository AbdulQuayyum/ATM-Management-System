#include <iostream>
#include <vector>

struct Account
{
  int AccountNumber;
  int Pin;
  std::string Name;
  std::string AccountType;
  double Balance;
};

int main()
{
  // Create an array of Account structs
  std::vector<Account> Accounts = {
      {1111, 1111, "Usman Ismaeel-Awwal", "Savings", 1000.00},
      {2222, 2222, "Ayinla Akerekoro", "Savings", 500.00},
      {3333, 3333, "Ajani Ajanlekoko", "Current", 150000.0}};

  int UserAccountNumber, UserPin;
  std::cout << "Enter your account number: ";
  std::cin >> UserAccountNumber;

  std::cout << "Enter your PIN: ";
  std::cin >> UserPin;

  bool found = false;
  Account foundAccount;
  for (const Account &account : Accounts)
  {
    if (account.AccountNumber == UserAccountNumber && account.Pin == UserPin)
    {
      found = true;
      foundAccount = account;
      break;
    }
  }

  if (found)
  {
    std::cout << "Access granted. Welcome, " << foundAccount.Name << "!" << std::endl;
    std::cout << "Account Type: " << foundAccount.AccountType << std::endl;
    std::cout << "Account Balance: ₦" << foundAccount.Balance << std::endl;
    // Perform other operations here
  }
  else
  {
    std::cout << "Invalid account number or PIN. Access denied." << std::endl;
  }

  return 0;
}
