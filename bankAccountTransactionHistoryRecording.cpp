// This program creates a bank account
// Record transaction history

#include <iostream>
#include"Account.h" // Account header file
#include<string>
#include<iomanip>
#include <cstdlib>

using namespace std;

// functions prototype
void userChoiceMenu ();
void displayAccountInfo (Account *[]);
double withdrawAccount (int, double, Account *[], int, int, int);
double depositAccount (int, double, Account *[], int, int, int);
bool accountExist (int, Account *[]);
bool accountCreated (int, Account *[]);
void accountMainMenu (Account *[]);



const int NUM_ACCOUNT = 5;
Account *accountPtr[NUM_ACCOUNT];  // global account pointer array

int main () //program starts here
{
	accountMainMenu (accountPtr); // call the user account menu


	delete[] accountPtr;  // delete pointer

	return 0;
}// end main() function

void displayAccountInfo (Account *accountPtr[])
{
	cout << endl;
	cout << "Account information" << endl;
	for (int index = 0; index < accountPtr[index]->getnumberAccount(); index++)
	{
		cout << "Number : " << setw (10) << accountPtr[index]->getAccountNumber () << ", Name : "
			<< setw (13) << accountPtr[index]->getName () << ", Balance : "
			<< setw (10) << showpoint << setprecision (2) << accountPtr[index]->getBalance () << endl;
		accountPtr[index]->printTransactions ();
		cout << endl;
	}
}

