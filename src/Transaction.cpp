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