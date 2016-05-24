/*
Shipping Charges
The Fast Freight Shipping Company charges the following rates:
Weight of Package (in Kilograms) Rate per 500 Miles Shipped
2 kg or less $1.10
Over 2 kg but not more than 6 kg $2.20
Over 6 kg but not more than 10 kg $3.70
Over 10 kg but not more than 20 kg $4.80
Write a program that asks for the weight of the package and the distance it is to be
shipped, and then displays the charges.
Input Validation: Do not accept values of 0 or less for the weight of the package. Do
not accept weights of more than 20 kg (this is the maximum weight the company will
ship). Do not accept distances of less than 10 miles or more than 3,000 miles. These
are the company’s minimum and maximum shipping distances.


The proper way to interpret the rates is that the distance in miles should be
rounded up to the next higher multiple of 500 before the rate is calculated. For example, a distance of
510 miles is rounded up to 1,000 miles, or 2 times 500 miles. If the package weights say 1kg, the charge
will be $1.10 times 2, that is $2.20. If the package weights 5.5 kg, the charge will be $2.20 times 2, that is
$4.40. A distance which is an integral multiple of 500 miles, say 2,000 miles, is not rounded up. If the
distance is 2,000 miles and the weight is 3 kg, the charge will be $2.20 times 4, that is $8.80.

Requirements
1. You are required to write the following functions and call them in the main() function
 getWeight: prompts the user to enter the weight, and performs input validation on the weight.
Returns the weight as a double if the weight is valid, else return -1
 getDistance: prompts the user to enter the distance, and performs input validation on the
distance. Returns the distance as a double if the distance is valid, else return -1
 calculateCharges: takes as argument the weight and the distance, and calculates the shipping
charges. Returns the charges as a double.
2. Your main() function implements the following pseudocode
call getWeight
exit if weight is invalid
call getDistance
exit if distance is invalid
call calculateCharges
print the charges

The program calculates the weight of the package and the distance the package can be shipped then determine the cost of shipping
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>


using namespace std;


// function prototype
double getWeight(); 

double getDistance();

double calculateCharges();

// program starts here
int main()  
{
   double charge;

   // call calculated charge function
   charge = calculateCharges(); 

   cout << fixed << showpoint << setprecision(2) << endl;
   cout << "The shipping charge is $" << charge << endl;

   system("pause");

   return 0;

} // end function main()


  // Validate weight entered by the user
double getWeight()  
{
   double weight, rate; 

   cout << "Weight of the package in kilograms (max 20kg): ";
   cin >> weight;

   //validate inputs from the user and display the rate base on the package weight
   if (weight <= 2.0)
   {
      rate = 1.10;
   }
   else if ((weight > 2.0) && (weight <6.0))
   {
      rate = 2.20;
   }
   else if ((weight >6.0) && (weight<10.0))
   {
      rate = 3.70;
   }
   else if ((weight >10.0) && (weight <20))
   {
      rate = 4.80;
   }
   else
   {
      cout << "We do not ship packages of more than 20kg." << endl;
      exit(0); // exit program for invalid inputs
   }
   return rate; // return rates
}


// Validate distance entered by the user
double getDistance() 
{
   double distance;

   cout << "Distance the package is to be shipped (min 10 Mi, max 3000 Mi): ";
   cin >> distance;

   // program validate inputs from the user and display the miles based on specified standard
   if ((distance > 10) && (distance <500))
   {
      distance = 1.0;;
   }
   else if ((distance > 500) && (distance <1000))
   {
      distance = 2.0;
   }
   else if ((distance >1000) && (distance<1500))
   {
      distance = 3.0;
   }
   else if ((distance >1500) && (distance <2000))
   {
      distance = 4.0;
   }

   else if ((distance >2000) && (distance <= 3000))
   {
      distance = 5.0;

   }
   else
   {
      cout << "We do not ship less than 10 miles or more than than 3000 miles.  " << endl;

      exit(0); // exit program for invalid inputs
   }
   return distance;
}


// calculate the shipping charge
double calculateCharges()  
{
   double charge, distance, weight;

   weight = getWeight();
   distance = getDistance();

   charge = weight * distance;

   return charge;
}