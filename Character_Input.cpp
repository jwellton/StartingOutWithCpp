// Display a row of $ characters based on user input
//
// Description: The program display $ characters by comparing numerical values



#include<iostream>

using namespace std;

// function prototype
int input_val(int &number);
void display_dollar_symbol(int value);


// program starts here
int main() 
{
   int dollar_value = 0;

   //call the input val function
   while(input_val(dollar_value)!= 0)
   {
	   //call the display function
       display_dollar_symbol(dollar_value);
       dollar_value = 0;

   }
} // end of main function

//function asks user to enter a number
int input_val(int &number)
{
   do
   {
       cout<<"Enter the next number (1-10): ";
       cin>>number;
       if(number < 0 || number > 10)
       {
           cout<<"That is a invalid number."<<endl;
       }
   }
   while(number < 0 || number > 10);

   return number;
}

//function display dollar symbols
void display_dollar_symbol(int value)
{

   for( int i = 0; i< value; i++)
   {
       cout<<"$";
   }
   cout<<endl;
}


