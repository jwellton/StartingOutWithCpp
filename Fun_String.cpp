// Fun with strings
//
// Description: The program get names from user and display choices


#include<iostream>

#include<string>

using namespace std;

// function prototype
int readName(string getNames[],int readNum);
void showName(string displayNames[], int showNum);


int main()

{
string getNum[10];
int num;

num = readName(getNum,10);
cout << " \n";
showName(getNum,num);

return 0;

}
// function get user name choice
int readName(string getNames[],int readNum)

{

string changeName;
}
