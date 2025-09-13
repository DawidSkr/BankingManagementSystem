#include "Account.h"
#include <iostream>

int main()
{
    std::cout << "=== Banking Management System ===" << std::endl;

    try
    {
        // Create a new bank account with a default initial balance
        Account userAccount;

        // Make an initial deposit
        userAccount.deposit("Initial deposit", 500.0);

        // Perform a withdrawal
        userAccount.withdraw("ATM Withdrawal", 200.0);

        // Print all transaction history
        userAccount.printTransactionHistory();

        // Display the final account balance after all transactions
        std::cout << "Final balance: " << userAccount.getBalance() << " USD" << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: Invalid argument - " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Error: Out of range - " << e.what() << std::endl;
    }

    return 0;
}