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

    std::cout << "[Withdraw] New balance: " << balance << " USD" << std::endl;
}

double Account::getBalance() const
{
    return balance;
}