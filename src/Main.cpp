#include <iostream>
#include <vector>
#include <limits>

struct Account
{
  int AccountNumber;
  int Pin;
  std::string Name;
  std::string AccountType;
  double Balance;
};

// Function to display the account information
void DisplayAccount(const Account &account)
{
  std::cout << "Account Number: " << account.AccountNumber << std::endl;
  std::cout << "Name: " << account.Name << std::endl;
  std::cout << "Account Type: " << account.AccountType << std::endl;
  std::cout << "Account Balance: ₦" << account.Balance << std::endl;
}

int main()
{
  // An array of Accounts
  std::vector<Account> Accounts = {
      {1111, 1111, "Usman Ismaeel-Awwal", "Savings", 1000.00},
      {2222, 2222, "Ayinla Akerekoro", "Savings", 500.00},
      {3333, 3333, "Ajani Ajanlekoko", "Current", 150000.0}};

  std::cout << "************************************** Welcome to Soft ATM **************************************";

  int UserAccountNumber, UserPin;
  std::cout << "Enter your account number: ";
  std::cin >> UserAccountNumber;

  std::cout << "Enter your PIN: ";
  std::cin >> UserPin;

  bool found = false;
  Account FoundAccount;

  // Search if the user's account exists in the database
  for (const Account &account : Accounts)
  {
    if (account.AccountNumber == UserAccountNumber && account.Pin == UserPin)
    {
      found = true;
      FoundAccount = account;
      break;
    }
  }

  if (found)
  {
    std::cout << "Access granted. Welcome, " << FoundAccount.Name << "!" << std::endl;

    // Operations the User can carry out
    int choice;
    do
    {
      std::cout << "************************************** Menu **************************************" << std::endl;
      std::cout << "1. Account Enquiry" << std::endl;
      std::cout << "2. Deposit Money" << std::endl;
      std::cout << "3. Withdraw Money" << std::endl;
      std::cout << "4. Change PIN" << std::endl;
      std::cout << "5. Close" << std::endl;
      std::cout << "Enter your choice (1-5): ";
      std::cin >> choice;

      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid choice (1-5)." << std::endl;
        continue;
      }

      switch (choice)
      {
      case 1:
        // Account Enquiry
        DisplayAccount(FoundAccount);
        break;
      case 2:
        // Deposit Money
        double DepositAmount;
        std::cout << "Enter the amount to deposit: ₦";
        std::cin >> DepositAmount;
        FoundAccount.Balance += DepositAmount;
        std::cout << "Deposit successful. Updated balance: ₦" << FoundAccount.Balance << std::endl;
        break;
      case 3:
        // Withdraw Money
        double WithdrawAmount;
        std::cout << "Enter the amount to withdraw: ₦";
        std::cin >> WithdrawAmount;
        if (WithdrawAmount <= FoundAccount.Balance)
        {
          FoundAccount.Balance -= WithdrawAmount;
          std::cout << "Withdrawal successful. Updated balance: ₦" << FoundAccount.Balance << std::endl;
        }
        else
        {
          std::cout << "Insufficient funds. Withdrawal failed." << std::endl;
        }
        break;
      case 4:
        // Change PIN
        int newPin;
        std::cout << "Enter your new PIN: ";
        std::cin >> newPin;
        FoundAccount.Pin = newPin;
        std::cout << "PIN changed successfully." << std::endl;
        break;
      case 5:
        // Close
        std::cout << "Thank you for using the ATM. Goodbye!" << std::endl;
        break;
      default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
      }
    } while (choice != 5);
  }
  else
  {
    std::cout << "Invalid account number or PIN. Access denied." << std::endl;
  }

  return 0;
}
