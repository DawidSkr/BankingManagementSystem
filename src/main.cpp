#include "Account.h"
#include "User.h"
#include <iostream>
#include <string>
#include <limits>
#include <unordered_map>
#include <fstream>

void saveUsersToFile(const std::string &filename);
void loadUsersFromFile(const std::string &filename);

std::unordered_map<std::string, User> users;

// Displays the main menu options to the user
void showMenu()
{
    std::cout << "\n=== Banking Management System Menu ===\n";
    std::cout << "1. Deposit\n";
    std::cout << "2. Withdraw\n";
    std::cout << "3. Show Balance\n";
    std::cout << "4. Show Transaction History\n";
    std::cout << "5. Show Account Number\n";
    std::cout << "6. Save User to File\n";
    std::cout << "7. Log out\n";
    std::cout << "8. Exit\n";
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
    std::cin.ignore();
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

void registerUser()
{
    std::cout << "Enter your name for registration: ";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter your password for registration: ";
    std::string password;
    std::cin >> password;

    User newUser(name, password);

    users[newUser.getAccountNumber()] = newUser;
    std::cout << "Registration successful! Your account number is " << newUser.getAccountNumber() << std::endl;

    saveUsersToFile("bin/users.dat");
}

// Function for user login
User *loginUser()
{
    std::cout << "Enter your account number: ";
    std::string accountNumber;
    std::cin >> accountNumber;

    if (users.find(accountNumber) != users.end())
    {
        std::cout << "Account found! Enter your password: ";
        std::string password;
        std::cin >> password;

        if (users[accountNumber].checkPassword(password))
        {
            std::cout << "Login successful!" << std::endl;
            return &users[accountNumber];
        }
        else
        {
            std::cerr << "Incorrect password. Please try again." << std::endl;
            return nullptr;
        }
    }
    else
    {
        std::cerr << "Account not found. Please check your account number." << std::endl;
        return nullptr;
    }
}

// Function to save all users to a binary file
void saveUsersToFile(const std::string &filename)
{
    std::ofstream outFile(filename, std::ios::binary);

    if (!outFile)
    {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    size_t userCount = users.size();
    outFile.write(reinterpret_cast<const char *>(&userCount), sizeof(userCount));

    for (const auto &userPair : users)
    {
        userPair.second.writeToFile(outFile);
    }

    outFile.close();
    std::cout << "Users have been successfully saved to the file!" << std::endl;
}

// Function to load all users from a binary file
void loadUsersFromFile(const std::string &filename)
{
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile)
    {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    size_t userCount;
    inFile.read(reinterpret_cast<char *>(&userCount), sizeof(userCount));

    for (size_t i = 0; i < userCount; ++i)
    {
        User user = User::readFromFile(inFile);
        users[user.getAccountNumber()] = user;
    }

    inFile.close();
    std::cout << "Users have been successfully loaded from the file!" << std::endl;
}

int main()
{
    std::cout << "=== Banking Management System ===" << std::endl;

    loadUsersFromFile("bin/users.dat");

    User *currentUser = nullptr;

    bool running = true;
    while (running)
    {
        if (currentUser == nullptr)
        {
            std::cout << "\n=== Main Menu ===\n";
            std::cout << "1. Register\n";
            std::cout << "2. Login\n";
            std::cout << "3. Exit\n";
            std::cout << "Choose an option: ";

            int choice = getUserChoice();

            switch (choice)
            {
            case 1:
                registerUser();
                break;
            case 2:
                currentUser = loginUser();
                break;
            case 3:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                running = false;
                break;
            default:
                std::cerr << "Invalid option, please try again." << std::endl;
                break;
            }
        }
        else
        {
            bool sessionRunning = true;
            while (sessionRunning)
            {
                showMenu();
                int choice = getUserChoice();

                switch (choice)
                {
                case 1:
                    handleDeposit(currentUser->getAccount());
                    break;
                case 2:
                    handleWithdraw(currentUser->getAccount());
                    break;
                case 3:
                    showBalance(currentUser->getAccount());
                    break;
                case 4:
                    showTransactionHistory(currentUser->getAccount());
                    break;
                case 5:
                    showAccountNumber(*currentUser);
                    break;
                case 6:
                    saveUsersToFile("bin/users.dat");
                    break;
                case 7:
                    std::cout << "Logging out..." << std::endl;
                    currentUser = nullptr;
                    sessionRunning = false;
                    break;
                case 8:
                    std::cout << "Exiting program. Goodbye!" << std::endl;
                    running = false;
                    sessionRunning = false;
                    break;
                default:
                    std::cerr << "Invalid option, please try again." << std::endl;
                    break;
                }
            }
        }
    }

    return 0;
}