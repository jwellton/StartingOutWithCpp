// Calculate MPH (Miles Per Hour) and KPH (Kilometers Per Hour)
//



#include <iostream>
#include <iomanip>

using namespace std;


const double KILOMETERS = 1.609344;

int main()
{

  double hours_traveled;

  double start_mileage;

  double end_mileage;

  double total_miles;

  double total_kilometers;

  double miles_per_hours;

  double kilometers_per_hours;



  // This Program ask the user to enter mileage and hours traveled
  cout << " Enter the starting mileage :" ;
  cin >> start_mileage;

  cout << " Enter the ending mileage :";
  cin >> end_mileage;

  cout << " Enter the number of hours traveled :";
  cin >> hours_traveled;


  // Calculates the mileage and hours traveled
  total_miles = end_mileage - start_mileage;

  miles_per_hours = total_miles / hours_traveled;

  total_kilometers = total_miles * KILOMETERS;

  kilometers_per_hours = total_kilometers / hours_traveled;


  // Display the result of calculation
  cout << fixed << setprecision(1);

  cout <<"\n";

  cout << " Total miles                            " << setw(6) << total_miles << endl;

  cout << " Miles/Hour                             " << setw(6) << miles_per_hours << endl;

  cout << " Total Kilometers                       " << setw(6) << total_kilometers << endl;

  cout << " Kilometers/Hours                       " << setw(6) << kilometers_per_hours << endl;


  return 0;


}
