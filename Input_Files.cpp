// Percentage of numbers input from a file
//
// Description: The program calculates the percentage of negative numbers, equal to zero and greater than zero



#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

// function prototype
int evaluate_input(int number);
int compute_file_input(ifstream& infile,int& greater_than_zero, int& equal_to_zero,int& negative_num);


// program starts here
int main()
{
   // read numbers from file
   ifstream infile("numbers.txt");
   if(!infile)
   {
	   // display when file fails to open
       cout <<"unable to open file. so exiting from program" << endl; return 0;
   }
   int sum;
   int greater_than_zero,equal_to_zero,negative_num;

   // call the compute functions
   sum = compute_file_input(infile, greater_than_zero, equal_to_zero, negative_num);
   infile.close(); // close file

   cout << fixed << showpoint << setprecision(1)<< endl;
   cout << setw(4)<<"There were " << static_cast<double>(100*negative_num)/sum <<"% negative numbers. "<< endl;
   cout << setw(4)<<"There were " << static_cast<double>(100*equal_to_zero)/sum <<"% numbers equal to zero." << endl;
   cout << setw(4)<<"There were "<< static_cast<double>(100*greater_than_zero)/sum<<"% numbers greater than zero." << endl;
   return 0;
} // end of main function


// function check if number is less than zero
int evaluate_input(int number)
{
   if(number>0) return 1;

   // return error when number is less than zero
   if(number<0) return -1;
   return 0;
}


// function compute the numbers from file
int compute_file_input(ifstream& infile,int& greater_than_zero, int& equal_to_zero,int& negative_num)
{
   int num; // number from the file
   greater_than_zero = equal_to_zero = negative_num = 0;
   int count = 0;

   // check for error from file
   while(!infile.eof())
   {
       infile >> num;
       count++;

       // call evaluate input function
       if(evaluate_input(num)==1) greater_than_zero++;

       // call evaluate input function
       else if(evaluate_input(num)==-1) negative_num++;
       else equal_to_zero++;
   }
   return count;
}
