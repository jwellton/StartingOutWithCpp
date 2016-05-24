/*
Rock, Paper, Scissors Game
Write a program that lets the user play the game of Rock, Paper, Scissors against the
computer. The program should work as follows.
1. When the program begins, a random number in the range of 1 through 3 is generated.
If the number is 1, then the computer has chosen rock. If the number is 2, then
the computer has chosen paper. If the number is 3, then the computer has chosen
scissors. (Don’t display the computer’s choice yet.)
2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard.
(You can use a menu if you prefer.)
3. The computer’s choice is displayed.
4. A winner is selected according to the following rules:
• If one player chooses rock and the other player chooses scissors, then rock wins.
(The rock smashes the scissors.)
• If one player chooses scissors and the other player chooses paper, then scissors
wins. (Scissors cuts paper.)
• If one player chooses paper and the other player chooses rock, then paper wins.
(Paper wraps rock.)
• If both players make the same choice, the game must be played again to determine
the winner.
Be sure to divide the program into functions that perform each major task.


You are required to implement your program with at least 3 functions that are called in the main()
function. Here are some suggested functions:
 getUserChoice: displays the menu, prompts the user to enter the choice, performs input
validation, displays the menu again if the input is invalid. Returns the user’s choice if it is valid
 getComputerChoice: uses the random number generator to randomly select a choice and
returns the choice
 determineWinner: takes as arguments the user’s choice and the computer’s choice and
determines the winner. Prints what are the choices and who is the winner
2. Your main() function implements the following pseudocode
call getComputerChoice
call getUserChoice
loop as long as user’s choice is not Quit
call determineWinner
call getComputerChoice
call getUserChoice
end loop

The program asks the user to select number 1 to 4 and wait for the computer to randomly select numbers
*/



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


const int ROCK = 1;    // initialize rock to 1
const int PAPER = 2;    // initialize  paper to 2
const int SCISSORS = 3;  // initialize scissors to 3

// function prototype
int getUserChoice();  
int getComputerChoice(); 
void determineWinner(int userChoice, int computerChoice);  


// program starts here
int main()   
{

  

   int userChoice = 1;       
   int computerChoice = 1;   
 

   // loops as long as the selected number is not 4
   while (userChoice != 4 || computerChoice != 4)      
   {

     // call the determine winner function
     determineWinner(userChoice, computerChoice);   

   }
   

   system("pause");  

   return 0;

} // end of main function


  // prompt the user to enter a number
int getUserChoice()   
{
   int userChoice;  
   cout << " Game Menu " << endl;
   cout << " ---------" << endl;
   cout << " 1) Rock " << endl;
   cout << " 2) Paper " << endl;
   cout << " 3) Scissors " << endl;
   cout << " 4) Quit " << endl << endl;

   cout << " Enter your Choice ";
   cin >> userChoice;

   // range of acceptable numbers
   if (userChoice < 1 || userChoice > 4)   
   {
      cout << " Invalid selection: Enter 1,2,3 or 4" << endl;
      cout << " Enter your Choice ";
      cin >> userChoice;
   }

   return  userChoice; // returns users choice
}


// get computer choice 
int getComputerChoice()  
{
   int computerChoice;  

   // random number generator
   computerChoice = (rand() % 3 + 1); 

   return computerChoice;  // return computer choice

}


// determine the winner of he game
void determineWinner(int userChoice, int computerChoice)   
{
   // call the get user function
   userChoice = getUserChoice();  

   // call the get computer choice
   computerChoice = getComputerChoice();  

   if (userChoice == 1 && computerChoice == 2)
   {
      cout << " You selected:" << " Rock" << endl;
      cout << " The computer selected:" << " Paper" << endl;
      cout << " Computer win! Paper wraps rock." << endl << endl;
   }

   else if (userChoice == 2 && computerChoice == 1)
   {
      cout << " You selected:" << " Paper" << endl;
      cout << " The computer selected:" << " Rock" << endl;
      cout << " You win! Paper wraps Scissors." << endl << endl;
   }
   
   else if (userChoice == 2 && computerChoice == 3)
   {
      cout << " You selected:" << " Paper" << endl;
      cout << " The computer selected:" << " Scissors" << endl;
      cout << " Computer win! Scissors cuts paper." << endl << endl;
   }
   
   else if (userChoice == 3 && computerChoice == 2)
   {
      cout << " You selected:" << " Scissors" << endl;
      cout << " The computer selected:" << " Paper" << endl;
      cout << " You win! Paper wraps Scissors." << endl << endl;
   }
   
   else if (userChoice == 1 && computerChoice == 3)
   {
      cout << " You selected:" << " Rock " << endl;
      cout << " The computer selected:" << "Scissors " << endl;
      cout << " You win! Rock smashes Scissors." << endl << endl;
   }

   else if (userChoice == 3 && computerChoice == 1)
   {
      cout << " You selected:" << " Scissors" << endl;
      cout << " The computer selected:" << " Rock " << endl;
      cout << " Computer win! Rock smashes Scissors." << endl << endl;
   }

   else if (userChoice == 4 || computerChoice == 4)
   {
      exit(0);
   }


   else if (userChoice == 1 && computerChoice == 1) 
   {
      cout << " You selected:" << " Rock" << endl;
      cout << " The computer selected:" << " Rock" << endl;
      cout << " Tie. No Winner. " << endl << endl;
   }

   else if (userChoice == 2 && computerChoice == 2)
   {
      cout << " You selected:" << " Paper" << endl;
      cout << " The computer selected:" << " Paper" << endl;
      cout << " Tie. No Winner. " << endl << endl;
   }

   else if (userChoice == 3 && computerChoice == 3)
   {
      cout << " You selected:" << " Scissors" << endl;
      cout << " The computer selected:" << " Scissors" << endl;
      cout << " Tie. No Winner. " << endl << endl;
   }

}