#include <iostream>
#include <string>
using namespace std;

int main()
{
	string items[3];
	float price[3];
	int arraySize = 3;
	int itemCount = 0;

	while (itemCount < arraySize)
	{
		cout << "enter item name" << endl;
		cin >> items[itemCount];

		cout << "enter price";
		cin >> price[itemCount];
		itemCount++;
	}
	cout << endl;

	int counter = 0;
	while (counter < itemCount)
	{
		cout << "Item #" << counter << ": " << items[counter] << ", $" << price[counter] << endl;
		counter++;
	}


	while (true) {}
	return 0;

}