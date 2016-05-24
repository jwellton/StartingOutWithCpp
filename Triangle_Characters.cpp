/*
Write a program that assigns the character ‘*’ to a variable, then displays that variable according to a
triangle pattern. The triangle is 4 rows high. The top row has 1 character, and the bottom row has 7
characters. The program then reassigns the character ‘$’ to the same variable and displays the variable
according to the same triangle pattern. The output of your program should be as below.


The program displays star and dollar triangle charaters 

*/


#include <iostream>

using  namespace std;


int main()
{
   char empty_char, star, dollar;

   empty_char = ' ';
    
   star = '*';  

   dollar = '$';

   // This program display star triangle pattern

   cout <<  empty_char <<  empty_char <<  empty_char <<  star <<  empty_char <<  empty_char <<  empty_char << endl;

   cout <<  empty_char <<  empty_char <<  star <<  star <<  star <<  empty_char <<  empty_char << endl;

   cout <<  empty_char <<  star <<  star <<  star <<  star <<  star <<  empty_char << endl;

   cout <<  star <<  star <<  star <<  star <<  star <<  star <<  star << endl << endl;

   
   

   // This program display dollar triangle pattern

   cout <<  empty_char <<  empty_char <<  empty_char <<  dollar <<  empty_char <<  empty_char <<  empty_char << endl;

   cout <<  empty_char <<  empty_char <<  dollar <<  dollar <<  dollar <<  empty_char <<  empty_char << endl;

   cout <<  empty_char <<  dollar <<  dollar <<  dollar <<  dollar <<  dollar <<  empty_char << endl;

   cout <<  dollar <<  dollar <<  dollar <<  dollar <<  dollar <<  dollar <<  dollar << endl << endl;

   system(" pause"); // displays " Press any key to continue ...."

   return 0;


} // end main() function