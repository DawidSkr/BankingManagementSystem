#include "Account.h"
#include "User.h"
#include <iostream>
#include <limits>

// Displays the main menu options to the user
void showMenu()
{
    std::cout << "\n=== Banking Management System Menu ===\n";
    std::cout << "1. Deposit\n";
    std::cout << "2. Withdraw\n";
    std::cout << "3. Show Balance\n";
    std::cout << "4. Show Transaction History\n";
    std::cout << "5. Show Account Number\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}
// Gets the user's menu choice and validates input
int getUserChoice()
{
    int choice;
    std::cin >> choice;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    return choice;
}

// Handles deposit operation, including input and error handling
void handleDeposit(Account &account)
{
    std::cout << "Enter deposit description: ";
    std::string desc;
    std::cin.ignore(); // czyścimy bufor po poprzednim wejściu
    std::getline(std::cin, desc);

    std::cout << "Enter deposit amount: ";
    double amount;
    std::cin >> amount;

    try
    {
        account.deposit(desc, amount);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error during deposit: " << e.what() << std::endl;
    }
}

// Handles withdrawal operation, including input and error handling
void handleWithdraw(Account &account)
{
    std::cout << "Enter withdrawal description: ";
    std::string desc;
    std::cin.ignore();
    std::getline(std::cin, desc);

    std::cout << "Enter withdrawal amount: ";
    double amount;
    std::cin >> amount;

    try
    {
        account.withdraw(desc, amount);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error during withdrawal: " << e.what() << std::endl;
    }
}

// Displays the current account balance
void showBalance(const Account &account)
{
    std::cout << "Current balance: " << account.getBalance() << " USD" << std::endl;
}

// Displays the full transaction history
void showTransactionHistory(const Account &account)
{
    account.printTransactionHistory();
}

// Displays the user's account number
void showAccountNumber(const User &user)
{
    std::cout << "Account Number: " << user.getAccountNumber() << std::endl;
}

int main()
{
    std::cout << "=== Banking Management System ===" << std::endl;

    User user("John Doe");

    bool running = true;
    while (running)
    {
        showMenu();
        int choice = getUserChoice();

        switch (choice)
        {
        case 1:
            handleDeposit(user.getAccount());
            break;
        case 2:
            handleWithdraw(user.getAccount());
            break;
        case 3:
            showBalance(user.getAccount());
            break;
        case 4:
            showTransactionHistory(user.getAccount());
            break;
        case 5:
            showAccountNumber(user);
            break;
        case 6:
            std::cout << "Exiting program. Goodbye!" << std::endl;
            running = false;
            break;
        default:
            std::cerr << "Invalid option, please try again." << std::endl;
            break;
        }
    }

    return 0;
}