//Convert to Roman Numerals



#include <iostream>

using namespace std;


// function prototype
int user_data_input();

void  roman_numeral_equivalent(int select);


int main()
{
   int number = user_data_input();

   if(number > 0)
   {
       roman_numeral_equivalent(number);
  }

   return 0;
}// end of main function



 // Get numbers from the user
int user_data_input()  
{
   int number;

   //Ask user to enter a number
   cout << "Enter a number from 1 to 5: ";

   cin >> number;

   if(number >= 1 && number <= 5) return number;

   cout << "The number must be in the range of 1 through 5 inclusive.\n";

   return 0;
}

// Print numbers to Roman numeral equivalent
void  roman_numeral_equivalent(int select)
{
   // switch statement evaluates the user's input and display output
   switch(select)
   {
       case 1:
           cout << "The Roman numeral equivalent is: I\n";
           break;

       case 2:
           cout << "The Roman numeral equivalent is: II\n";
           break;

       case 3:
           cout << "The Roman numeral equivalent is: III\n";
           break;

       case 4:
           cout << "The Roman numeral equivalent is: IV\n";
           break;

       case 5:
           cout << "The Roman numeral equivalent is: V\n";
           break;
   }
}


