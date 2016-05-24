// Determine the minimum and maximum target heart rates

#include <iostream>
#include <iomanip>

using namespace std;

int calculate_maximum_heart_rate(int age);

void display_target_heart_rate(int);

void process_target_heart_rate();


int main()
{
	cout<<"Starting";
 process_target_heart_rate();
 process_target_heart_rate();
 process_target_heart_rate();


 return 0;
}

int calculate_maximum_heart_rate(int age)
{
	int max_heart_rate = 220;

	max_heart_rate = 220 -age;

	cout << max_heart_rate;

	return max_heart_rate;
}

void display_target_heart_rate (int max)
{

	cout << max;

	double minimum_target_heart_rate;

	double maximum_target_heart_rate;

	minimum_target_heart_rate = max * 0.6;
	maximum_target_heart_rate = max * 0.7;

	cout << " \n";

	cout << fixed << showpoint << setprecision(1);

	cout << " Minimum target heart rate is " << setw(5) << minimum_target_heart_rate << endl;

	cout << " Maximum target heart rate is " << setw(5) << maximum_target_heart_rate << endl;
}

void process_target_heart_rate()
{
    int maximum_heart_rate;
	int age;
    cout << " Enter your age :" << endl;
	cin >> age;

	 maximum_heart_rate = calculate_maximum_heart_rate(age);

	 display_target_heart_rate(maximum_heart_rate);

}





