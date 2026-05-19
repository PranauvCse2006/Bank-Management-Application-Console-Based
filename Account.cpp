#include "Account.h"

Account::Account()
{
    accountNumber = 0;
    customerName = "";
    accountPIN = 0;
    accountBalance = 0.0;
}

void Account::createAccount()
{
    cout << "\n====================================";
    cout << "\n        CREATE ACCOUNT";
    cout << "\n====================================";

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    cout << "Enter Customer Name: ";
    cin >> customerName;

    cout << "Create 4-Digit PIN: ";
    cin >> accountPIN;

    cout << "Enter Initial Balance: Rs.";
    cin >> accountBalance;

    saveAccountToFile();

    cout << "\n Account Created Successfully!";
}

void Account::saveAccountToFile()
{
    ofstream file("accounts.txt", ios::app);

    file << accountNumber << " "
         << customerName << " "
         << accountPIN << " "
         << accountBalance << endl;

    file.close();
}

bool Account::loginAccount()
{
    int enteredAccountNumber;
    int enteredPIN;

    cout << "\nEnter Account Number: ";
    cin >> enteredAccountNumber;

    cout << "Enter PIN: ";
    cin >> enteredPIN;

    ifstream file("accounts.txt");

    while(file >> accountNumber
               >> customerName
               >> accountPIN
               >> accountBalance)
    {
        if(accountNumber == enteredAccountNumber &&
           accountPIN == enteredPIN)
        {
            cout << "\n Login Successful!";
            file.close();
            return true;
        }
    }

    file.close();

    cout << "\n Invalid Account Number or PIN!";
    return false;
}

bool Account::searchAccount(int searchAccountNumber)
{
    ifstream file("accounts.txt");

    while(file >> accountNumber
               >> customerName
               >> accountPIN
               >> accountBalance)
    {
        if(accountNumber == searchAccountNumber)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void Account::depositMoney()
{
    double depositAmount;

    cout << "\nEnter Amount To Deposit: Rs.";
    cin >> depositAmount;

    if(depositAmount <= 0)
    {
        cout << "\n Invalid Amount!";
        return;
    }

    accountBalance += depositAmount;

updateAccountInFile();

addTransaction(
    "[DEPOSIT] Rs." + to_string((int)depositAmount)
);

cout << "\n Amount Deposited Successfully!";
}
void Account::withdrawMoney()
{
    double withdrawAmount;

    cout << "\nEnter Amount To Withdraw: Rs.";
    cin >> withdrawAmount;

    if(withdrawAmount > accountBalance)
    {
        cout << "\n Insufficient Balance!";
        return;
    }

    accountBalance -= withdrawAmount;

    updateAccountInFile();

    addTransaction(
        "[WITHDRAW] Rs." + to_string((int)withdrawAmount)
    );

    cout << "\n Withdrawal Successful!";
}

void Account::checkBalance()
{
    cout << "\n====================================";
    cout << "\n         ACCOUNT BALANCE";
    cout << "\n====================================";

    cout << "\nCustomer Name : " << customerName;
    cout << "\nAccount Number: " << accountNumber;
    cout << "\nBalance        : Rs." << accountBalance;

    cout << "\n====================================";
}

void Account::displayAccountDetails()
{
    cout << "\n====================================";
    cout << "\n        ACCOUNT DETAILS";
    cout << "\n====================================";

    cout << "\nCustomer Name : " << customerName;
    cout << "\nAccount Number: " << accountNumber;
    cout << "\nBalance        : Rs." << accountBalance;

    cout << "\n====================================";
}

void Account::updateAccountInFile()
{
    ifstream file("accounts.txt");

    ofstream tempFile("temp.txt");

    int tempAccountNumber;
    string tempCustomerName;
    int tempPIN;
    double tempBalance;

    while(file >> tempAccountNumber
               >> tempCustomerName
               >> tempPIN
               >> tempBalance)
    {
        if(tempAccountNumber == accountNumber)
        {
            tempFile << accountNumber << " "
                     << customerName << " "
                     << accountPIN << " "
                     << accountBalance << endl;
        }
        else
        {
            tempFile << tempAccountNumber << " "
                     << tempCustomerName << " "
                     << tempPIN << " "
                     << tempBalance << endl;
        }
    }

    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}

int Account::getAccountNumber()
{
    return accountNumber;
}
void Account::addTransaction(string message)
{
    ofstream file("transactions.txt", ios::app);

    file << "Account Number: "
         << accountNumber
         << " -> "
         << message
         << endl;

    file.close();
}
void Account::showTransactionHistory()
{
    ifstream file("transactions.txt");

    string line;

    cout << "\n====================================";
    cout << "\n       TRANSACTION HISTORY";
    cout << "\n====================================\n";

    while(getline(file, line))
    {
        if(line.find(to_string(accountNumber))
            != string::npos)
        {
            cout << line << endl;
        }
    }

    file.close();
}
void Account::viewAllAccounts()
{
    ifstream file("accounts.txt");

    int accNo;
    string name;
    int pin;
    double balance;

    cout << "\n====================================";
    cout << "\n          ALL ACCOUNTS";
    cout << "\n====================================\n";

    while(file >> accNo
               >> name
               >> pin
               >> balance)
    {
        cout << "Account Number : "
             << accNo << endl;

        cout << "Customer Name  : "
             << name << endl;

        cout << "Balance         : Rs."
             << balance << endl;

        cout << "------------------------------------\n";
    }

    file.close();
}
void Account::deleteAccount()
{
    int deleteAccountNumber;

    cout << "\nEnter Account Number To Delete: ";
    cin >> deleteAccountNumber;

    ifstream file("accounts.txt");

    ofstream tempFile("temp.txt");

    int accNo;
    string name;
    int pin;
    double balance;

    bool found = false;

    while(file >> accNo
               >> name
               >> pin
               >> balance)
    {
        if(accNo == deleteAccountNumber)
        {
            found = true;
            continue;
        }

        tempFile << accNo << " "
                 << name << " "
                 << pin << " "
                 << balance << endl;
    }

    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if(found)
    {
        cout << "\n Account Deleted Successfully!";
    }
    else
    {
        cout << "\n Account Not Found!";
    }
}