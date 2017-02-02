#include <iostream>
using namespace std;

int main()
{
	int feet;
	cout << "how much feet do you want to measure?";
	cin >> feet;
	for (int i = 0; i <= 12 * feet; i++)
	{
		if (i % 12 == 0)
		{
			cout << "|";
		}
		else
		{
			cout << "-";
		}
	}

		while (true) {}
	
	return 0;
}