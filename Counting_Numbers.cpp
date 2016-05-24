// Still more counting
//
// Description: The program keep track of all entered numbers from 0-9


#include<iostream>
#include<conio.h>

using namespace std;

// function prototype
void showNumber(int arr[]);
void CountNumber(int num, int arr[]);





int main()

{
int i;

int number[10] = {0,0,0,0,0,0,0,0,0};

int flag=1;

while ( flag)

{
cout<<"Enter a one-digit number or 10 to exit: "<<endl;
cin>>i;

if (i<0 || i>10)
{
cout<<"The value "<<i<<" is not valid."<<endl;
}
else if (i ==10)
{
flag=0;
}
else
{

// call count number function
CountNumber(i,number);
}

}
if (!flag)

{

// call the show number function
showNumber(number);
}
return 0;
}



// function count numbers 0-9
void CountNumber(int num, int arr[])
{

switch(num)
     {

case 0: arr[0]++; break;

case 1: arr[1]++; break;

case 2: arr[2]++; break;

case 3: arr[3]++; break;

case 4: arr[4]++; break;

case 5: arr[5]++; break;

case 6: arr[6]++; break;

case 7: arr[7]++; break;

case 8: arr[8]++; break;

case 9: arr[9]++; break;

    }
}

// function show the index numbers
void showNumber(int arr[])

{

for(int i=0; i<10;i++)
    {
if (arr[i] >0)
       {

cout<<"You entered "<<arr[i]<<" ,"<<i<<"(s)"<<endl;

        }
   }
}



