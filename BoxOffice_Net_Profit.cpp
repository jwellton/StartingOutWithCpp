/*
Box Office
A movie theater only keeps a percentage of the revenue earned from ticket sales. The
remainder goes to the movie distributor. Write a program that calculates a theater’s
gross and net box office profit for a night. The program should ask for the name of the
movie, and how many adult and child tickets were sold. (The price of an adult ticket is
$10.00 and a child’s ticket is $6.00.) It should display a report similar to
Movie Name: “Wheels of Fury”
Adult Tickets Sold: 382
Child Tickets Sold: 127
Gross Box Office Profit: $ 4582.00
Net Box Office Profit: $ 916.40
Amount Paid to Distributor: $ 3665.60
NOTE: Assume the theater keeps 20 percent of the gross box office profit

This Program calculates the theater's gross and net profit
*/



#include <iostream>

#include <iomanip>

#include <string>

using namespace std;


const double GROSS_PERCENT = .20, PRICE_CHILD = 6.00, PRICE_ADULT = 10;

// program starts here
int main()  
{
   

   double adultTicket, childTicket, grossProfit, netProfit, distributorAmount;  

   string movieTitle;         


   // The program asks the user to enter movie title and tickets
   cout << " Please enter the movie title: ";

   getline(cin, movieTitle);

   cout << " Please enter the number of adult tickets and number of child tickets :";

   cin >> adultTicket;
   cout << "Please enter the number of adult tickets and number of child tickets :";
   cin >> childTicket;

   // calculate the gross and net profits  
   grossProfit = (adultTicket* PRICE_ADULT) + (childTicket*PRICE_CHILD);
  
   netProfit = grossProfit * GROSS_PERCENT;

   distributorAmount = grossProfit - netProfit;

  // display the results of gross and net profit
  cout << "Movie name                             \''" << movieTitle << "\"\n";
  cout << left;
  cout << "Adult Tickets Sold                      " << adultTicket << endl;
  cout << "Child Tickets Sold                      " << childTicket << endl;
  cout << right << fixed << showpoint << setprecision(2);
  cout << "Gross profit                           $" << setw(8) << grossProfit << endl;
  cout << "Net profit                             $" << setw(8) << netProfit << endl;
  cout << "Amout Paid to Distributor              $" << setw(8) << distributorAmount << endl;

  system("pause");

  return 0;


} // end of function main()
