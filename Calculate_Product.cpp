// Calculate the Product
//
// Description: The program calculates the product of sequence of numbers


#include <iostream>
using namespace std;


// program starts here
int main()  
{
int number=1, product = 1, count = 0;

// loop executes once before testing values
do
{
       product = product * number;

       // increment result of the product
          count++;

          cout << "Enter an integer number to be included in the product"
          << endl << "or enter 0 to end the input: ";
          cin >> number;

}while(number!=0);

if (count > 1)
{
          cout << endl << "The product is " << product << "." << endl;
}
return 0;
}  //end of  main function