double withdrawAccount (int userAccount, double amountW, Account *accountPtr[], int monthM, int dayM, int yearM)
{
	bool found = false;
	double newBalance = 0.0;
	bool returnWithdraw = false;
	for (int count = 0; count < accountPtr[count]->getnumberAccount(); count++)
	{
		if (accountPtr[count]->getAccountNumber () == userAccount)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = accountPtr[count]->getBalance ();
			returnWithdraw = accountPtr[count]->withdraw (amountW, monthM,dayM,yearM);
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

double depositAccount (int userAccount, double amountW, Account *accountPtr[], int monthD, int dayD, int yearD)
{
	bool found = false;
	double newBalance = 0.0;
	bool returnDeposit = false;
	for (int count = 0; count < accountPtr[count]->getnumberAccount(); count++)
	{
		if (accountPtr[count]->getAccountNumber () == userAccount)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = accountPtr[count]->getBalance ();
			returnDeposit = accountPtr[count]->deposit (amountW, monthD,dayD,yearD);
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


void userChoiceMenu () // user choice menu
{
	cout << endl;
	cout << "1 -  Create account" << endl;
	cout << "2 -  Deposit to account" << endl;
	cout << "3 -  Withdraw from account" << endl;
	cout << "4 -  Display transaction history for an account" << endl;
	cout << "5 -  Display information for all accounts" << endl;
	cout << "6 -  Get total net deposits" << endl;
	cout << "7 -  Exit" << endl;
}

// check if account exist, allow deposit or withdraw
bool accountExist (int userAccount, Account *accountPtr[])
{
	bool found = false;
	for (int i = 0; i < accountPtr[i]->getnumberAccount(); i++)
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

bool accountCreated (int userAccount, Account *accountPtr[]) // check if account exist
{
	bool found = false;
	for (int i = 0; i < accountPtr[i]->getnumberAccount(); i++)
	{
		if (accountPtr[i]->getAccountNumber () == userAccount)
		{
			found = true;
			break;
		}
	}
	return found;
}

void accountMainMenu (Account *accountPtr[]) // user account menu
{
	int userAccount, choice, month1, day1, year1;
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
				cout << "Enter current month, day and year :";
				cin >> month1 >> day1 >> year1;
				cout << "Enter balance :";
				cin >> accountBalance;
				if (accountIndex < NUM_ACCOUNT)
				{

					accountPtr[accountIndex] =  new Account (userAccount, accountName, accountBalance,month1,day1,year1);
					accountIndex++;
				}
				else
					cout << "Max number of accounts reached, cannot add a new account" << endl;

			}
			else
				cout << "This account number already exists." << endl;
			break;

		case 2: cout << "Enter account number :";
			    cin >> userAccount;
			    foundAccount = accountExist (userAccount, accountPtr);
			    if (foundAccount == true)
			        {
				cout << "Enter current month, day and year :";
				cin >> month1 >> day1 >> year1;
				cout << "Enter amount :";
				cin >> accountBalance;
				depositAccount (userAccount, accountBalance, accountPtr, month1, day1, year1);
			        }
			    break;

		case 3: cout << "Enter account number :";
			    cin >> userAccount;
			    foundAccount = accountExist (userAccount, accountPtr);
			    if (foundAccount == true)
			          {
				cout << "Enter current month, day and year :";
				cin >> month1 >> day1 >> year1;
				cout << "Enter amount :";
				cin >> accountBalance;
				withdrawAccount (userAccount, accountBalance, accountPtr, month1, day1, year1);
			          }
			    break;
		case 4:
			cout << "Enter account number :";
			cin >> userAccount;
			foundAccount = accountExist (userAccount, accountPtr);
			if (foundAccount == true)
			{
				for (int i = 0; i < accountIndex; i++)
				{
					if(accountPtr[i]->getAccountNumber() == userAccount)
						accountPtr[i]->printTransactions ();
				}
			}
			else
			{
				cout << "Account not found\n";
			}
			break;
		case 5:  displayAccountInfo (accountPtr);
			break;
		case 6:  cout << "Total net deposit is :"
                    << accountPtr[accountIndex]->getTotalNetDeposit()
                    << endl;
			break;

		}

	} while (choice != 7);
}


#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include<iostream>

using namespace std;



class Account
{
private:
	struct Transaction
	{
		int transactionMonth;
		int transactionDay;
		int transacionYear;
		double transactionAmount;
		double transactionBalance;
		enum operation {CREATION, DEPOSIT, WITHDRAWAL};
		operation transactionType;
	};

	int accountNumber;
	double balance;
	string ownerName;
	Transaction **transactionHistory = new Transaction*[0];
	int numberTransaction = 0;
	static double totalNetDeposit;
	static int numberAccount;
	string operationToString (int);

	void recordTransaction (Transaction *transact);

public:

	Account (int number, string name, double amount, int month1, int day1, int year1);

	~Account ()
	{
		delete transactionHistory;
	}

	bool withdraw (double amount1, int month2, int day2, int year2);

	bool deposit (double amount, int month3, int day3, int year3);

	int getAccountNumber () const;

	double getTotalNetDeposit ();

	string getName () const;

	double getBalance () const;

	void printTransactions ();
	int getnumberAccount ();

};

#endif /* ACCOUNT_H_ */



#include"Account.h"
#include<iostream>
#include <string>
using namespace std;

double Account::totalNetDeposit = 0.0;
int Account::numberAccount = 0;


Account :: Account (int number, string name, double amount, int month1, int day1, int year1)
{
	accountNumber = number;
	ownerName = name;
	Transaction *current = new Transaction();
	current->transactionMonth = month1;
	current->transactionDay = day1;
	current->transacionYear = year1;
	current->transactionType = current->CREATION;
	current->transactionAmount = amount;

	balance = amount;
	current->transactionBalance = balance;
	recordTransaction (current);
	totalNetDeposit += amount;
	numberTransaction = 1;
	numberAccount++;
}

int Account::getAccountNumber () const
{
	return accountNumber;
}

string Account ::getName () const
{
	return ownerName;
}

double Account :: getBalance () const
{
	return balance;
}

double Account::getTotalNetDeposit ()
{
	return totalNetDeposit;
}

int  Account::getnumberAccount ()
{
	return numberAccount;
}

bool Account::withdraw (double amount2, int month2, int day2, int year2 )
{
	if (amount2 > balance)
	{
		cout << "Insufficient balance, withdraw not executed" << endl;
		return false;
	}

	else
	{
		Transaction* current = new Transaction ();
		current->transactionMonth = month2;
		current->transactionDay = day2;
		current->transacionYear = year2;
		current->transactionType = current->WITHDRAWAL;
		current->transactionAmount = amount2;

		balance -= amount2;
		current->transactionBalance = balance;
		recordTransaction (current);
		totalNetDeposit -= amount2;
		return true;
	}
}


bool Account::deposit (double amount3, int month3, int day3, int year3)
{
	if (amount3 < 0)
	{
		cout << "Deposit amount cannot be negative, deposit not executed" << endl;
		return false;
	}
	else
	{
		Transaction *current = new Transaction ();
		current->transactionMonth = month3;
		current->transactionDay = day3;
		current->transacionYear = year3;
		current->transactionType = current->DEPOSIT;
		current->transactionAmount = amount3;

		balance += amount3;
		current->transactionBalance = balance;
		totalNetDeposit += amount3;
		recordTransaction (current);
		return true;
	}
}

string Account::operationToString (int convertToString)
{
	switch (convertToString) {
	case 0:
		return "Creation";
	case 1:
		return "Deposit";
	case 2:
		return "Withdraw";
	}
	return "ERROR";
}

// Record transaction history
void Account::recordTransaction (Transaction *transact)
{
	numberTransaction++;
	Transaction ** temp = new Transaction*[numberTransaction];
	for (int i = 0; i < numberTransaction - 1; i++)
	{
		temp[i] = transactionHistory[i];
	}
	temp[numberTransaction - 1] = transact;
	transactionHistory = temp;
}

void Account ::printTransactions ()
{
	for (int i = 0; i < numberTransaction; i++)
	{
		cout << "Transaction history :"
			<< "......................." << endl;
		cout << "Date :" << transactionHistory[i]->transactionMonth
           << "/" << transactionHistory[i]->transactionDay << "/"
           << transactionHistory[i]->transacionYear << endl;
		cout << " Amount:" << transactionHistory[i]->transactionAmount
           << "type :" << operationToString(transactionHistory[i]->transactionType)
           << "New Balance :" << transactionHistory[i]->transactionBalance << endl;

	}

}
