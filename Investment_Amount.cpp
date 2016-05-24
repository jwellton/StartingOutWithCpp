// Calculate Investment Amount
//
// Description: The program calculates the interest after a period of investment


#include <iostream>
#include <iomanip>
using namespace std;

// function prototype
double future_investment_value( double amount, int months, double rate);
double initial_investment_amount();
double annual_interest_rate();
int number_month();




int main() // program starts here
{
double amount, rate, investment_returns, monthly_rate;

int months;

cout <<"The minimum investment is $10000.00."<< endl;

// call the initial investment amount function
amount = initial_investment_amount();

// call the annual interest rate function
rate = annual_interest_rate();

// call the number of months function
months = number_month();

monthly_rate = rate/1200;

// call the future_investment_value function
investment_returns = future_investment_value(amount,months, monthly_rate);


cout << fixed << setprecision(2);

cout <<"After " <<months <<" months your investment of $"<<amount <<" will be worth $"<< investment_returns << endl;


return 0;
}  //end of main function


//The function ask the user to enter the initial investment amount
double initial_investment_amount()
{
   double amount;

   cout <<"Enter the amount of the investment: ";

   cin >> amount;

   while(amount < 10000)
   {
   cout <<"Error, the minimum investment is $10000.00. "<< endl;

   cout <<"Enter the amount of the investment: ";

   cin >> amount;
   }
   return amount; // returns initial amount
}

// The function asks the user to enter the interest earned
double annual_interest_rate()
{
double rate;

cout <<"Enter the annual interest rate: ";

cin >> rate;

while(rate < 0)
{
cout <<"Error, the interest rate should not be negative. " << endl;

cout <<"Enter the annual interest rate: ";

cin >> rate;   // Repeat when invalid number is entered
}
return rate; // returns rate
}

// The function asks user to enter the number of months for the investment
int number_month()
{
int months;
cout <<"Enter the number of months of the investment: ";

cin >> months;

while(months<0)
{
cout <<"Error, the number of months should not be negative." << endl;

cout <<"Enter the number of months of the investment: ";

cin >> months;
}
return months; // returns number of months
}


// This function calculates the interest earned after a period of investment
double future_investment_value(double amount,int months,double rate)
{

double balane = amount;

//Repeat the number of months of the investment
for(int i=0; i<months; i++)
{
double interest_earned = balane*rate;

balane = balane + interest_earned;
}
return balane; // returns investment balance
}
