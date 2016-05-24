/*
Stock Profit
The profit from the sale of a stock can be calculated as follows:
Profit  (( NS  SP )  SC )  (( NS  PP )  PC )
where NS is the number of shares, SP is the sale price per share, SC is the sale commission
paid, PP is the purchase price per share, and PC is the purchase commission paid.
If the calculation yields a positive value, then the sale of the stock resulted in a profit.
If the calculation yields a negative number, then the sale resulted in a loss.
Write a function that accepts as arguments the number of shares, the purchase price per
share, the purchase commission paid, the sale price per share, and the sale commission
paid. The function should return the profit (or loss) from the sale of stock.


You can earn extra credit (5 points) if in addition to the function in the basic assignment, you implement
a single function “getData” that prompts the user to input the number of shares, the purchase price per
share, the purchase commission paid, the sale price per share and the sale commission paid, reads the
data, then provides that data to the main function by using reference variables.


The program ask users to enter the number of shares, purchases , commission and then calculates the profit

*/


#include <iostream>
#include <iomanip>

using namespace std;


// function prototype
double getData();  


int main()
{

   double gross;

// call getData function
   gross = getData(); 

   return 0;

   system("pause");

} // end of main function

double getData()
{
   double numberShares, stockPerShare, purchaseCommission, salePricePerShare, saleCommission;


   cout << " How many shares did you buy and then sell? ";
   cin >> numberShares;
   cout << "What price did you pay for the stock per share? ";
   cin >> stockPerShare;
   cout << " What was the purchase commission? ";
   cin >> purchaseCommission;
   cout << " What was the sale price per share? ";
   cin >> salePricePerShare;
   cout << " What was the sales commission? ";
   cin >> saleCommission;

   double stockProfit;            

   // calculates the stock profits
   stockProfit = ((numberShares*salePricePerShare) - saleCommission) - ((numberShares*stockPerShare) + purchaseCommission);

   cout << fixed << showpoint << setprecision(2);
   cout << " The profit from this sales of stock is  $" << setw(6) << stockProfit << endl;

   return stockProfit;  // returns calculated stock profit
   
}