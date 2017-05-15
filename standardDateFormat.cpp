/*
This program demonstrate input validation for strings.
The program takes string input,validates, compares
then display dates in integer format on the console
*/

#include <iostream>
#include "Date.h"
#include <string>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

// function prototypes
int getMonth (string month2);
int getDay (string day2);
int getYear (string year2);

int main () // program starts here
{
   // Date variables declaration
	int month, day, year;
	const int NUM_DATES = 4;
	string dateArray[NUM_DATES] = { "02/12/2017", "02/12/2018", "02/13/2017", "03/12/2017" };

	// Driver for the Date class
	cout << "***********************************\n";
	cout << "Part A - Driver for the Date class:\n";
	cout << "***********************************\n";
	Date d1, d2;
	for (int i = 0; i < NUM_DATES; i++)
		for (int j = 0; j < NUM_DATES; j++)
		{
			month = getMonth (dateArray[i]);
			day = getDay (dateArray[i]);
			year = getYear (dateArray[i]);
			d1.set (month, day, year);
			cout << "\n================\n";
			cout << "d1: ";
			d1.print ();
			month = getMonth (dateArray[j]);
			day = getDay (dateArray[j]);
			year = getYear (dateArray[j]);
			d2.set (month, day, year);
			cout << "\nd2: ";
			d2.print ();
			cout << endl;
			if (d1 < d2) cout << "d1 < d2\n";
			if (d2 < d1) cout << "d2 < d1\n";
			if (d1 == d2) cout << "d2 == d1\n";
			if (d1 <= d2) cout << "d1 <= d2\n";
			if (d2 <= d1) cout << "d2 <= d1\n";
		}

	return 0;
} // end of main function

// function gets months
int getMonth (string date)
{
   // access month from index 0 then return string length
   string monthStr = date.substr(0,2);
   // convert strings to integer
	int numMonth = atoi(monthStr.c_str());
	return numMonth;
}

// function gets day
int getDay (string date)
{

   // access day from index 3 then return string length
   string dayStr = date.substr(3,2);
   // converts string to integer
	int numDay = atoi(dayStr.c_str());

	return numDay;
}

// functions gets year
int getYear (string date)
{
   // access year from index 6 then return string length
	string yearStr = date.substr(6,4);
	// converts string to integer
	int numYear = atoi(yearStr.c_str());

	return numYear;
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
	void set (int month_, int day_, int year_)
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
		if(year < year1)
         return true;
      else if(year > year1)
         return false;
      else if(month < month1)
         return true;
      else if(month > month1)
         return false;
      else if(day < day1)
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
		if(year == year2 && month == month2 && day == day2)
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
		if(year < year3)
         return true;
      else if(year > year3)
         return false;
      else if(month < month3)
         return true;
      else if(month > month3)
         return false;
      else if(day <= day3)
         return true;
      else
         return false;


	}
   // function prints the dates
	void print ()
	{
		cout << month << "/" << day << "/" << year << endl;
	}

};


#endif // DATE_H_INCLUDED


