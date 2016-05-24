// An array of 10 Integers
//
// Description: The program display entered numbers in reversed order



#include<iostream>
using namespace std;

// function prototype
int getUserChoice( int arr[]);
int displayReverseOrder(int arr[]);




int main()
{
   int arr[9];

   // call the get user choice function
   getUserChoice(arr);

   cout << "\n\n";
   cout << "The values in reversed order are:" << endl;

   // call display reversed number functions
   displayReverseOrder(arr);
}

// function get user number choice function
int getUserChoice(int arr[])
{
   for (int i=1;i<=10;i++)
   {
       cout<<"Enter Number "<<i<<":";
       cin>>arr[i];
   }
return 0;
}

// function display reversed number function
int displayReverseOrder(int arr[])
{
   for (int i=10;i>-1;--i)
   {
       cout<<"Value Number "<<i<<":";
       cout << arr[i]<< endl;
   }

return 0;
}




