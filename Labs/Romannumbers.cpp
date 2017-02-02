#include <iostream>
#include <string>
using namespace std;
int main()
{
	int num;
	string roman;
	cout << "please inter a number between 1 and 5" << endl;
	cin >> num;
	switch (num)
	{
	case 1:
		roman = "I";

		break;

	case 2:
		roman = "II";

		break;
	case 3:
		roman = "III";

			break;
	case 4:
		roman = "IV";

			break;
	case 5:
		roman = "V";

			break;


	}
	cout << endl << roman;
	while (true) {}
	return 0;
	
}