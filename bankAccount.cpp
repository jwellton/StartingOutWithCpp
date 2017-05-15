/*
The program ask the user to create a bank account,
then dynamically allocate memory for the bank account  array.
program ask for the account number, name on the account
and the amount,It allows the user to create a maximum of 5 accounts,
search the class array to ensure
multiple account with same number is not created
then display the content on the console
*/

#include <iostream>
#include"Account.h" // Account header file
#include<string>
#include<iomanip>
#include <cstdlib>

using namespace std;

// functions prototype
void userChoiceMenu ();
void displayAccountInfo(Account[]);
double withdrawAccount (int, double, Account[]);
double depositAccount (int, double, Account[]);
bool accountExist (int, Account[]);
bool accountCreated (int, Account[]);
void accountMainMenu (Account[]);



const int NUM_ACCOUNT = 5;
Account *accountPtr = new Account[NUM_ACCOUNT];  // global account pointer array

int main() //program starts here
{

	accountMainMenu (accountPtr); // call the user account menu

	delete[] accountPtr;  // delete pointer

   return 0;
}// end main() function

void displayAccountInfo( Account accountPtr[])  // display  account information
{
	cout << endl;
	cout << "Account information" << endl;
	for (int index = 0; index < NUM_ACCOUNT; index++)
	{
		cout << "Number : " << setw(10) << accountPtr[index].getAccountNumber () << ", Name : "
			<<setw(13) << accountPtr[index].getName () << ", Balance : "
			<< setw(10) << showpoint<< setprecision(2)<<accountPtr[index].getBalance() << endl;
	}
}

double withdrawAccount (int userAccount, double amountW, Account accountPtr[]) // keep account withdraw activities
{
	bool found = false;
	double newBalance = 0.0;
	bool returnWithdraw = false;
	for (int count = 0; count < NUM_ACCOUNT; count++)
	{
		if (accountPtr[count].getAccountNumber () == userAccount)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = accountPtr[count].getBalance ();
			returnWithdraw = accountPtr[count].withdraw (amountW);
			if (returnWithdraw == true)
			{
				newBalance -= amountW;
				cout << "New balance is  " << newBalance << endl << endl;
			}
			break;
		}
	}
	return newBalance;
}

double depositAccount (int userAccount, double amountW, Account accountPtr[]) // keep deposit activities
{
	bool found = false;
	double newBalance = 0.0;
	bool returnDeposit = false;
	for (int count = 0; count < NUM_ACCOUNT; count++)
	{
		if (accountPtr[count].getAccountNumber () == userAccount)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = accountPtr[count].getBalance ();
			returnDeposit = accountPtr[count].deposit(amountW);
			if (returnDeposit == true)
			{
				newBalance += amountW;
				cout << "New balance is " << newBalance << endl;
			}
			break;
		}
	}
	return newBalance;


}


void userChoiceMenu() // user choice menu
{
   cout << endl;
   cout << "1 -  Create account with complete information" << endl;
   cout << "2 -  Create default account" << endl;
   cout << "3 -  Deposit to account" << endl;
   cout << "4 -  Withdraw from account" << endl;
   cout << "5 -  Display information for all accounts" << endl;
   cout << "6 -  Exit" << endl << endl;
}

bool accountExist (int userAccount, Account accountPtr[]) // check if account exist, allow deposit or withdraw
{
	bool found = false;
	for (int i = 0; i < NUM_ACCOUNT; i++)
	{
		if (accountPtr[i].getAccountNumber () == userAccount)
		{
			found = true;
			break;
		}
	}
	if (found != true)
	{
		cout << "No such account" << endl;

	}

	return found;
}

bool accountCreated (int userAccount, Account accountPtr[]) // check if account exist
{
	bool found = false;
	for (int i = 0; i < NUM_ACCOUNT; i++)
	{
		if (accountPtr[i].getAccountNumber () == userAccount)
		{
			found = true;
			break;
		}
	}
	return found;
}

void accountMainMenu (Account[]) // user account menu
{
	int userAccount, choice;
	string accountName = "";
	double  accountBalance;
	int accountIndex = 0;
	bool foundAccount;


	do
	{
		userChoiceMenu (); // call user choice menu
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Enter account number:";
			     cin >> userAccount;
			     foundAccount = accountCreated (userAccount, accountPtr);
			     if (foundAccount == false)
			       {
				  cout << "Enter owner's name :";
				  cin.ignore ();
				  getline (cin, accountName);
				  cout << "Enter balance :";
				  cin >> accountBalance;
				  if (accountIndex < NUM_ACCOUNT)
				      {
				         // call constructor Account() with arguments
					      *(accountPtr + accountIndex) = Account (userAccount, accountName, accountBalance);
                     accountIndex++;
				      }
				  else
					cout << "Max number of accounts reached, cannot add a new account" << endl;

			        }
              else
				  cout << "This account number already exists." << endl;
              break;

		case 2: if (accountIndex < NUM_ACCOUNT)
		           {
		              // call constructor Account() with  no arguments
			          *(accountPtr + accountIndex) = Account ();
                    accountIndex++;
                 }
				   else
               cout << "Max number of accounts reached, cannot add a new account" << endl;
			      break;

		case 3:  cout << "Enter account number :";
			      cin >> userAccount;
			      foundAccount = accountExist (userAccount, accountPtr);
			      if (foundAccount == true)
			          {
				          cout << "Enter amount :";
                      cin >> accountBalance;
                      depositAccount (userAccount, accountBalance, accountPtr);
			            }
			      break;
		case 4:  cout << "Enter account number :";
			      cin >> userAccount;
			      foundAccount = accountExist (userAccount, accountPtr);
			      if (foundAccount == true)
			         {
				   cout << "Enter amount :";
				   cin >> accountBalance;
               withdrawAccount (userAccount, accountBalance, accountPtr);
			         }
			      break;
		case 5:  displayAccountInfo (accountPtr);
			      break;

		}

	} while (choice != 6);
}




#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include<iostream>

using namespace std;

class Account
{
private:
	int accountNumber;
	double balance;
	string ownerName;

public:
	Account()
	{
		accountNumber = 9999;
	    ownerName = "";
		balance = 0.00;
	}

	Account(int accNum, string userName, double bal)
	{
		accountNumber = accNum;
		ownerName = userName;
		balance = bal;
	}

	bool withdraw (double amount1);
	bool deposit (double amount_);

	int getAccountNumber() const
	{
		return accountNumber;
	}

	string getName() const
	{
		return ownerName;
	}

	double getBalance() const
	{
		return balance;
	}

};

#endif /* ACCOUNT_H_ */



#include"Account.h"
#include<iostream>
#include <iomanip>
#include <string>

bool Account::withdraw(double amount1)
{
	if (amount1 > balance)
	{
		cout << "Insufficient balance, withdraw not executed" << endl;
		return false;
	}

	else
	{
		balance -= amount1;
		return true;
	}
}


bool Account::deposit (double amount_)
{
	if (amount_ < 0)
	{
		cout << "Deposit amount cannot be negative, deposit not executed" << endl;
		return false;
	}
	else
	{
		balance += amount_;
		return true;
	}
}


