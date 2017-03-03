#include <iostream>
#include <string>
using namespace std;

int main()
{
	string cities[20];
	int arraySize = 20;
	cities[0] = "Lee's Summit";
	cities[1] = "Raytown";
	cities[2] = "Independence";
	cities[3] = "Belton";
	int itemCount = 4;

	for (itemCount = 0; itemCount < 4; itemCount++)
	{
		cout << cities[itemCount] << endl;
	}
	while (true) {}

	return 0;
}