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
#include "Account.h"
#include "PremiumAccount.h"
#include "RegularAccount.h"
#include <string>
#include <iomanip>


using namespace std;

// function prototypes
void userChoiceMenu();
void displayAccountInfo(RegularAccount*[], PremiumAccount*[]);
double withdrawAccount(int, double, RegularAccount *[]);
double depositAccount(int, double, RegularAccount *[]);
bool accountExist(int, RegularAccount*[]);
bool accountCreated(int, RegularAccount*[]);
double withdrawPremiumAccount(int, double, PremiumAccount *[]);
double depositPremium(int, double, PremiumAccount *[]);
bool premiumAccountExist(int, PremiumAccount*[]);
bool PremiumAccountCreated(int, PremiumAccount*[]);
void accountMainMenu(RegularAccount *[], PremiumAccount*[]);


const int NUM_REGULAR_ACCOUNT = 5;
const int NUM_PREMIUM_ACCOUNT = 5;

RegularAccount *regularAccountArray[NUM_REGULAR_ACCOUNT];
PremiumAccount *premiumAccountArray[NUM_PREMIUM_ACCOUNT];

int main()
{
	accountMainMenu(regularAccountArray, premiumAccountArray);

	return 0;

}

void userChoiceMenu() // user choice menu
{
	cout << endl;
	cout << "1 -  Create regular account" << endl;
	cout << "2 -  Create premium account" << endl;
	cout << "3 -  Deposit to regular account" << endl;
	cout << "4 -  Deposit to premium account" << endl;
	cout << "5 -  Withdraw from regular account" << endl;
	cout << "6 -  Withdraw from premium account" << endl;
	cout << "7 -  Display information for all accounts" << endl;
	cout << "8 -  Get total net deposits" << endl;
	cout << "9 - Exit" << endl;
}

void accountMainMenu(RegularAccount *regularAccountArray[], PremiumAccount *premiumAccountArray[])
{
	int userAccount, choice;
	string accountName = "";
	double  depositAmount;
	int accountIndex = 0;
	int premAccountIndex = 0;
	bool foundAccount;


	do
	{
		userChoiceMenu(); // user choice menu
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Enter account number:";
			cin >> userAccount;
			foundAccount = accountCreated(userAccount, regularAccountArray);
			if (foundAccount == false)
			{
				cout << "Enter owner's name :";
				cin.ignore();
				getline(cin, accountName);
				cout << "Enter amount :";
				cin >> depositAmount;
				if (accountIndex < NUM_REGULAR_ACCOUNT)
				{

					regularAccountArray[accountIndex] = new RegularAccount(userAccount, accountName, depositAmount);
					accountIndex++;
				}
				else
					cout << "Max number of accounts reached, cannot add a new account" << endl;
			}
			else
				cout << "This account number already exists." << endl;
			break;
		case 2: cout << "Enter account number:";
			cin >> userAccount;
			foundAccount = PremiumAccountCreated(userAccount, premiumAccountArray);
			if (foundAccount == false)
			{
				cout << "Enter owner's name :";
				cin.ignore();
				getline(cin, accountName);
				cout << "Enter amount :";
				cin >> depositAmount;
				if (depositAmount < premiumAccountArray[premAccountIndex]->getMinBalance())
				{
					cout << "Insufficient amount ,you needed  at least $" << premiumAccountArray[premAccountIndex]->getMinBalance()
						<< " to open a premium account" << endl;
				}
				else
				if (premAccountIndex < NUM_PREMIUM_ACCOUNT)
				{
					premiumAccountArray[premAccountIndex] = new PremiumAccount(userAccount, accountName, depositAmount);
					premAccountIndex++;
				}
				else
					cout << "Max number of accounts reached, cannot add a new account" << endl;
			}
			else
				cout << "This account number already exists." << endl;
			break;


		case 3: cout << "Enter account number :";
			cin >> userAccount;
			foundAccount = accountExist(userAccount, regularAccountArray);
			if (foundAccount == true)
			{
				cout << "Enter amount :";
				cin >> depositAmount;
				depositAccount(userAccount, depositAmount, regularAccountArray);
			}
			break;
		case 4: cout << "Enter account number :";
			cin >> userAccount;
			foundAccount = premiumAccountExist(userAccount, premiumAccountArray);
			if (foundAccount == true)
			{
				cout << "Enter amount :";
				cin >> depositAmount;
				depositPremium(userAccount, depositAmount, premiumAccountArray);
			}
			break;

		case 5: cout << "Enter account number :";
			cin >> userAccount;
			foundAccount = accountExist(userAccount, regularAccountArray);
			if (foundAccount == true)
			{
				cout << "Enter amount :";
				cin >> depositAmount;
				withdrawAccount(userAccount, depositAmount, regularAccountArray);
			}
			break;
		case 6: cout << "Enter account number :";
			cin >> userAccount;
			foundAccount = premiumAccountExist(userAccount, premiumAccountArray);
			if (foundAccount == true)
			{
				cout << "Enter amount :";
				cin >> depositAmount;
				withdrawPremiumAccount(userAccount, depositAmount, premiumAccountArray);
			}
			break;
		case 7:  displayAccountInfo(regularAccountArray, premiumAccountArray);
			break;
		case 8:
				cout << "Total net deposit is :"
					 << fixed << showpoint << setprecision(2) << "  $" << regularAccountArray[accountIndex]->getTotalNetDeposit()
					 << endl;
			break;
		}

	} while (choice != 9);

	delete[] regularAccountArray;
	delete[] premiumAccountArray;

}



