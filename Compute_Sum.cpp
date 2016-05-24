// The compute_sum function
// Compute the sum of all of the numbers from 1 to n where n is a natural number
//use the formula: n(n+1)/2



#include <iostream>

using namespace std;


// compute_sum function
int compute_sum(int limit)    
{
  int sum_to_limit;

  sum_to_limit = limit*(limit + 1)/2;

  return sum_to_limit;

}

int main()
{
	int sum = 0;
	int maxNumber;

	// get the maxNumber for the function call
	cout << "Enter a whole number greater than 0" << endl;
	cin >> maxNumber;


   // call to compute_sum function
	sum = compute_sum(maxNumber); 

	// display the sum calculated by the compute_sum function
	cout << " The sum of 1 to " << maxNumber;
	cout << " is " << sum << endl;

	return 0;
}
