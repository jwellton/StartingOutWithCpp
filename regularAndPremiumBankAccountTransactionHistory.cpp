// This program creates a regular and premium bank account
// Record all transactions in standard date format

#include <iostream>
#include "Date.h"
#include "Account.h"
#include "PremiumAccount.h"
#include "RegularAccount.h"
#include "Transaction.h"
#include <string>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

// function prototypes
void userChoiceMenu();
void displayAccountInfo(RegularAccount*[],PremiumAccount*[]);
double withdrawAccount(int, double, RegularAccount *[], Date);
double depositAccount(int, double, RegularAccount *[],Date);
bool accountExist(int, RegularAccount*[]);
bool accountCreated(int, RegularAccount*[]);
double withdrawPremiumAccount(int, double, PremiumAccount *[], Date);
double depositPremium(int, double, PremiumAccount *[], Date);
bool premiumAccountExist(int, PremiumAccount*[]);
bool PremiumAccountCreated(int, PremiumAccount*[]);
void accountMainMenu(RegularAccount *[], PremiumAccount*[]);
int getMonth(string month);
int getDay(string day);
int getYear(string year);
Date showDate(string date);

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
	cout << "9 -  Calculate bonus for a premium account" << endl;
	cout << "10 - Exit" << endl;
}

// function gets months
int getMonth(string date)
{
	// access month from index 0 then return string
	string monthStr = date.substr(0, 2);
	// convert strings to integer
	int numMonth = atoi(monthStr.c_str());
	return numMonth;
}

// function gets day
int getDay(string date)
{

	// access day from index 3 then return string length
	string dayStr = date.substr(3, 2);
	// converts string to integer
	int numDay = atoi(dayStr.c_str());

	return numDay;
}

// functions gets year
int getYear(string date)
{
	// access year from index 6 then return string length
	string yearStr = date.substr(6, 4);
	// converts string to integer
	int numYear = atoi(yearStr.c_str());

	return numYear;
}

