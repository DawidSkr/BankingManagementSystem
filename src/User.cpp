#include "User.h"
#include <random>
#include <sstream>
#include <iomanip>
#include <fstream>

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

User::User(const std::string &userName, const std::string &userPassword, double initialBalance)
    : name(userName), password(userPassword), accountNumber(generateRandomAccountNumber()), account(initialBalance) {}

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

bool User::checkPassword(const std::string &inputPassword) const
{
    return password == inputPassword;
}

void User::writeToFile(std::ofstream &outFile) const
{
    size_t nameLength = name.size();
    outFile.write(reinterpret_cast<const char *>(&nameLength), sizeof(nameLength));
    outFile.write(name.c_str(), nameLength);

    size_t passLength = password.size();
    outFile.write(reinterpret_cast<const char *>(&passLength), sizeof(passLength));
    outFile.write(password.c_str(), passLength);

    size_t accLength = accountNumber.size();
    outFile.write(reinterpret_cast<const char *>(&accLength), sizeof(accLength));
    outFile.write(accountNumber.c_str(), accLength);

    account.writeToFile(outFile);
}

User User::readFromFile(std::ifstream &inFile)
{
    User user;

    size_t nameLength;
    inFile.read(reinterpret_cast<char *>(&nameLength), sizeof(nameLength));
    user.name.resize(nameLength);
    inFile.read(&user.name[0], nameLength);

    size_t passLength;
    inFile.read(reinterpret_cast<char *>(&passLength), sizeof(passLength));
    user.password.resize(passLength);
    inFile.read(&user.password[0], passLength);

    size_t accLength;
    inFile.read(reinterpret_cast<char *>(&accLength), sizeof(accLength));
    user.accountNumber.resize(accLength);
    inFile.read(&user.accountNumber[0], accLength);

    user.account.readFromFile(inFile);

    return user;
}