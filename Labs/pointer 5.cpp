#include <iostream>
#include <string>
using namespace std;
int main()
{ 
	float priceHamburger = 10;
	float priceFries = 3;
	float priceSalad = 4;

	float *ptrPrice = 0;

	cout << " what do you want to have ?" << endl;
	cout << " 1. Hamburger " << endl;
	cout << " 2. Fries " << endl;
	cout << " 3. Salad " << endl;
	 
	string choice;
	cin >> choice;

	if (choice == "hamburger")
	{
		ptrPrice = &priceHamburger;
		
	} 
	if (choice == "Fries")
	{
		ptrPrice = &priceFries;
	}
	if (choice == "salad")
	{
		ptrPrice = &priceSalad;
	}
	
	float taxAmt = 0.065 * (*ptrPrice);
	*ptrPrice = *ptrPrice + taxAmt;

	cout << "Price will be = " << *ptrPrice;
	
	
	while (true){}
	return 0;
 }