#include<iostream>
using namespace std;
int main()
{
	int sum = 0;
	bool isDone = false;
	while (!isDone)
	{
		char input;
		int num;

		cout << "please inter a number";
		cin >> num;
		sum = sum + num;
		
		cout << "type (A ) if you want to enter another variable" << endl;
		cout << "type (Q ) if you do not want to enter another number";
		cin >> input;
		if (input == 'Q' || input == 'q')
		{
			isDone = true;
			cout << sum;
		}

	}

	while (true) {}
	return  0;

}