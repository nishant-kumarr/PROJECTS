# Simple Banking System

## Overview
This project implements a simple banking system in C language, allowing users to perform basic banking operations such as depositing money, withdrawing money, transferring money to other accounts, checking account details, and viewing transaction history. The system uses file handling to store account information and transaction details.

## Functionality

- **Create or Load Account:**
  - Users can enter their account holder name to check if an account already exists or create a new one if not found.

- **Deposit Money:**
  - Users can deposit a specified amount into their account, and the transaction details are recorded.

- **Withdraw Money:**
  - Users can withdraw a specified amount from their account, provided they have sufficient balance. Transaction details are recorded.

- **Transfer Money:**
  - Users can transfer money to another account by entering the recipient's account number. The transaction details are recorded.

- **Check Account Details:**
  - Users can view their account details, including name, account number, total balance, and the number of transactions made.

- **Transaction History:**
  - Users can view a detailed history of transactions, including date/time and transaction amounts.

## Working

1. **Account Creation/Loading:**
   - User enters account holder name.
   - Checks if the account exists by searching in the file.
   - If found, loads existing account details; otherwise, prompts to create a new account.

2. **Menu-driven Operations:**
   - Users choose operations through a menu (deposit, withdraw, transfer, check details, transaction history, exit).

3. **File Handling:**
   - Utilizes file operations to store and retrieve account information and transaction details.

4. **Transaction Logging:**
   - Records each transaction, including deposit, withdrawal, and transfer, in the file.

## Features

- **Random Account Number Generation:**
  - Generates a random account number for new accounts.

- **Transaction Count:**
  - Keeps track of the number of transactions made from each account.

- **Time-stamped Transactions:**
  - Records the date and time of each transaction.

## Code Explanation

- **File Handling Functions:**
  - `findAccountByName`: Searches for an account in the file by name.
  - `createNewAccount`: Creates a new account with a random account number.

- **Menu Functions:**
  - `menu`: Displays the user menu.
  - Operations such as deposit, withdraw, transfer, check details, and transaction history are implemented as functions.

- **Transaction Functions:**
  - `deposit_money`, `withdraw_money`, `transfer_money`: Handle respective operations and update account information.

- **Account Details Functions:**
  - `checkDetail`, `transaction_details`: Display account details and transaction history.

## Further Possible Expansion

- **Password Protection:**
  - Implement a password system for account security.

- **Multi-User Support:**
  - Extend the system to handle multiple user accounts.

- **Graphical User Interface (GUI):**
  - Enhance the user experience with a graphical interface.

- **Transaction Categories:**
  - Add categories to transactions for better organization.

- **Database Integration:**
  - Replace file handling with a database for improved scalability.

## How to Run

1. Compile the code using a C compiler.
2. Run the executable file in the command line or terminal.
3. Follow the on-screen instructions to perform banking operations.

<div align="right">
<br>
<br>
THANK YOU !!

</div>