void accountMainMenu(RegularAccount *regularAccountArray[], PremiumAccount *premiumAccountArray[])
{
	int userAccount, choice;
	string accountName = "", date = "";
	double  depositAmount;
	int accountIndex = 0;
	bool foundAccount;


	do
	{
		userChoiceMenu(); // user choice menu
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Enter account number:";
			cin >> userAccount;
			foundAccount = accountCreated(userAccount,regularAccountArray);
			if (foundAccount == false)
			{
				cout << "Enter owner's name :";
				cin.ignore();
				getline(cin, accountName);
				cout << "Enter current month, day and year,in the mm/dd/yyyy format :";
				cin >> date;
				Date dateR;
				dateR = showDate(date);
				cout << "Enter amount :";
				cin >> depositAmount;
				if (accountIndex < NUM_REGULAR_ACCOUNT)
				{

					regularAccountArray[accountIndex] = new RegularAccount(userAccount, accountName, depositAmount, dateR);
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
			foundAccount = PremiumAccountCreated(userAccount,premiumAccountArray);
			if (foundAccount == false)
			{
				cout << "Enter owner's name :";
				cin.ignore();
				getline(cin, accountName);
				cout << "Enter current month, day and year,in the mm/dd/yyyy format :";
				cin >> date;
				Date dateP;
				dateP = showDate(date);
				cout << "Enter amount :";
				cin >> depositAmount;
				if (depositAmount < premiumAccountArray[accountIndex]->getMinBalance())
					cout << "Insufficient amount ,you needed  at least $" << premiumAccountArray[accountIndex]->getMinBalance()
					     << " to open a premium account" << endl;
				if (accountIndex < NUM_PREMIUM_ACCOUNT)
				{

					premiumAccountArray[accountIndex] = new PremiumAccount(userAccount, accountName, depositAmount, dateP);
					accountIndex++;
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
				cout << "Enter current month, day and year, in the mm/dd/yyyy format :";
				cin >> date;
				Date dateW;
				dateW = showDate(date);
				cout << "Enter amount :";
				cin >> depositAmount;
				depositAccount(userAccount, depositAmount,regularAccountArray,dateW);
			}
			break;
		case 4: cout << "Enter account number :";
			cin >> userAccount;
			foundAccount = premiumAccountExist(userAccount,premiumAccountArray);
			if (foundAccount == true)
			{
				cout << "Enter current month, day and year, in the mm/dd/yyyy format :";
				cin >> date;
				Date dateW;
				dateW = showDate(date);
				cout << "Enter amount :";
				cin >> depositAmount;
				depositPremium(userAccount, depositAmount,premiumAccountArray, dateW);
			}
			break;

		case 5: cout << "Enter account number :";
			cin >> userAccount;
			foundAccount = accountExist(userAccount, regularAccountArray);
			if (foundAccount == true)
			{
				cout << "Enter current month, day and year, in the mm/dd/yyyy format  :";
				cin >> date;
				Date dateF;
				dateF = showDate(date);
				cout << "Enter amount :";
				cin >> depositAmount;
				withdrawAccount(userAccount, depositAmount,regularAccountArray,dateF);
			}
			break;
		case 6: cout << "Enter account number :";
			cin >> userAccount;
			foundAccount = premiumAccountExist(userAccount,premiumAccountArray);
			if (foundAccount == true)
			{
				cout << "Enter current month, day and year , in the mm/dd/yyyy format:";
				cin >> date;
				Date dateP;
				dateP = showDate(date);
				cout << "Enter amount :";
				cin >> depositAmount;
				withdrawPremiumAccount(userAccount, depositAmount, premiumAccountArray,dateP);
			}
			break;
		case 7:  displayAccountInfo(regularAccountArray,premiumAccountArray);
			break;
		case 8:  cout << "Total net deposit is :"
			          << (regularAccountArray[accountIndex]->getTotalNetDeposit() + premiumAccountArray[accountIndex]->getTotalNetDeposit())
			          << endl;
			break;
		case 9: cout << "Enter account number ";
			cin >> userAccount;
			foundAccount = premiumAccountExist(userAccount, premiumAccountArray);
			if (foundAccount == true)
			{
				int month, year;
				cout << "Enter month and year :";
				cin >> month >> year;
				double netDeposit = premiumAccountArray[accountIndex]->calcBonus(month, year);
				cout << "Bonus is $" << netDeposit << endl;
			}


		}

	} while (choice != 10);
}



bool accountCreated(int userAccount, RegularAccount *regularAccountArray[]) // check if account exist
{
	bool found = false;
	for (int i = 0; i < regularAccountArray[i]->getnumberAccount(); i++)
	{
		if (regularAccountArray[i]->getNumberRegularAccount() == userAccount)
		{
			found = true;
			break;
		}
	}
	return found;
}

bool accountExist(int userAccount, RegularAccount *regularAccountArray[]) // check if account exist, allow deposit or withdraw
{
	bool found = false;
	for (int i = 0; i < regularAccountArray[i]->getnumberAccount(); i++)
	{
		if (regularAccountArray[i]->getNumberRegularAccount() == userAccount)
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

double depositAccount(int userAccount, double amountW, RegularAccount *regularAccountArray[], Date dateD)
{
	bool found = false;
	double newBalance = 0.0;
	bool returnDeposit = false;
	for (int count = 0; count < regularAccountArray[count]->getnumberAccount(); count++)
	{
		if (regularAccountArray[count]->getNumberRegularAccount() == userAccount)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = regularAccountArray[count]->getBalance();
			returnDeposit = regularAccountArray[count]->deposit(amountW,dateD);
			if (returnDeposit == true)
			{
				newBalance += amountW;
				cout << showpoint << setprecision(2) << "New balance is " << newBalance << endl;
			}
			break;
		}
	}
	return newBalance;


}


double withdrawAccount(int userAccount, double amountW, RegularAccount *regularAccountArray[], Date dateZ)
{
	bool found = false;
	double newBalance = 0.0;
	bool returnWithdraw = false;
	for (int count = 0; count < regularAccountArray[count]->getnumberAccount(); count++)
	{
		if (regularAccountArray[count]->getNumberRegularAccount() == userAccount)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = regularAccountArray[count]->getBalance();
			returnWithdraw = regularAccountArray[count]->withdraw(amountW,dateZ);
			if (returnWithdraw == true)
			{
				newBalance -= amountW;
				cout << showpoint << setprecision(2)<< "New balance is  " << newBalance << endl << endl;
			}
			break;
		}
	}
	return newBalance;
}

double withdrawPremiumAccount(int userAccount, double amountW, PremiumAccount *premiumAccountArray[], Date dateZ)
{
	bool found = false;
	double newBalance = 0.0;
	bool returnWithdraw = false;
	for (int count = 0; count < premiumAccountArray[count]->getnumberAccount(); count++)
	{
		if (premiumAccountArray[count]->getNumberPremiumAccount() == userAccount)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = premiumAccountArray[count]->getBalance();
			returnWithdraw = premiumAccountArray[count]->withdrawPremium(amountW, dateZ);
			if (returnWithdraw == true)
			{
				newBalance -= amountW;
				cout << showpoint << setprecision(2) << "New balance is  " << newBalance << endl;
			}
			break;
		}
	}
	return newBalance;
}

double depositPremium(int userAccount, double amountW, PremiumAccount *premiumAccountArray[], Date dateD)
{
	bool found = false;
	double newBalance = 0.0;
	bool returnDeposit = false;
	for (int count = 0; count < premiumAccountArray[count]->getnumberAccount(); count++)
	{
		if (premiumAccountArray[count]->getNumberPremiumAccount() == userAccount)
		{
			found = true;
		}
		if (found == true)
		{
			newBalance = premiumAccountArray[count]->getBalance();
			returnDeposit = premiumAccountArray[count]->deposit(amountW, dateD);
			if (returnDeposit == true)
			{
				newBalance += amountW;
				cout << showpoint << setprecision(2) << "New balance is " << newBalance << endl;
			}
			break;
		}
	}
	return newBalance;
}

bool premiumAccountExist(int userAccount, PremiumAccount*premiumAccountArray[])
{
	bool found = false;
	for (int i = 0; i < premiumAccountArray[i]->getnumberAccount(); i++)
	{
		if (premiumAccountArray[i]->getNumberPremiumAccount() == userAccount)
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
	for (int i = 0; i < premiumAccountArray[i]->getnumberAccount(); i++)
	{
		if (premiumAccountArray[i]->getNumberPremiumAccount() == userAccount)
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
	cout << "Regular accounts"
		<< "================" << endl;
	for (int index = 0; index < regularAccountArray[index]->getnumberAccount(); index++)
	{
		regularAccountArray[index]->print();
	}

	cout << "Premium accounts"
		<< "================" << endl;
	for (int index = 0; index < premiumAccountArray[index]->getnumberAccount(); index++)
	{
		premiumAccountArray[index]->print();
	}

}


Date showDate(string date)
{
	int month = getMonth(date);
	int day = getDay(date);
	int year = getYear(date);
	Date dateobject;
	dateobject.set(month, day, year);
	return dateobject;
}


#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;


class Date
{
private:
	// member variables
	int month;
	int day;
	int year;
public:
	// function sets the values of dates
	void set(int month_, int day_, int year_)
	{
		month = month_;
		day = day_;
		year = year_;
	}

	// function compares dates with (<) operator
	bool operator<(const Date & rhs)
	{
		int day1 = rhs.day;
		int month1 = rhs.month;
		int year1 = rhs.year;
		if (year < year1)
			return true;
		else if (year > year1)
			return false;
		else if (month < month1)
			return true;
		else if (month > month1)
			return false;
		else if (day < day1)
			return true;
		else
			return false;
	}

	// function compares dates with (==) operator
	bool operator==(const Date & rhs)
	{
		int day2 = rhs.day;
		int month2 = rhs.month;
		int year2 = rhs.year;
		if (year == year2 && month == month2 && day == day2)
			return true;
		else
			return false;



	}

	// function compares dates with (<=) operator
	bool operator<=(const Date & rhs)
	{
		int day3 = rhs.day;
		int month3 = rhs.month;
		int year3 = rhs.year;
		if (year < year3)
			return true;
		else if (year > year3)
			return false;
		else if (month < month3)
			return true;
		else if (month > month3)
			return false;
		else if (day <= day3)
			return true;
		else
			return false;


	}
	// function prints the dates
	void print()
	{
		cout << month << "/" << day << "/" << year << endl;
	}

};


#endif // DATE_H_INCLUDED


#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include<iostream>
#include "Transaction.h"

using namespace std;



class Account
{
private:

    int accountNumber;
	string ownerName;
	static int numberAccount;

protected:

	double balance;
	Transaction **transactionHistory = new Transaction*[0];
	int numberTransaction = 0;
	static double totalNetDeposit;

	void recordTransaction(Transaction *transact);

public:

	Account(int number, string name, double amount, Date date);

	~Account()
	{
		delete transactionHistory;
	}

	bool withdraw(double amount1, Date date1);

	bool deposit(double amount, Date date2);

	int getAccountNumber() const;

	static double getTotalNetDeposit();

	string getName() const;

	double getBalance() const;

	void printTransactions();
	static int getnumberAccount();
	void print();

};

#endif // ACCOUNT_H_INCLUDED


#include"Account.h"
#include<iostream>
#include "Transaction.h"
#include "Date.h"

using namespace std;

double Account::totalNetDeposit = 0.0;
int Account::numberAccount = 0;


Account::Account(int number, string name, double amount,Date date)
{
	accountNumber = number;
	ownerName = name;
	balance = amount;
	Transaction* current = new Transaction(date,balance,0);
	recordTransaction(current);
	totalNetDeposit += amount;
	numberTransaction = 1;
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

bool Account::withdraw(double amount2,Date date1)
{

	if (amount2 > balance)
	{
		cout << "Insufficient balance, withdraw not executed" << endl;
		return false;
	}

	else
	{


		balance -= amount2;
		Transaction* current = new Transaction(date1, balance,2);
		recordTransaction(current);
		totalNetDeposit -= amount2;
		return true;
	}
}


bool Account::deposit(double amount3,Date date2)
{
	if (amount3 < 0)
	{
		cout << "Deposit amount cannot be negative, deposit not executed" << endl;
		return false;
	}
	else
	{

		balance += amount3;
		Transaction *current = new Transaction(date2,balance,1);
		totalNetDeposit += amount3;
		recordTransaction(current);
		return true;
	}
}


void Account::recordTransaction(Transaction *transact)
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

void Account::printTransactions()
{
	for (int i = 0; i < numberTransaction; i++)
	{
		transactionHistory[i]->printTransact();
	}

}

void Account:: print()
{
	cout << "Number:" << getAccountNumber() << ", Name:"
		<< getName() << showpoint<< setprecision(2) << ", Balance:" << getBalance() << endl;
	this->printTransactions();

}


#ifndef REGULARACCOUNT_H_INCLUDED
#define REGULARACCOUNT_H_INCLUDED
#include<iostream>
#include "Transaction.h"
#include "Date.h"
#include "Account.h"

using namespace std;

class RegularAccount : public Account
{
private:
	static int numberRegularAccounts;
public:
	RegularAccount(int number, string name, double amount, Date date) : Account(number, name, amount, date)
	{
		numberRegularAccounts++;
	}

	static int getNumberRegularAccount()
	{
		return numberRegularAccounts;
	}
};
#endif // REGULARACCOUNT_H_INCLUDED


#ifndef PREMIUMACCOUNT_H_INCLUDED
#define PREMIUMACCOUNT_H_INCLUDED
#include<iostream>
#include "Transaction.h"
#include "Account.h"
#include "Date.h"

using namespace std;

class PremiumAccount : public Account
{

private:
	static int numberPremiumAccount;
	static double MIN_BALANCE;
	static double BONUS_THRESHOLD;
	static double BONUS_RATE;
public:
	PremiumAccount(int number1, string name1, double amount1, Date date1) : Account(number1, name1, amount1, date1)
	{
		numberPremiumAccount++;
	}

	int getNumberPremiumAccount()
	{
		return numberPremiumAccount;
	}
	bool withdrawPremium(double amount2, Date date2)
	{
		double currentBalance = amount2 + MIN_BALANCE;
		if (amount2 >= currentBalance)
		{
			cout << "You need to maintain a min balance of $"
			     << MIN_BALANCE << ", withdrawal not executed" << endl;
			return false;
		}
		else
		{
			balance -= amount2;
			Transaction* current = new Transaction(date2,balance, 2);
			recordTransaction(current);
			totalNetDeposit -= amount2;
			return true;

		}
	}

	static double getMinBalance()
	{
		return MIN_BALANCE;
	}

	double calcBonus(int month3, int year3)
	{
		double netTotalDeposit = 0;
		Date startDate, endDate, transactDate;
		startDate.set(month3, 1, year3);
		endDate.set(month3, 30, year3);
		for (int i = 0; i < numberTransaction; i++)
		{
			transactDate = transactionHistory[0]->getTransactionDate();
			if (transactDate.operator<=(startDate) && transactDate.operator<=(endDate))
			{
				transactionHistory[i]->getTransactionAmount();
				if (transactionHistory[i]->getTransactionType == 0 || transactionHistory[i]->getTransactionType == 1)
				{
					netTotalDeposit += transactionHistory[i]->getTransactionAmount();
					cout << "Total net deposit in month = $" << netTotalDeposit << endl;
				}
				else
					netTotalDeposit -= transactionHistory[i]->getTransactionAmount();
			}
		}


		if (netTotalDeposit > BONUS_THRESHOLD)
		{
			return netTotalDeposit * BONUS_RATE;
		}
	}
};

int PremiumAccount::numberPremiumAccount = 0;
double PremiumAccount::MIN_BALANCE = 1000.00;
double PremiumAccount::BONUS_THRESHOLD = 500.00;
double PremiumAccount::BONUS_RATE = 0.01;
#endif // PREMIUMACCOUNT_H_INCLUDED


#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include<iostream>
#include <iomanip>
#include "Date.h"
#include <string>

using namespace std;



class Transaction
{
private:
	    Date transactionDate;
		double transactionAmount;
		double transactionBalance;
		enum operation { CREATION, DEPOSIT, WITHDRAWAL };
		operation transactionType;


public:
	Transaction() {}
	Transaction(Date date, double amt, operation type)
	{
		transactionDate = date;
		transactionAmount = amt;
		transactionType = type;
	}

	string operationToString( int type)
	{
		switch (type) {
		case 0:
			return "Creation";
		case 1:
			return "Deposit";
		case 2:
			return "Withdraw";
		}
		return "ERROR";
	}

	void printTransact()
	{
		cout << "Transaction history :"
			 << "......................." << endl;

		cout  << "Date :";
		      transactionDate.print();
		cout  << showpoint << setprecision(2)
           << ",Amount:" <<transactionAmount << ",type :"
			  << operationToString(transactionType)
			  << showpoint << setprecision(2) <<",New Balance :"
			  << transactionBalance << endl;


	}

	operation getTransactionType() const
	{
		return transactionType;
	}

	double getTransactionAmount() const
	{
		return transactionAmount;
	}

	Date getTransactionDate() const
	{
		return transactionDate;
	}

	double getTransactionBalance() const
	{
		return transactionBalance;
	}

};

#endif // TRANSACTION_H_INCLUDED


