/*
This program demonstrate exception handling.
when a user enter an invalid value for the chosen shape
The program takes entered value from the user and determine ,
if the value is valid or throws an exceptions
then display dates in integer format on the console
*/

#include <iostream>
#include <string>
#include <iomanip>
#include"BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include <cstdlib>

using namespace std;

int main()
{
	const int NUM_SHAPES = 3;
	BasicShape *shapeArray[NUM_SHAPES]; // pointer array to Basic shape
	int index, userChoice;
	double Xcentric, Ycentric, radius; // variables for the shape

	cout << "Extra credit version \n";
	cout << "---------------------\n";

	for (index = 0; index < NUM_SHAPES; index++)
	{
		cout << "Enter shape: 1 for circle , 2 for rectangle: ";
		cin >> userChoice;
		switch (userChoice)
		{
		case 1: try
		         {
			           cout << "Enter x coordinate of center: ";
                    cin >> Xcentric;
			           cout <<"Enter y coordinate of center: ";
                    cin >> Ycentric;
			           cout << "Enter radius: ";
			           cin >> radius;
			           cout << "\n";
		              Circle  *circlePtr = new Circle(Xcentric, Ycentric, radius); // call circle constructor
			           shapeArray[index] = circlePtr;  // circle pointer to shape array
		          }
				  catch (Circle::NegativeValue)
				    {
					      cout << "Negative input value" << endl;
					      return 0;
               }
				  break;

		case 2 : try
               {
			           cout << "Enter width: ";
			           cin >> Xcentric;
			           cout << "Enter length: ";
			           cin >> Ycentric;
			           cout << "\n";
                    Rectangle *rectanglePtr = new Rectangle(Xcentric, Ycentric); // call circle constructor
			           shapeArray[index] = rectanglePtr; // rectangle pointer to shape array

               }
		        catch (Rectangle::NegativeValue)
		        {
                    cout << "Negative input value " << endl;
                    return 0;
              }
		        break;

		        default:
		               cout << "Invalid shape entered, please reenter\n";
		               cout << "Enter shape: 1 for circle , 2 for rectangle: ";
                     cin >> userChoice;
              break;
		}

	}

	for (index = 0; index < NUM_SHAPES; index++)
	{
		shapeArray[index]->printInfo(); // prints the shapes

	}

	return 0;
}



#ifndef BASICSHAPE_H_INCLUDED
#define BASICSHAPE_H_INCLUDED

class BasicShape
{
private:
	double area;
public :

	double getArea() const
	{
		return area;
	}

	void setArea(double shapeArea)
	{
		area = shapeArea;
	}
	virtual~BasicShape()
	{

	}

	virtual double calcArea() const = 0;

	virtual void printInfo() const = 0;

};


#endif // BASICSHAPE_H_INCLUDED



#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "BasicShape.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Circle : public BasicShape
{
private :
	double centerX;
	double centerY;
	double radius;
public:
	class NegativeValue{};

	Circle(double Xcentric, double Ycentric, double circleRadius)
	{
		centerX = Xcentric;
		if (Ycentric >= 0)
		{
			centerY = Ycentric;
		}
		else
			throw NegativeValue();

		radius = circleRadius;

	}
	virtual~Circle ()
	{
	}

	virtual double calcArea() const
	{
		const double Pi = 3.14159;

		return (Pi * radius * radius);
	}


	virtual void printInfo() const
	{
		double  returnArea = calcArea();
		cout << "Shape is Circle,"
			  << "xCenter = " << centerX
			  << ",yCenter = " << centerY
			  << ",radius = " << radius
			  << ",area = " << returnArea << endl;

	}
};


#endif // CIRCLE_H_INCLUDED




#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "BasicShape.h"
#include <iostream>
using namespace std;

class Rectangle: public BasicShape
{
private:
	double width;
	double length;
public:
	class NegativeValue {};
	Rectangle(double rectWidth, double rectLength)
	{
		width = rectWidth;
		if (rectLength >= 0)
		{
			length = rectLength;
		}
		else
			throw NegativeValue();
	}
	virtual~Rectangle()
	{

	}

	virtual double calcArea()const
	{
		return(width * length);
	}

	virtual void printInfo() const
	{
		double returnArea = calcArea();
		cout <<"Shape is Rectangle,"
			  << "width = " << width
			  << ",length = " << length
			  << ",area = " << returnArea << endl;
	}

};


#endif // RECTANGLE_H_INCLUDED


