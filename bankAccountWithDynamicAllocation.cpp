/*
The program ask the user to create a bank account,
then dynamically allocate memory to the bank account  array.
program ask for the account number, name
and the amount,It allows the user to create a maximum of 5 account,
search the class array to ensure
multiple account with same number is not created
then display the content on the console
*/

#include <iostream>
#include"Account.h" // Account header file
#include<string>
#include<iomanip> // number format
#include <cstdlib>

using namespace std;

// functions prototype
void userChoiceMenu ();
void displayAccountInfo (Account*[]);
double withdrawAccount (int, double, Account*[]);
double depositAccount (int, double, Account*[]);
bool accountExist (int, Account*[]);
bool accountCreated (int, Account*[]);
void accountMainMenu (Account *[]);



const int NUM_ACCOUNT = 5;
Account *accountPtr[NUM_ACCOUNT];  // global account pointer array

int main () //program starts here
{
	// call the user account menu
	accountMainMenu (accountPtr);

	return 0;
}// end main() function

 // display  account information
void displayAccountInfo (Account *accountPtr[])
{
	cout << endl;
	cout << "Account information" << endl;
	for (int index = 0; index < accountPtr[index]->getNumberAccounts(); index++)
	{
		cout << "Number : " << setw (10) << accountPtr[index]->getAccountNumber () << ", Name : "
			<< setw (13) << accountPtr[index]->getName () << ", Balance : "
			<< setw (10) << fixed << showpoint << setprecision (2) << accountPtr[index]->getBalance () << endl;
	}
}

// process withdraw transactions
double withdrawAccount (int userAccount, double amountW, Account *accountPtr[])
{
	bool found = false;
	double newBalance = 0.0;
	bool returnWithdraw = false;
	for (int count = 0; count < accountPtr[count]->getNumberAccounts(); count++)
	{
		if (accountPtr[count]->getAccountNumber () == userAccount)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = accountPtr[count]->getBalance ();
			returnWithdraw = accountPtr[count]->withdraw (amountW);
			if (returnWithdraw == true)
			{
				newBalance -= amountW;
				cout << fixed << showpoint << setprecision(2)
				     << "New balance is  " << newBalance << endl << endl;
			}
			break;
		}
	}
	return newBalance;
}

// process  deposit transactions
double depositAccount (int userAccount, double amountW, Account *accountPtr[])
{
	bool found = false;
	double newBalance = 0.0;
	bool returnDeposit = false;
	for (int count = 0; count < accountPtr[count]->getNumberAccounts(); count++)
	{
		if (accountPtr[count]->getAccountNumber () == userAccount)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = accountPtr[count]->getBalance ();
			returnDeposit = accountPtr[count]->deposit (amountW);
			if (returnDeposit == true)
			{
				newBalance += amountW;
				cout << fixed << showpoint << setprecision(2)
				     << "New balance is " << newBalance << endl;
			}
			break;
		}
	}
	return newBalance;


}


void userChoiceMenu () // user choice menu
{
	cout << endl;
	cout << "1 -  Create account " << endl;
	cout << "2 -  Deposit to account" << endl;
	cout << "3 -  Withdraw from account" << endl;
	cout << "4 -  Display information for all accounts" << endl;
	cout << "5 -  Get total net deposits" << endl;
	cout << "6 -  Exit" << endl << endl;
}

