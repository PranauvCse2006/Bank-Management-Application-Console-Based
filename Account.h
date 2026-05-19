#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Account
{
private:

    int accountNumber;

    string customerName;

    int accountPIN;

    double accountBalance;

public:

    
    Account();

    
    void createAccount();

    bool loginAccount();

    void depositMoney();

    void withdrawMoney();

    void checkBalance();

    void displayAccountDetails();

   
    void saveAccountToFile();

    bool searchAccount(int);

    void updateAccountInFile();

    
    int getAccountNumber();
    void addTransaction(string);

    void showTransactionHistory();

    void adminPanel();

    void viewAllAccounts();

    void deleteAccount();
};

#endif