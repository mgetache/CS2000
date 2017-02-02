#include <iostream>
#include <string>
using namespace std;
int main()
{
	int price;
	string city;
	cout << "what is the price of the item" << endl;
	cin >> price;
	cout << " What city are you in ?"<<endl;
	cin >> city;
	if (city == "olathe" || "Olathe")
	{
		cout << "Total price is :"<<price + .065*price; 
	}
	else if (city == "OverlandPark" || city == "overlandpark")
	{
		cout<< "Total price is :" << price + .0935*price;
	}
	else if (city == "Raytown" || "raytown")
	{
		cout<< "Total price is :" << price + .08225*price;
	}
	else if (city == "independence" || "Independence")
	{
		cout<< "Total price is :" << price + .07255*price;
	}
	else
	{
		cout<< "Total price is :" << price + .08*price;
	}
	while (true){}
	return 0;
}