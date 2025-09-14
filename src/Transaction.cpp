#include "Transaction.h"
#include <iostream>

Transaction::Transaction(TransactionType transactionType, const std::string &desc, double amt)
    : type(transactionType), description(desc), amount(amt) {}

void Transaction::printTransaction() const
{
    std::string typeStr;
    switch (type)
    {
    case TransactionType::Deposit:
        typeStr = "Deposit";
        break;
    case TransactionType::Withdraw:
        typeStr = "Withdraw";
        break;
    }

    std::cout << typeStr << " | Amount: " << amount << " USD | Description: " << description << std::endl;
}

void Transaction::writeToFile(std::ofstream &outFile) const
{
    outFile.write(reinterpret_cast<const char *>(&type), sizeof(type));
    size_t descLength = description.size();
    outFile.write(reinterpret_cast<const char *>(&descLength), sizeof(descLength));
    outFile.write(description.c_str(), descLength);
    outFile.write(reinterpret_cast<const char *>(&amount), sizeof(amount));
}

Transaction Transaction::readFromFile(std::ifstream &inFile)
{
    TransactionType type;
    inFile.read(reinterpret_cast<char *>(&type), sizeof(type));

    size_t descLength;
    inFile.read(reinterpret_cast<char *>(&descLength), sizeof(descLength));
    std::string description(descLength, ' ');
    inFile.read(&description[0], descLength);

    double amount;
    inFile.read(reinterpret_cast<char *>(&amount), sizeof(amount));

    return Transaction(type, description, amount);
}