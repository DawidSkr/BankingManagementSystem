#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <stdexcept>

/**
 * @brief A simple bank account class supporting deposit and withdrawal operations.
 */
class Account
{
private:
    double balance; ///< Current balance of the account

public:
    /**
     * @brief Constructor to initialize an account with a given initial balance.
     * @param initialBalance Starting balance (default: 1000.0)
     */
    explicit Account(double initialBalance = 1000.0);

    /**
     * @brief Deposit funds into the account.
     * @param description Description or note for the transaction.
     * @param amount Amount to deposit (must be > 0).
     * @throws std::invalid_argument if amount <= 0.
     */
    void deposit(const std::string &description, double amount);

    /**
     * @brief Withdraw funds from the account.
     * @param description Description or note for the transaction.
     * @param amount Amount to withdraw (must be > 0 and <= balance).
     * @throws std::invalid_argument if amount <= 0.
     * @throws std::out_of_range if amount exceeds current balance.
     */
    void withdraw(const std::string &description, double amount);

    /**
     * @brief Returns the current account balance.
     */
    double getBalance() const;
};

#endif