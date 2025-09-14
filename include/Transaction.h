#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <fstream>

/**
 * @enum TransactionType
 * @brief Enum for type of banking transaction.
 */
enum class TransactionType
{
    Deposit,
    Withdraw
};

/**
 * @class Transaction
 * @brief Represents a single banking transaction.
 */
class Transaction
{
private:
    TransactionType type;    ///< Transaction type: Deposit or Withdraw
    std::string description; ///< Description of the transaction
    double amount;           ///< Amount of money involved in the transaction

public:
    /**
     * @brief Construct a new Transaction object.
     * @param transactionType Type of transaction ("Deposit" or "Withdraw").
     * @param desc Description or note about the transaction.
     * @param amt Amount of money transacted.
     */
    Transaction(TransactionType transactionType, const std::string &desc, double amt);

    /**
     * @brief Prints the transaction details to the console.
     */
    void printTransaction() const;

    /**
     * @brief Writes transaction data to a binary file.
     * @param outFile Output file stream to which the transaction data will be written.
     */
    void writeToFile(std::ofstream &outFile) const;

    /**
     * @brief Reads transaction data from a binary file.
     * @param inFile Input file stream from which the transaction data will be read.
     */
    static Transaction readFromFile(std::ifstream &inFile);
};

#endif // TRANSACTION_H