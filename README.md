# 🏦 Banking Management System – C++ Project

This is a simple banking management system built in C++ as part of my personal portfolio. The project demonstrates basic object-oriented programming, exception handling, and clean code structure.

## 🔧 Technologies Used

- **Language:** C++
- **Concepts:** OOP, exception handling, header/source file separation
- **Tools:** g++, CLI

## 📚 Project Overview

The system allows basic banking operations:
- Creating an account with an optional initial balance
- Making deposits (with validation)
- Performing withdrawals (with balance checks)
- Handling errors through exceptions (`std::invalid_argument`, `std::out_of_range`)
- Logging actions to the console

## 💡 Purpose

The goal of this project was to strengthen my understanding of:
- Designing clean and reusable C++ classes
- Separating logic into header and source files
- Using exception handling to manage error states
- Building maintainable CLI applications

## 🧪 How to Run

```bash
g++ src/main.cpp src/Account.cpp -Iinclude -o build/Release/BankingSystem.exe
.\build\Release\BankingSystem.exe
