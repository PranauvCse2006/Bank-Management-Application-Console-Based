#include <iostream>
#include <cstdlib>

#include "Account.h"

using namespace std;

void showMainMenu()
{
    cout << "\n========================================";
    cout << "\n       BANK MANAGEMENT SYSTEM";
    cout << "\n========================================";

    cout << "\n1. Create Account";
    cout << "\n2. Login";
    cout << "\n3. Admin Login";
    cout << "\n4. Exit";

    cout << "\n========================================";
}

void showUserMenu()
{
    cout << "\n========================================";
    cout << "\n           USER DASHBOARD";
    cout << "\n========================================";

    cout << "\n1. Deposit Money";
    cout << "\n2. Withdraw Money";
    cout << "\n3. Check Balance";
    cout << "\n4. Account Details";
    cout << "\n5. Transaction History";
    cout << "\n6. Logout";

    cout << "\n========================================";
}
void showAdminMenu()
{
    cout << "\n========================================";
    cout << "\n             ADMIN PANEL";
    cout << "\n========================================";

    cout << "\n1. View All Accounts";
    cout << "\n2. Delete Account";
    cout << "\n3. Exit Admin Panel";

    cout << "\n========================================";
}

int main()
{
    Account userAccount;

    int mainChoice;

    while(true)
    {
        showMainMenu();

        cout << "\nEnter Choice: ";
        cin >> mainChoice;

        switch(mainChoice)
        {
            case 1:
            {
                userAccount.createAccount();
                break;
            }

            case 2:
            {
                bool loginSuccess =
                    userAccount.loginAccount();

                if(loginSuccess)
                {
                    int userChoice;

                    while(true)
                    {
                        showUserMenu();

                        cout << "\nEnter Choice: ";
                        cin >> userChoice;

                        switch(userChoice)
                        {
                            case 1:
                            {
                                userAccount.depositMoney();
                                break;
                            }

                            case 2:
                            {
                                userAccount.withdrawMoney();
                                break;
                            }

                            case 3:
                            {
                                userAccount.checkBalance();
                                break;
                            }

                            case 4:
                            {
                                userAccount.displayAccountDetails();
                                break;
                            }
                            case 5:
                            {
                                userAccount.showTransactionHistory();
                                break;
                            }

                            case 6:
                            {
                                cout << "\n Logging Out...";
                                break;
                            }

                            default:
                            {
                                cout << "\n Invalid Choice!";
                            }
                        }

                        if(userChoice == 6)
                        {
                            break;
                        }
                    }
                }

                break;
            }
            case 3:
            {
                string adminUsername;
                string adminPassword;

                cout << "\nEnter Admin Username: ";
                cin >> adminUsername;

                cout << "Enter Admin Password: ";
                cin >> adminPassword;

                if(adminUsername == "admin" &&
                   adminPassword == "admin123")
                {
                    cout << "\n Admin Login Successful!";

                    int adminChoice;

                    while(true)
                    {
                        showAdminMenu();

                        cout << "\nEnter Choice: ";
                        cin >> adminChoice;

                        switch(adminChoice)
                        {
                            case 1:
                            {
                                userAccount.viewAllAccounts();
                                break;
                            }

                            case 2:
                            {
                                userAccount.deleteAccount();
                                break;
                            }

                            case 3:
                            {
                                cout << "\n Exiting Admin Panel...";
                                break;
                            }

                            default:
                            {
                                cout << "\n Invalid Choice!";
                            }
                        }

                        if(adminChoice == 3)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    cout << "\n Invalid Admin Credentials!";
                }

                break;
            }

            case 4:
            {
                cout << "\n Thank You For Using Our Bank!";
                exit(0);
            }

            default:
            {
                cout << "\n Invalid Choice!";
            }
        }
    }

    return 0;
}