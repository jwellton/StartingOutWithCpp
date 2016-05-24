// The gross and net pay applications

#include <iostream>
#include <iomanip>

using namespace std;


// Function prototypes
// Print out the program description
void printDescription();

// Calculate gross pay
float computeGrossPay(float, int);

// Calculate net pay
float computeNetPay(float);


int main()
{
   // variables for
   float payRate;
   float grossPay;
   float netPay;
   int hours;

   cout << setprecision(2) << fixed;
   cout << "Welcome to the Payroll Program" << endl;

   printDescription(); //Call to Description function

   // Get the pay rate and number of hours from the user
   cout << "Please input the pay per hour: ";
   cin >> payRate;

   cout << endl << "Please input the number of hours worked: ";
   cin >> hours;

   cout << endl << endl;

   // get the gross pay
   grossPay = computeGrossPay(payRate, hours);

   netPay = computeNetPay(grossPay);


   cout << " Your gross pay is " << grossPay << endl;

   cout << " Your net pay is " << netPay << endl;

   cout << "We hope you enjoyed this program" << endl;

   return 0;
}

// printDescription
void printDescription() //The function heading
{
   cout << endl;
   cout << "*************************************************" << endl;
   cout << "This program takes two numbers (pay rate & hours)"
        << endl;
   cout << "and multiplies them to get gross pay. The program "
        << endl;
   cout << "then calculates net pay by subtracting 15%" << endl;
   cout << "*************************************************" << endl
        << endl;
}


// computeGrossPay
float computeGrossPay(float rate, int time)
{
   float grossPay;

   grossPay = rate *time;
   return grossPay;
}

// computeNetPay
float computeNetPay(float gross)
{
	float const grossPayRate = 0.15;
	float netPay;

	netPay = gross - gross*grossPayRate;
	return netPay;

}
