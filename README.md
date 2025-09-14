# 🏦 Banking Management System – C++ Project

This is a simple banking management system built in C++ as part of my personal portfolio. The project demonstrates object-oriented programming, use of enums, exception handling, and clean code structure.

## 🔧 Technologies Used

- **Language:** C++
- **Concepts:** OOP, enums, exception handling, header/source file separation, STL (std::vector)
- **Features:** Binary file serialization (save/load users & accounts)
- **Tools:** g++, CLI

## 📚 Project Overview

The system supports basic banking operations:
- User registration and secure login, allowing users to create an account, log in securely with a password, and manage their banking operations
- Creating a user with a unique 10-digit account number and an associated account with an optional initial balance
- Making deposits (with validation)
- Performing withdrawals (with balance and error checks)
- Tracking all transactions using a `Transaction` class with enum-based transaction types
- Printing full transaction history to the console
- Handling errors via exceptions (`std::invalid_argument`, `std::out_of_range`)

## 🖥️ User Interaction (Menu System)

The program now features an interactive command-line menu that allows users to:

- Deposit funds with custom descriptions
- Withdraw funds with validation and balance checks
- View the current account balance
- Display the full transaction history
- Show the user’s unique 10-digit account number
- Save user data to a binary file for persistence
- Log Out to end the current user session
- Exit the application gracefully

This menu-driven interface improves usability by providing a simple and intuitive way to interact with the banking system.

## 💡 Purpose

This project helped me practice:
- Designing clean and reusable C++ classes with separation into header and source files
- Implementing enum classes for improved type safety and clarity
- Managing error states using exceptions
- Utilizing STL containers (`std::vector`) for managing collections of objects
- Building maintainable CLI applications with proper logging and feedback

## 🧪 How to Build and Run

```bash
g++ src/main.cpp src/Account.cpp src/Transaction.cpp src/User.cpp -Iinclude -o build/Release/BankingSystem.exe
./build/Release/BankingSystem.exe
