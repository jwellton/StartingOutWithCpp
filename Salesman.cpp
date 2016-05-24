
// Sales for each salesman
//
// Description: The program calculate the sales amount for each salesman



#include <iostream>

#include <string>

using namespace std;



int main()

{

     string name[3];

     double sale[3][4];

     double totalAmount;
     totalAmount = 0.0;


     for (int i = 0; i < 3; i++)

     {

          cout << "Enter in the name of the Salesman" << i + 1 << " : ";

          cin >> name[i];

          cout <<endl<<"Enter in sales for each quarter for "<< name[i] << endl;

          cout << endl;

          for (int j = 0; j < 4; j++)

          {

              cout << "Enter in data for quarter " << j + 1 << " : ";

              cin >> sale[i][j];

          }

          cout << endl;

     }

     for (int i = 0; i < 3; i++)

     {

          for (int j = 0; j < 4; j++)

          {

              totalAmount = totalAmount + sale[i][j];

          }

          cout <<endl<<"Total sales for " << name[i] << " is $"<< totalAmount << ".00";

          totalAmount = 0;

     }

     cout << endl;

     return 0;

}
