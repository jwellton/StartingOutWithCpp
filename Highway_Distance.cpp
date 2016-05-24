/*
Distance per Tank of Gas
A car with a 20-gallon gas tank averages 23.5 miles per gallon when driven in town
and 28.9 miles per gallon when driven on the highway. Write a program that calculates
and displays the distance the car can travel on one tank of gas when driven in town
and when driven on the highway.
Hint: The following formula can be used to calculate the distance:
Distance  Number of Gallons  Average Miles per Gallon

The program calculates and displays the distance the car travel on one tank in town and on the highway
*/


#include <iostream>

using namespace std;


int main()
{

   int number_gallon;

   double miles_town, miles_highway, distance_town, distance_highway; 

   number_gallon = 20;

   miles_highway = 28.9;

   miles_town = 23.5;

   distance_town = number_gallon * miles_town; 

   cout << "Distance the car can travel in town is " << distance_town << " miles " << endl;


   distance_highway = number_gallon * miles_highway;


   cout << "Distance the car can travel on the highway is " << distance_highway << " miles " << endl;


   system("pause"); // displays, "Press any key to continue ...."


   return 0;


} // end function main()