bool accountCreated(int userAccount, RegularAccount *regularAccountArray[]) // check if account exist
{
	bool found = false;
	for (int i = 0; i <regularAccountArray[i]->getNumberRegularAccount(); i++)
	{

		int x = regularAccountArray[i]->getAccountNumber();
		if (userAccount == x)
		{
			found = true;
			break;
		}
	}
	return found;
}

// check if account exist, allow deposit or withdraw
bool accountExist(int userAccount, RegularAccount *regularAccountArray[])
{
	bool found = false;
	for (int i = 0; i < regularAccountArray[i]->getNumberRegularAccount(); i++)
	{
		int x = regularAccountArray[i]->getAccountNumber();
		if (userAccount==x)
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

double depositAccount(int userAccount, double amountW, RegularAccount *regularAccountArray[])
{
	bool found = false;
	double newBalance = 0.0;
	bool returnDeposit = false;
	for (int count = 0; count < regularAccountArray[count]->getnumberAccount(); count++)
	{
		int x = regularAccountArray[count]->getAccountNumber();
		if (userAccount == x)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = regularAccountArray[count]->getBalance();
			returnDeposit = regularAccountArray[count]->deposit(amountW);
			if (returnDeposit == true)
			{
				newBalance += amountW;
				cout << fixed << showpoint << setprecision(2) << "New balance is  $" << newBalance << endl;
			}
			break;
		}
	}
	return newBalance;


}


double withdrawAccount(int userAccount, double amountW, RegularAccount *regularAccountArray[])
{
	bool found = false;
	double newBalance = 0.0;
	bool returnWithdraw = false;
	for (int count = 0; count < regularAccountArray[count]->getnumberAccount(); count++)
	{
		int x = regularAccountArray[count]->getAccountNumber();
		if (userAccount == x)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = regularAccountArray[count]->getBalance();
			returnWithdraw = regularAccountArray[count]->withdraw(amountW);
			if (returnWithdraw == true)
			{
				newBalance -= amountW;
				cout << fixed << showpoint << setprecision(2) << "New balance is  $" << newBalance << endl << endl;
			}
			break;
		}
	}
	return newBalance;
}

double withdrawPremiumAccount(int userAccount, double amountW, PremiumAccount *premiumAccountArray[])
{
	bool found = false;
	double newBalance = 0.0;
	bool returnWithdraw = false;
	for (int count = 0; count < premiumAccountArray[count]->getnumberAccount(); count++)
	{
		int y = premiumAccountArray[count]->getAccountNumber();
		if (userAccount == y)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = premiumAccountArray[count]->getBalance();
			returnWithdraw = premiumAccountArray[count]->withdrawPremium(amountW);
			if (returnWithdraw == true)
			{
				newBalance -= amountW;
				cout << fixed << showpoint << setprecision(2) << "New balance is  $" << newBalance << endl;
			}
			break;
		}
	}
	return newBalance;
}

double depositPremium(int userAccount, double amountW, PremiumAccount *premiumAccountArray[])
{
	bool found = false;
	double newBalance = 0.0;
	bool returnDeposit = false;
	for (int count = 0; count < premiumAccountArray[count]->getnumberAccount(); count++)
	{
		int y = premiumAccountArray[count]->getAccountNumber();
		if (userAccount == y)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = premiumAccountArray[count]->getBalance();
			returnDeposit = premiumAccountArray[count]->deposit(amountW);
			if (returnDeposit == true)
			{
				newBalance += amountW;
				cout << fixed << showpoint << setprecision(2) << "New balance is  $" << newBalance << endl;
			}
			break;
		}
	}
	return newBalance;
}

