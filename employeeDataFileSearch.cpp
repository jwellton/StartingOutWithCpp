// This program search employee data from a file 

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int getNumberRecords();
int linearSearch(int employeeId[], int SIZE, int IdVal);
void getData(int Id[], int rate[]);


int main()
{
   int readFile = getNumberRecords();

    cout << "Actual number of records =" <<  readFile << endl;

    int const fileRecord = 97;
    int *ID = new int[fileRecord];
    int *rate = new int[fileRecord];
    getData(ID,rate);

    delete[] ID;
    delete[] rate;

    //rate = nullptr;
    //ID = nullptr;

    return 0;
}

int getNumberRecords()
{
   ifstream fileData;
   int readFile, rate;
   int index = 0;
   fileData.open("employeeFile2.txt");
   if (fileData)
   {
      while(fileData >> readFile)
      {  //cout << readFile << endl;
         fileData >> rate;
         //cout << readFile <<"   " << rate << endl;
          index++;
      }
      return index;
   }
   else
   {
       cout << "error opening file " << endl;
   }

   fileData.close();
}


int linearSearch(int employeeId[], int SIZE, int IdVal)
{
   for (int index = 0; index <= SIZE; index++)
   {
      if(IdVal == employeeId[index])
      {
         return index;
      }
   }
   return -1;
}



void getData(int Id[], int rate[])
{
   ifstream inFile;
   int index;

   inFile.open("employeeFile2.txt");
   if (!inFile)
   {
      cout << "Sorry encountered an error opening the file" << endl;
   }
   else
   {
      while (inFile >> Id[index] )
      {
         inFile >> rate[index];

         index++;
      }
   }

   inFile.close();

   int fileSize = getNumberRecords();
   int userEmployeeId, hourlyRate;
   cout << "Input employee'ID, 0 to quit :";
   cin >> userEmployeeId;
   cout << "Input the number of hours:";
   cin >> hourlyRate;

   int searchKey;

   if(userEmployeeId == 0)
   {
      exit(0);
   }
   else if ((userEmployeeId >= 1 && userEmployeeId <= 999999)&& hourlyRate >= 1)
   {
      searchKey = linearSearch(Id, fileSize,userEmployeeId);
      if (searchKey == -1)
      {
         cout << "Employee not found" << endl;
         cout << "It took 97 comparisons" << endl;
      }
      else
      {
         int wage = rate[index] * hourlyRate;
         cout << "ID =" << userEmployeeId << " hours" << hourlyRate << endl;
         cout << "Employee" << userEmployeeId << ", rate =" << rate[index] << ", hours =" << hourlyRate << ", wage =" << wage << endl;
         cout << "It took" << searchKey << "comparisons" << endl;
      }
   }
   else
   {
      cout << "Invalid entry, ID must be between 1 and 999999, Please reenter:";
      cin >> userEmployeeId;
      cout << "Invalid entry, Hours must be positive, Please reenter:";
      cin >> hourlyRate;
   }

}
