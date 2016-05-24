// Financial Aid Program



#include <iostream>

using namespace std;


// function prototype
int undergraduate_student();

int annual_income();

void print_input_data(int amount);




int main()
{
   // call undergraduate student function
   int student = undergraduate_student(); 

   if(student == 1)
   {
      // call annual income function
       int income = annual_income(); 
       if(income > 0)
       {
           print_input_data(income);
       }
       else cout << "You do not qualify for financial aid\n";
   }
   else cout << "You do not qualify for financial aid\n";

   return 0;
}


// get a yes or no answer from the user
int undergraduate_student()   
{
   char answer;

   cout << "Are you an undergraduate student? ";

   cin >> answer;

   if(answer == 'y' || answer == 'Y')
	   return 1;

   else if(answer == 'n' || answer == 'N')
	   return 0;

   else
   {
       cout << "Student type is invalid\n";

       return -1;
   }
}


// check user income
int annual_income() 
{
   double income;

   cout << "What is your current yearly income? ";

   cin >> income;

   if(income < 0)
   {
       cout << "Aid amount is not valid\n";

       return -1;
   }
   else if(income > 15000)
   {
       return 500;
   }
   else return 1000;
}

// display the result from user if qualified or not
void print_input_data(int amount)  
{
   if(amount > 0)

	   cout << "You qualify for $" << amount << " in financial aid.\n";

   else
	   cout << "You do not qualify for financial aid\n";
}
