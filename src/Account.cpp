#include "Account.h"
#include <iostream>

// Constructor with optional initial balance
Account::Account(double initialBalance)
    : balance(initialBalance)
{
    std::cout << "Account created with initial balance: " << balance << " USD" << std::endl;
}

void Account::deposit(const std::string &description, double amount)
{
    std::cout << "[Deposit] Attempting to deposit: " << amount << " USD" << std::endl;

    if (amount <= 0)
    {
        throw std::invalid_argument("Deposit amount must be greater than zero.");
    }

    balance += amount;
    Transaction transaction(TransactionType::Deposit, description, amount);
    transactionHistory.push_back(transaction);

    std::cout << "[Deposit] New balance: " << balance << " USD" << std::endl;
}

void Account::withdraw(const std::string &description, double amount)
{
    std::cout << "[Withdraw] Attempting to withdraw: " << amount << " USD" << std::endl;

    if (amount <= 0)
    {
        throw std::invalid_argument("Withdrawal amount must be greater than zero.");
    }

    if (amount > balance)
    {
        throw std::out_of_range("Insufficient funds for withdrawal.");
    }

    balance -= amount;
    Transaction transaction(TransactionType::Withdraw, description, amount);
    transactionHistory.push_back(transaction);

    std::cout << "[Withdraw] New balance: " << balance << " USD" << std::endl;
}

void Account::printTransactionHistory() const
{
    std::cout << "=== Transaction History ===" << std::endl;
    if (transactionHistory.empty())
    {
        std::cout << "No transactions found." << std::endl;
        return;
    }

    for (const auto &transaction : transactionHistory)
    {
        transaction.printTransaction();
    }
}

double Account::getBalance() const
{
    return balance;
}

void Account::writeToFile(std::ofstream &outFile) const
{
    outFile.write(reinterpret_cast<const char *>(&balance), sizeof(balance));
    size_t historySize = transactionHistory.size();
    outFile.write(reinterpret_cast<const char *>(&historySize), sizeof(historySize));

    for (const auto &transaction : transactionHistory)
    {
        transaction.writeToFile(outFile);
    }
}

void Account::readFromFile(std::ifstream &inFile)
{
    inFile.read(reinterpret_cast<char *>(&balance), sizeof(balance));

    size_t historySize;
    inFile.read(reinterpret_cast<char *>(&historySize), sizeof(historySize));

    transactionHistory.clear();
    for (size_t i = 0; i < historySize; ++i)
    {
        transactionHistory.push_back(Transaction::readFromFile(inFile));
    }
}