// check if account exist, allow deposit or withdraw
bool accountExist (int userAccount, Account *accountPtr[])
{
	bool found = false;
	for (int i = 0; i < accountPtr[i]->getNumberAccounts(); i++)
	{
		if (accountPtr[i]->getAccountNumber () == userAccount)
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

// check if account exist
bool accountCreated (int userAccount, Account *accountPtr[])
{
	bool found = false;
	for (int i = 0; i < accountPtr[i]->getNumberAccounts(); i++)
	{
		// check if new account number alreaady exist
		if (accountPtr[i]->getAccountNumber () == userAccount)
		{
			found = true;
			break;
		}
	}
	return found;
}

// user account choice  menu
void accountMainMenu (Account *accountPtr[])
{
	int userAccount, choice;
	string accountName = "";
	double  accountBalance;
	int accountIndex = 0;
	bool foundAccount;


	do
	{
		userChoiceMenu (); // call user choice menu function
		cin >> choice;

		switch (choice) // choice menu is determine here
		{
		case 1: cout << "Enter account number:";
			cin >> userAccount;
			foundAccount = accountCreated (userAccount, accountPtr);
			if (foundAccount == false) // return false if account number is found
			{
				cout << "Enter owner's name :";
				cin.ignore ();
				getline (cin, accountName);
				cout << "Enter balance :";
				cin >> accountBalance;
				if (accountIndex <=accountPtr[accountIndex]->getNumberAccounts())
				{
					// call constructor Account() with arguments
					accountPtr[accountIndex] = new Account (userAccount, accountName, accountBalance);
					accountIndex++;
				}
				else
					cout << "Max number of accounts reached, cannot add a new account" << endl;

			}
			else
				cout << "This account number already exists." << endl;
			break;

		case 2:cout << "Enter account number :";
			cin >> userAccount;
			foundAccount = accountExist (userAccount, accountPtr);
			if (foundAccount == true)
			{
				cout << "Enter amount :";
				cin >> accountBalance;
				depositAccount (userAccount, accountBalance, accountPtr);
			}
			break;

		case 3: cout << "Enter account number :";
			cin >> userAccount;
			foundAccount = accountExist (userAccount, accountPtr);
			if (foundAccount == true)
			{
				cout << "Enter amount :";
				cin >> accountBalance;
				withdrawAccount (userAccount, accountBalance, accountPtr);
			}
			break;
		case 4: displayAccountInfo (accountPtr);
			break;
		case 5: cout << fixed << showpoint << setprecision(2)
			         << "Total net deposits is :"
			         << accountPtr[accountIndex]->getTotalNetDeposits () << endl;
         break;
		case 6: exit (0); // quit program
		   break;

		default : cout << " Invalid choice , valid choice is 1 to 6" << endl;

		}

	} while (choice != 6);

	delete []accountPtr; // delete pointer
}



#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
	int accountNumber;
	double balance;
	string ownerName;
	static double totalNetDeposits; // records deposit transaction
	static int numberAccounts; // records number of created account

public:

	// constructor declaration
	Account (int accNum, string userName, double bal);
	~Account();
	// public member functions declaration
	bool withdraw (double amount1);
	bool deposit (double amount_);

	int getAccountNumber () const;

	string getName () const;

	double getBalance () const;
	static double getTotalNetDeposits ();
	static int getNumberAccounts ();

};

#endif // ACCOUNT_H_INCLUDED



#include"Account.h"
#include<iostream>
#include <iomanip>
#include <string>

// static variable definition
double Account::totalNetDeposits = 0.0;
int Account::numberAccounts = 0;

// constructor
Account::Account (int accNum, string userName, double bal)
{
	accountNumber = accNum;
	ownerName = userName;
	balance = bal;
	totalNetDeposits += bal;
	numberAccounts++;
}

Account :: ~Account () {} // Account destructor

// withdraw function definition
bool Account::withdraw (double amount1)
{
	if (amount1 > balance)
	{
		cout << "Insufficient balance, withdraw not executed" << endl;
		return false;
	}

	else
	{
		balance -= amount1;
		totalNetDeposits -= amount1;
		return true;
	}
}

// deposit function definition
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
		totalNetDeposits += amount_;
		return true;
	}
}

double Account::getTotalNetDeposits ()
{
	return totalNetDeposits;
}

int Account::getAccountNumber () const
{
	return accountNumber;
}

string Account::getName () const
{
	return ownerName;
}

double Account::getBalance () const
{
	return balance;
}

int Account::getNumberAccounts ()
{
	return numberAccounts;
}



