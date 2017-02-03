#include <iostream>
#include <string>
using namespace std;

float CountChange(int quarterCount, int dimeCount, int nickelCount, int pennyCount)
{
	float money = 0.25*quarterCount + 0.1*dimeCount + 0.03*nickelCount + 0.001*pennyCount;
	return money;
}
int main()
{
	while (true)
	{
		int quarters, dimes, nickels, pennies;

		cout << "How many quarters? ";
		cin >> quarters;

		cout << "How many dimes? ";
		cin >> dimes;

		cout << "How many nickels? ";
		cin >> nickels;

		cout << "How many pennies? ";
		cin >> pennies;

		float money = CountChange(quarters, dimes, nickels, pennies);
		cout << "Money: $" << money << endl;

		cout << endl << endl;
	}

	return 0;
}
