// This calculate the average test score for students

#include <iostream>

using namespace std;

const int NUM_TESTS =3;

struct Student
{
   string name;
   int idNum;
   int tests[NUM_TESTS];
   double average;
   char grade;
};

Student *initArrays(int numStudent);
void getInfo(Student myStudentInfo[],int numStudent);
void showInfo (Student myStudentInfo[], int numStudent);
void testGrade(Student myStudentInfo[], int numStudent,int numTest);




int main()
{
   int numStudent;

   cout << "There are " << NUM_TESTS  << " tests per student " << "\n";

   Student *studPtr;

   cout << "Enter the number of students : ";
   cin >> numStudent;

   studPtr = initArrays(numStudent);

   getInfo( studPtr,numStudent);

   testGrade(studPtr, numStudent,NUM_TESTS);

   showInfo (studPtr,numStudent);

   return 0;
}



Student *initArrays(int numStudent)
{
   Student * studPtr;

   studPtr = new Student[numStudent];

   return studPtr;
}


void getInfo(Student myStudentInfo[],int numStudent)
{
   int testGrade;

   for (int student = 0; student < numStudent; student++)
   {
      cout << "Student name :";
      cin.ignore();
      getline(cin, myStudentInfo[student].name);

      cout << "ID Number :";
      cin >> myStudentInfo[student].idNum;
      while(myStudentInfo[student].idNum <= 0)
      {
         cout << "Please enter an ID number greater than 0:";
         cin >> myStudentInfo[student].idNum;
      }

     for (int test = 0; test < NUM_TESTS; test++)
      {
         cout << " Test #" << (test+1) << ":";
         cin >> testGrade;
         while(testGrade < 0)
         {
            cout << "Enter 0 or greater :";
            cin >> testGrade;
         }

         myStudentInfo[student].tests[test] = testGrade;
    }
  }
}





void testGrade(Student myStudentInfo[],int numStudent, int numTest)
{

   double averageScore;

   for (int student = 0; student < numStudent; student++)
   {
      averageScore = 0;

      for (int test = 0; test < numTest; test++)

      averageScore += myStudentInfo[student].tests[test];

      myStudentInfo[student].average =  (averageScore/numTest);

      if ( myStudentInfo[student].average >= 90)
      myStudentInfo[student].grade = 'A';
      else if (myStudentInfo[student].average >= 80)
      myStudentInfo[student].grade = 'B';
      else if (myStudentInfo[student].average >= 70)
      myStudentInfo[student].grade = 'C';
      else if (myStudentInfo[student].average >= 60)
      myStudentInfo[student].grade = 'D';
      else
      myStudentInfo[student].grade = 'F';

   }

}



void showInfo (Student myStudentInfo[], int numStudent)
{
   for (int student = 0; student < numStudent; student++)
   {
      cout << "Student name: " << myStudentInfo[student].name << "\n";
      cout << "ID number: " << myStudentInfo[student].idNum << "\n";
      cout << "Average test score: " << myStudentInfo[student].average << "\n";
      cout << "Grade: " << myStudentInfo[student].grade << "\n\n";
    }
}
