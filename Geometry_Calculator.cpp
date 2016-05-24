/*
Geometry Calculator
Write a program that displays the following menu:
Geometry Calculator
1. Calculate the Area of a Circle
2. Calculate the Area of a Rectangle
3. Calculate the Area of a Triangle
4. Quit
Enter your choice (1-4):
If the user enters 1, the program should ask for the radius of the circle and then display
its area. Use the following formula:
area  π r 2
Use 3.14159 for π and the radius of the circle for r . If the user enters 2, the program
should ask for the length and width of the rectangle and then display the rectangle’s
area. Use the following formula:
area = length * width
If the user enters 3 the program should ask for the length of the triangle’s base and its
height, and then display its area. Use the following formula:
area = base * height * .5
If the user enters 4, the program should end.
Input Validation: Display an error message if the user enters a number outside the range
of 1 through 4 when selecting an item from the menu. Do not accept negative values
for the circle’s radius, the rectangle’s length or width, or the triangle’s base or height

Requirements
1. You are required to write the following functions and call them in the main() function
 getChoice: displays the menu of choices, reads and returns the user’s choice
 calculateCircleArea: prompts the user to input the radius, performs input validation. If input is
valid, calculates the area and returns the result as a double. If input is invalid, return -1.
 calculateRectArea: prompts the user to input the width and height, performs input validation. If
input is valid, calculates the area and returns the result as a double. If input is invalid, return -1
 calculateTriangleArea: prompts the user to input the base and height, performs input validation.
If input is valid, calculates the area and returns the result as a double. If input is invalid, return -1
2. Your main() function implements the following pseudocode
call getChoice to get the user’s choice
perform input validation on the user’s choice and call the appropriate function to calculate the area
display the area if result returned is valid

The program calculates  the area of circle, rectangle,triangle and display the area  of the Geometry
*/

#include<iostream>
#include<cmath>  // Required for mathematical functions
#include<cstdlib> // Required for exit function

using namespace std;

const double PI = 3.14159; // pie constant

// function prototype
double calculateCircleArea(); 

double calculateRectArea(); 

double calculateTriangleArea(); 

int getChoice(); 


int main()
{
   int getInput; 

   // call the getChoice function
   getInput = getChoice(); 
   double area;

   // run user input from 1 -4 and defaults 
   switch (getInput) 
   {
   case 1:

      // call the calculate circle function
      area = calculateCircleArea(); 
      break;
   case 2:

      // call the calculate rectangle function
      area = calculateRectArea(); 
      break;
   case 3:

      // call the calculate triangle function
      area = calculateTriangleArea(); 
      break;
   case 4:
      cout << "Program ending. " << endl;
      return 0;
   default:
      // Breaks when the program encounter error
      break;
   }

   // Validate users input to ensure only specified values are entered 
   if ((getInput < 1) || (getInput > 4))  
   {
      cout << "The valid choices are 1 through 4,Run the program again and select one of those. " << endl;
      return -1;
   }
   else
   {

      // display area from the calculated geometry function
      cout << "The area is " << area << endl; 
   }

   system("pause"); // displays, "Press any key to continue ...."

   return 0;

} // end function main()


  // function calculates circle area 
double calculateCircleArea() 
{
   double circleArea, radius; 

   cout << "Enter the circle's radius: "; 
   cin >> radius;

   // calcultes the area of the circle
   circleArea = PI * pow(radius, 2);  


   // check if the value of the radius is less than zero
   if (radius < 0) 
   {
      cout << "The radius can not be less than zero." << endl;
      exit(0);
   }
   else
   {
      return circleArea; // return the area of the circle
   }
}


double calculateRectArea()
{
   double rectArea, length, width;
   cout << "Enter the rectangle's length: ";
   cin >> length;

   cout << "Enter the rectangle's width: ";
   cin >> width;

   rectArea = length * width;


   // check if the value of the length or the width is less than zero
   if ((length <0) || (width < 0)) 
   {
      cout << "The length or the width can not be less than zero. " << endl;
     exit(0);
   }
   else
   {
      return rectArea; // return the area of the rectangle
   }

}

// calculates the area of the triangle
double calculateTriangleArea() 
{
   double triangleArea, base, height; 
   cout << "Enter the length of the base: ";
   cin >> base;
   cout << "Enter the triangle's height: ";
   cin >> height;

   // calculates the area of the triangle
   triangleArea = base * height * 0.5; 


   // check if the value of the base or the height is less than zero
   if ((base<0) || (height<0))
   {
      cout << "The base or the height can not be less than zero. " << endl;
      exit(0);
   }
   else
   {
      return triangleArea; // return the area of the triangle
   }

}

// functions ask the user to enter choice
int getChoice() 
{
   int choice;

   cout << "Geometry Calculator" << endl << endl;
   cout << "1.  Calculate the area of a Circle" << endl;
   cout << "2.  Calculate the area of a Rectangle" << endl;
   cout << "3.  Calculate the area of a Triangle" << endl;
   cout << "4.  Quit" << endl << endl;
   cout << "Enter your choice (1-4): ";
   cin >> choice;


   return choice;  // return users choice
}


