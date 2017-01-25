// if greater than equality sign is changed to get the correct out put the value of the boolean variable inside the if and else statment needs to be changed to.
#include<iostream>
#include<string>
using namespace std;

bool isTallEnoughForRide;
float feet;
int main()
{
	cout << "what is your height(ft) ?" << endl;
	cin >> feet;
	if (feet > 3)
	{
		isTallEnoughForRide = true;
		

	}
	else
	{
		isTallEnoughForRide = false;
		
	}
	if (isTallEnoughForRide)
	{
		cout << "permitted to ride the roller coaster";
	}
	else
	{
		cout << "Too short to ride the roller coaster";
	}
	while (true) {}
	return 0;
}