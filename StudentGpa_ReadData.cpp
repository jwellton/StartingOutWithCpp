
/*
Write a program that reads from the “studentData.txt” file and puts the data into these parallel arrays.
The “studentData.txt” file is posted on eLearning.
 the students’ names in an array called nameArray.
 the students’ majors in an array called majorArray
 the students’ GPA in an array called gpaArray
The arrays are populated in the order the data is read from the file. For example, the first name read
from the file is assigned to the first element of the nameArray, the second name read is assigned to the
second element of the nameArray, and so on. The other arrays are populated in the same fashion. Note
the file contains a student’s name, followed by the student’s major, followed by the student’s GPA (you
do not have to type this data, the file will be posted on eLearning):
Kai CS 3.8
Alice ME 3.9
Seppo CE 3.2
Ken BME 3.0
Anna EE 3.8
Make sure when you read from the file, you store the items in the arrays in the proper order.
The program then uses a loop to display the students names, another loop to display the students
majors, and another loop to display the students’ GPAs. All the data is displayed in the order they are in
the arrays. Then the program displays a menu of choices. As long as the user does not choose to quit,
the program loops over the menu display
1) Search for the lowest GPA (the program then displays the GPA, name and major)
2) Search for the highest GPA (the program then displays the GPA, name and major)
3) Search on a student’s name (the program displays the name, GPA and major if found, or “Not found”)
4) Quit
Requirements
1. You are required to implement your program with at least 3 functions that are called in the main()
function. Below are suggested functions:
 getUserChoice: displays the menu, prompts the user to enter the choice, performs input
validation, displays the menu again if the input is invalid. Returns the user’s choice if it is valid
 searchLowestGPA: takes as arguments the gpaArray and its size, and returns the index of the
lowest GPA. For example, if gpaArray[2] is the lowest element of the gpaArray, the function
returns 2.
 searchHighestGPA: takes as argument the gpaArray and its size, and returns the index of the
highest GPA
 searchName: takes as arguments a name, the nameArray and its size, and returns the index of
the nameArray element that matches the name argument. Returns -1 if no match
 display: takes as argument an index and the nameArray, majorArray and gpaArray, and displays
the elements of nameArray, majorArray and gpaArray at the index
2. Your main() function implements the following pseudocode
Open file
Read from the file and populate the arrays
Display the nameArray
Display the majorArray
Display the gpaArray
While user does not quit
call getUserChoice
depending on the user’s choice, call the appropriate function, and display the result

The Program reads student data from a file and display names and GPA of the students
*/

#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>


using namespace std;

// function prototypes
int getUserChoice();
int highestStudentGpa(double gpaArr[], int);
int lowestStudentGpa(double gpaArr[], int);
int StudentName(string studentName, string nameArr[], int size);
void displayInfo(int index, string nameArr[], double gpaArr[], string majorArr[]);


int main() // program starts here
{

   
   
   int userChoice,highGpa,lowGpa, otherNames;  
   ifstream infile;                           
   string nameArr[20], majorArr[20], studentName, major;  
   double gpaArr[20];  



   int count = 0;   

   // open file from the project file
   infile.open("studentData.txt");   
   if (!infile)

      // display when file failed to open 
      cout << "Error opening file" << endl;  
   else
   {
      // Reads data in the file
      while (infile >> nameArr[count])
      {
         infile >> majorArr[count];
         infile >> gpaArr[count];
         count++;

      }

      infile.close();  // close file

   }
   cout << "Names array" << endl;
   cout << "-----------" << endl;
   for (int i = 0; i < 5; i++)
   {
      cout << "nameArray[" << i << "] = " << nameArr[i] << endl;
   }
   cout << endl;

   cout << "Major array" << endl;
   cout << "-----------" << endl;
   for (int i = 0; i < 5; i++)
   {
      cout << "majorArray[" << i << "] = " << majorArr[i] << endl;
   }
   cout << endl;

   cout << "GPA array" << endl;
   cout << "---------" << endl;
   for (int i = 0; i < 5; i++)
   {
      cout << "gpaArray[" << i << "] = " << gpaArr[i] << endl;
   }
   cout << endl;

   do
   {

      // call get user functions
      userChoice = getUserChoice();  


      if (userChoice == -1)
      {
         continue;
         exit(0);
         system("pause");
      }
      else if (userChoice == 1)
      {
         // call the student low Gpa function
         lowGpa = lowestStudentGpa(gpaArr, 5);  

         // call function to display student Gpa and names
         displayInfo(lowGpa, nameArr, gpaArr, majorArr);   
      }
      else if (userChoice == 2)
      {
         // call the student high Gpa function
         highGpa = highestStudentGpa(gpaArr, 5);   
         displayInfo(highGpa, nameArr, gpaArr, majorArr);
      }
      else if (userChoice == 3)
      {
         cout << "Input name: ";
         cin >> studentName;
         otherNames = StudentName(studentName, nameArr, 5);
         //cout << "name match = " << nameMatch << endl;
         if (otherNames == -1)
         {
            cout << "Name not found" << endl;
            continue;
         }
         displayInfo(otherNames, nameArr, gpaArr, majorArr);
      }


   } while (userChoice != 4);


   system("pause");
   return 0;

}  // end of main function

   // high Gpa student function
int highestStudentGpa(double gpaArr[], int size)  
{

   double highGpa;  
   int highGpaIndex;
   int i;
   highGpa = gpaArr[0];
   for (i = 1; i<size; i++)
   {
      if (gpaArr[i]>highGpa)
      {
         highGpa = gpaArr[i];
         highGpaIndex = i;
      }

   }
   return highGpaIndex;
}

// low Gpa student function
int lowestStudentGpa(double gpaArr[], int size)  
{
   
   double lowGpa;       
   int lowGpaIndex = 0;
   int i;
   lowGpa = gpaArr[0];
   for (i = 1; i<size; i++)
   {
      if (gpaArr[i]<lowGpa)
      {
         lowGpa = gpaArr[i];
         lowGpaIndex = i;
      }

   }
   return lowGpaIndex;
}


// functions get user choice
int getUserChoice()  
{

   int choice;
   cout << "Enter your choice" << endl;
   cout << "1 - Search for the lowest GPA" << endl;
   cout << "2 - Search for the highest GPA" << endl;
   cout << "3 - Search on a student's name" << endl;
   cout << "4 _ Quit" << endl;
   cin >> choice;
   if (choice<1 || choice >4)
   {
      cout << "Invalid choice reenter" << endl;
      return-1;
   }
   else
      return choice;
}

// display student name, major and Gpa
void displayInfo(int index, string nameArr[], double gpaArr[], string majorArr[])  
{

   cout << "Name is " << nameArr[index] << ", major is " << majorArr[index] << ", GPA = " << gpaArr[index] << endl;

}

// function loops student names
int StudentName(string studentName, string nameArr[], int size)  
{
   int i;
   int studentNameIndex = 0;
   for (i = 0; i<size; i++)
   {
      if (studentName == nameArr[i])
         return i;
   }
   return -1;
}
