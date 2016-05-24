/*
 * Currency Conversion
 * Description : This program ask the user to enter currency in Us Dollars and then convert the amount to other currency using standard exchange rate
 */


#include <iostream>
#include <iomanip>


using namespace std;

// function prototype
float convertToYen (float dollars);

float convertToEuros(float dollarEuros);

float convertToPesos(float dollarPesos);

// standard exchange rate in one dollar equivalent
const float rateDollarToYen = 104.75, rateDollarToPesos = 13.07,rateDollarToEuros = 0.77; 


int main ()
{
   // different currencies
	float dollars, euros, pesos, yen;  

	cout << fixed << showpoint << setprecision(2);

   // Ask the user to enter amount in Us Dollars
	cout << "Please input the amount of Us Dollars you want converted:";   
	cin>> dollars;

   // call convertToYen  function
	yen = convertToYen(dollars); 

   // call convertToEuros function
	euros = convertToEuros(dollars); 

   // call convertToPesos function
    pesos = convertToPesos(dollars);      

    // Display converted Us dollars to other currencies

    cout << "The value of " << dollars << " Dollars is : " <<  endl;

    cout<<  setw(7) << yen << " Yen." << endl;

    cout << setw(5) << euros << " Euros" << endl;

    cout << setw(6) << pesos << " Pesos" << endl;


} // end of main function


  // converts dollar to yen
float convertToYen(float dollars)          
{

	float dollarToYen;

	dollarToYen = dollars * rateDollarToYen;

	return dollarToYen; // returns dollar amount to yen
}

// converts dollar to euros
float convertToEuros(float dollarEuros)  
{

	float dollarToEuros;

	dollarToEuros = dollarEuros * rateDollarToEuros;

	return dollarToEuros; // returns dollar amount to Euros
}

// converts dollar to pesos
float convertToPesos(float dollarPesos)  
{
    float dollarToPesos;
	dollarToPesos = dollarPesos * rateDollarToPesos;

	return dollarToPesos; // returns dollar amount in Mexican Pesos
}


