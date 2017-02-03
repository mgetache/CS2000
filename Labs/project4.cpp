#include<iostream>
using namespace std;
int main()
{
	float startingWage;
	float percentRaisePerYear;
	float adjustedWage;
	int yearsWorked;

	cout << "what is your starting wage?";
	cin >> startingWage;

	cout << "what % of a raise do you get per year? %";
	cin >> percentRaisePerYear;

	percentRaisePerYear /= 100;
	
	cout << "How many years have you worked? ";
	cin >> yearsWorked;
 adjustedWage = startingWage;

	for (int i = 0; i < yearsWorked; i++)
	{
		adjustedWage += adjustedWage * percentRaisePerYear;
	}
	cout << "your new wage is $" << adjustedWage;
	while (true){}
	return 0;

}