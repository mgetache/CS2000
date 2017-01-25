// the scope of both variables is within the manin function that is inside the int manin() function.
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int age;
	float ticketPrice;

	cout << "Age?";
	cin >> age;

	if (age < 13)
	{
		ticketPrice = 5.00;
	}
	else
	{
		ticketPrice = 7.00;
	}
	cout << "Ticket price: " << ticketPrice << endl;

	while (true){}
	return 0;
}