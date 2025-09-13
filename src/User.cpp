#include "User.h"
#include <random>
#include <sstream>
#include <iomanip>

// Generate random 10-digit account number as string
std::string User::generateRandomAccountNumber()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<unsigned long long> dis(1000000000ULL, 9999999999ULL);

    unsigned long long num = dis(gen);

    std::ostringstream oss;
    oss << num;

    return oss.str();
}

User::User(const std::string &userName, double initialBalance)
    : name(userName), accountNumber(generateRandomAccountNumber()), account(initialBalance) {}

std::string User::getName() const
{
    return name;
}

std::string User::getAccountNumber() const
{
    return accountNumber;
}

const Account &User::getAccount() const
{
    return account;
}

Account &User::getAccount()
{
    return account;
}
