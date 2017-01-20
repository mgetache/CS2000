#include <iostream>
#include <string>
using namespace std;

int main()
{
	float ratio;
	cout << "How many batches do you want to make? ";
	cin >> ratio;
	float tspBakingSoda = 1 * ratio;
	float tspBakingPowder = 0.5 * ratio;
	float cupsOfButter = 1 * ratio;
	float cupsOfSugar = 1.5* ratio;
	float  eggs = 1 * ratio;


	cout <<tspBakingSoda<< "tsp baking soda" << endl;
	cout << tspBakingPowder<<" tsp baking powder" << endl;
	cout << cupsOfButter<<" c butter" << endl;
	cout << cupsOfSugar<< "c white sugar" << endl;
	cout << eggs<<"  egg" << endl;
	while (true); // kludgey fix
	
	return 0;
}