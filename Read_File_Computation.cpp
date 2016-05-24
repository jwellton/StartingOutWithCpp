
/*
Problem 24, page 298 textbook, with the following adaptations:
Instead of the file “Random.txt” mentioned in the problem, use the file “RandomNumbers2.txt” posted
on eLearning and copy it to the same folder you are running your program.
Your program should display a menu asking the user to choose what to calculate (a, b, or c). In addition,
the user also has to option to quit by choosing d. As long as the user does not choose to quit, the
program loops over displaying the menu. Your program must also do input validation and print an error
message if the user types anything other than a, b, c, or d, then display the menu again and ask the user
to reenter the user’s choice.
a) The number of values in the file
b) The sum of all the numbers in the file
c) The average of all numbers in the file
d) Quit
Requirements
1. Although the numbers are integers, the average of the numbers must be calculated as a real average
(for example double), and displayed in decimal notation, with four significant digits after the decimal
point.
2. Your program must check that the file “RandomNumbers2.txt” was opened successfully. If it is not
opened successfully, your program must print an error message and exit.
3. You are allowed to hard code the file name as “RandomNumbers2.txt” in your program.
4. For your program to work, you must close the file and reopen it each time the user makes a new
choice
5. You are required to implement your program with at least 3 functions that are called in the main()
function. Below are suggested functions:
 getUserChoice: displays the menu, prompts the user to enter the choice, performs input
validation, displays the menu again if the input is invalid. Returns the user’s choice if it is valid
 calcNumber: open the file (checks for file open failure and exit the program if there is failure),
read the data, calculate the number of values in the file, then close the file, and returns the
result.
 calcSum: open the file (checks for file open failure and exit the program if there is failure), read
the data, calculate the sum of values in the file, then close the file, and returns the result.
 calcAvg: open the file (checks for file open failure and exit the program if there is failure), read
the data, calculate the average of values in the file, then close the file, and returns the result
6. Your main() function implements the following pseudocode
Do
call getUserChoice
depending on the user’s choice, call the appropriate calculation function, or quit
print the result
Loop while user’s choice is not Quit

The Program reads file and display result by simple computation
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


// function prototype
char getUserChoice();
int calcNumber();
double calcSum();
double calcAvg();


// program starts here
int main() 
{
   // user choice
   char choice = ' ';  
   do
   {
      // call the user choice function
      choice = getUserChoice();  

   } while (choice = 'd');

 
   system(" pause");
   return 0;
}

//user choice function
char getUserChoice()
{
   int cal = 0;
   double sum = 0.0;
   double avg = 0.0;
   char choice;

   cout << " Make your choice " << endl;
   cout << " ---------" << endl;
   cout << " a. Calculate the number of values in the file " << endl;
   cout << " b. Calculate the sum of all values in the file " << endl;
   cout << " c. Calculate the average of all values in the file  " << endl;
   cout << " d. Quit " << endl << endl;

   cout << " Make your choice :" << endl;
   cin >> choice;

   if (choice = 'a')
   {
     cal = calcNumber();
   }

   else if (choice = 'b')
   {
      sum = calcSum();
   }
   else if (choice = 'c')
   {
     avg = calcAvg();
   }
   else if (choice = 'd')
   {
      exit(0);
   }
   
   return choice;

}

// calculate the total number in the file
int calcNumber()
{
   int num = 0;
   int numbers = 0;
   double sum = 0.0;
   double average = 0.0;

   ifstream randomFile;
   randomFile.open("RandomNumbers2.txt");

   if (randomFile.fail()) {
      cout << "failed to read file.";
   }
   else {

      while (randomFile >> num)
      {
         numbers++;
         sum += num;
      }

      if (numbers>0)
         average = sum / numbers;
      else
         average = 0.0;

      cout << "Number of values is " << numbers << "\n";
    
   }

   randomFile.close();

   return numbers;

}

// sum the numbers from the file
double calcSum()
{
   int num = 0;
   int numbers = 0;
   double sum = 0.0;
   double average = 0.0;

   ifstream randomFile;
   randomFile.open("RandomNumbers2.txt");

   if (randomFile.fail()) {
      cout << "failed to read file.";
   }
   else {

      while (randomFile >> num)
      {
         numbers++;
         sum += num;
      }

      if (numbers > 0)
         average = sum / numbers;
      else
         average = 0.0;

      cout << "Sum of values is " << sum << "\n";
   }

   randomFile.close();

   return sum;
}

// average the numbers from the file
   double calcAvg()
   {
      int num = 0;
      int numbers = 0;
      double sum = 0.0;
      double average = 0.0;

      ifstream randomFile;
      randomFile.open("RandomNumbers2.txt");

      if (randomFile.fail()) {
         cout << "failed to read file.";
      }
      else {

         while (randomFile >> num)
         {
            numbers++;
            sum += num;
         }

         if (numbers > 0)
            average = sum / numbers;
         else
            average = 0.0;

         cout << "Average of values is " << average;

      }

      randomFile.close();

      return average;
   }
          
      
