#ifndef USER_H
#define USER_H

#include "Account.h"
#include <string>

/**
 * @class User
 * @brief Represents a user with a bank account and a unique account number.
 */
class User
{
private:
    std::string name;          ///< User's full name
    std::string accountNumber; ///< Bank account number (unique identifier)
    Account account;           ///< User's bank account

    /**
     * @brief Generates a random 10-digit account number as a string.
     * @return A string containing a 10-digit random number.
     */
    static std::string generateRandomAccountNumber();

public:
    /**
     * @brief Constructs a User with a given name and optional initial balance.
     * Automatically generates a random 10-digit account number.
     * @param userName The name of the user.
     * @param initialBalance The starting balance for the account (default 1000.0).
     */
    explicit User(const std::string &userName, double initialBalance = 1000.0);

    /**
     * @brief Get the user's name.
     */
    std::string getName() const;

    /**
     * @brief Get the user's account number.
     */
    std::string getAccountNumber() const;

    /**
     * @brief Get the user's account (read-only).
     */
    const Account &getAccount() const;

    /**
     * @brief Get the user's account (modifiable).
     */
    Account &getAccount();
};

#endif // USER_H
