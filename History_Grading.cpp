// History grading project
//
// Description:  The program asks the user to enter a test score and display a letter grade
// The program aim to determine the performance of the user by using standard grading system
// On a scale of 0 to 100 and then display the equivalent letter grade A,B,C,F


#include <iostream>
#include <iomanip>


using namespace std;


// function prototypes
void getTestGrade( float & firstTest, float & secondTest, float & thirdTest);


void displayTestGrade( float & test1, float & test2, float & test3);


char determineLetterGrade( float totalPoints);

// standard grades scale 0 to 100
const float grade_A = 92, grade_B = 82, grade_C = 72, grade_F = 71;  



int main()
{
  float test1, test2, test3;

  float totalPoints;


  // call the displayTestGrade function
  displayTestGrade( test1,test2,test3); 

     // drops test1
	 if (test1 < test2) 
	    {
	        cout << "After dropping test #1,";

           // add test1 and test3 keeping test3 constant
	        totalPoints = (test2 + test3); 
	        cout << " the points earned are  " << totalPoints << ".\n";
	     }

     // drops test2
	   if (test2 < test1) 
	        {
	            cout << "After dropping test #2, ";

               // add test1 and test3 keeping test3 constant
	            totalPoints = (test1 + test3); 
	            cout << " the points earned are  " << totalPoints << ".\n";

	    }


      // Averages test 1 and test2 when a user enters equal values
	    if (test1 == test2)  
	    {
	        cout << "After averaging test #1 and test #2,";

           // add average of test1,test2 and test3 keeping test3 constant
	        totalPoints = ((test1 + test2) / 2) + test3; 
	        cout << " the points earned are  " << totalPoints << ".\n";
	    }

  // call the determineletterGrade function
  determineLetterGrade(totalPoints); 

 return 0;

}


// function ask the user to enter test score
void getTestGrade(float & firstTest, float & secondTest, float & thirdTest)
{
  cout << "Enter the score for test #1:";
  cin >> firstTest;

  cout << "Enter the score for test #2:";
  cin >> secondTest;

  cout << "Enter the score for test #3:";
  cin >> thirdTest;
}



// function display the test score entered by the user
void displayTestGrade( float & test1, float& test2, float& test3)
{
  getTestGrade(test1, test2, test3);

  cout << "First test:"<< setw(13) << test1 << "\n";

  cout << "Second test:"<< setw(12) << test2 << "\n";

  cout << "Third test:"<< setw(13) << test3 << "\n";
}


// function determine the letter grades
char determineLetterGrade( float totalPoints)
{
	if (totalPoints >= grade_A)
	{
		cout << "The letter grade is A." << endl;
	}

	else if ( totalPoints >= grade_B)
	{
		cout << "The letter grade is B." << endl;
	}

	else if ( totalPoints >= grade_C)
	{
		cout << "The letter grade is C." << endl;
	}

	else
	{
		cout << "The letter grade is F." << endl;
	}

	return totalPoints; // returns letter grades
}