bool premiumAccountExist(int userAccount, PremiumAccount*premiumAccountArray[])
{
	bool found = false;
	for (int i = 0; i < premiumAccountArray[i]->getNumberPremiumAccount(); i++)
	{
		int y = premiumAccountArray[i]->getAccountNumber();
		if (userAccount == y)
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

bool PremiumAccountCreated(int userAccount, PremiumAccount*premiumAccountArray[])
{
	bool found = false;
	for (int i = 0; i < premiumAccountArray[i]->getNumberPremiumAccount(); i++)
	{
		//cout << i << endl;
		int y = premiumAccountArray[i]->getAccountNumber();
		if (userAccount == y)
		{
			found = true;
			break;
		}
	}
	return found;
}


void displayAccountInfo(RegularAccount *regularAccountArray[], PremiumAccount *premiumAccountArray[])
{
	cout << endl;
	cout << "Regular accounts" << endl;
	cout << "=================" << endl << endl;
	for (int index = 0; index < regularAccountArray[index]->getNumberRegularAccount(); index++)
	{
		regularAccountArray[index]->print();
	}

	cout << endl;
	cout << "Premium accounts" << endl;
	cout << "=================" << endl << endl;
	for (int index = 0; index < premiumAccountArray[index]->getNumberPremiumAccount(); index++)
	{
		premiumAccountArray[index]->print();
	}

}


#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include<iostream>

using namespace std;



class Account
{
private:
	int accountNumber;
	string ownerName;
	static int numberAccount;
protected:

	double balance;
	static double totalNetDeposit;

public:

	Account(int, string, double );

	bool withdraw(double);

	bool deposit(double);

	int getAccountNumber() const;

	double getTotalNetDeposit();

	string getName() const;

	double getBalance() const;

	int getnumberAccount();

	void print();

};

#endif /* ACCOUNT_H_ */



#include"Account.h"
#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

double Account::totalNetDeposit = 0.0;
int Account::numberAccount = 0;


Account::Account(int number, string name, double amount)
{
	accountNumber = number;
	ownerName = name;
	balance = amount;
	totalNetDeposit += amount;
	numberAccount++;
}

int Account::getAccountNumber() const
{
	return accountNumber;
}

string Account::getName() const
{
	return ownerName;
}

double Account::getBalance() const
{
	return balance;
}

double Account::getTotalNetDeposit()
{
	return totalNetDeposit;
}

int  Account::getnumberAccount()
{
	return numberAccount;
}

bool Account::withdraw(double amount2)
{
	if (amount2 > balance)
	{
		cout << "Insufficient balance, withdraw not executed" << endl;
		return false;
	}

	else
	{
		balance -= amount2;
		totalNetDeposit -= amount2;
		return true;
	}
}


bool Account::deposit(double amount3)
{
	if (amount3 < 0)
	{
		cout << "Deposit amount cannot be negative, deposit not executed" << endl;
		return false;
	}
	else
	{
		balance += amount3;
		totalNetDeposit += amount3;
		return true;
	}
}



void Account::print() // prints transactions
{
	cout << "Number:"  << setw(9) << getAccountNumber() << ", Name:" << setw(14)
		<< getName() << fixed << showpoint << setprecision(2) << ", Balance:  " << getBalance() << endl;
}


#ifndef REGULARACCOUNT_H_INCLUDED
#define REGULARACCOUNT_H_INCLUDED
#include<iostream>
#include "Account.h"

using namespace std;

class RegularAccount : public Account
{
private:
	static int numberRegularAccount;
public:
	RegularAccount(int number, string name, double amount) : Account(number, name, amount)
	{
		numberRegularAccount++;
	}

	static int getNumberRegularAccount()
	{
		return numberRegularAccount;
	}
};
int RegularAccount::numberRegularAccount = 0;
#endif // REGULARACCOUNT_H_INCLUDED


#ifndef PREMIUMACCOUNT_H_INCLUDED
#define PREMIUMACCOUNT_H_INCLUDED
#include<iostream>
#include "Account.h"

using namespace std;

class PremiumAccount : public Account
{
private:
	static int numberPremiumAccount;
	static double MIN_BALANCE;

public:
	PremiumAccount(int number1, string name1, double amount1) : Account(number1, name1, amount1)
	{
		numberPremiumAccount++;
	}

	int getNumberPremiumAccount()
	{
		return numberPremiumAccount;
	}
	bool withdrawPremium(double amount2)
	{
		if ((amount2 + MIN_BALANCE) <= balance)
		{
			balance -= amount2;
			totalNetDeposit -= amount2;
			return true;

		}
		else
		{
			cout << "You need to maintain a min balance of $" << MIN_BALANCE << ", withdrawal not executed" << endl;
			return false;

		}
	}

	static double getMinBalance()
	{
		return MIN_BALANCE;
	}

};

int PremiumAccount::numberPremiumAccount = 0;
double PremiumAccount::MIN_BALANCE = 1000.00;
#endif // PREMIUMACCOUNT_H_INCLUDED




