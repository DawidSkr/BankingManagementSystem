# 🏦 Banking Management System – C++ Project

This is a simple banking management system built in C++ as part of my personal portfolio. The project demonstrates object-oriented programming, use of enums, exception handling, and clean code structure.

## 🔧 Technologies Used

- **Language:** C++
- **Concepts:** OOP, enums, exception handling, header/source file separation, STL (std::vector)
- **Tools:** g++, CLI

## 📚 Project Overview

The system supports basic banking operations:
- Creating an account with an optional initial balance
- Making deposits (with validation)
- Performing withdrawals (with balance and error checks)
- Tracking all transactions using a `Transaction` class with enum-based transaction types
- Printing full transaction history to the console
- Handling errors via exceptions (`std::invalid_argument`, `std::out_of_range`)

## 💡 Purpose

This project helped me practice:
- Designing clean and reusable C++ classes with separation into header and source files
- Implementing enum classes for improved type safety and clarity
- Managing error states using exceptions
- Utilizing STL containers (`std::vector`) for managing collections of objects
- Building maintainable CLI applications with proper logging and feedback

## 🧪 How to Build and Run

```bash
g++ src/main.cpp src/Account.cpp src/Transaction.cpp -Iinclude -o build/Release/BankingSystem.exe
./build/Release/BankingSystem.exe
