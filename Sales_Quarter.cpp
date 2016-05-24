// Sales by quarter
//
// Description: The program calculate the sales amount for each salesman


#include <iostream>
#include <string>

using namespace std;


// program start here
int main()

{


     string name[3];
     double total=0.0;
     string readName = "";
     int i;
     double sale[3][4];
     double totalAmount = 0;


     for (int i = 0; i < 3; i++)

     {

          cout << "Enter in the name of the Salesman" << i + 1 << " : ";

          cin >> name[i];

cout <<endl<<"Enter in sales for each quarter for " << name[i] << endl;

          cout << endl;

          for (int j = 0; j < 4; j++)

          {

              cout << "Enter in data for quarter " << j + 1 << " : ";

              cin >> sale[i][j];

          }

          cout << endl;

     }cout << endl;

for(int j = 0; j < 4; j++)

     {

          total = sale[0][j];

          for(i = 0; i < 3; i++)

          {

              if(total < sale[i][j])

              {

            total = sale[i][j];
                   readName = name[i];
              }
          }

cout << "Salesman " << readName << " has highest sale for quarter " << j + 1 << " with $" << total << ".00" << endl;

   }

   cout << endl;

   return 0;

}
