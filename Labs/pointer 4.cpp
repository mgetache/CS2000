#include <iostream>
#include <string>
using namespace std;

int main()
{
	string y;
	cout << "which do you want to see about:" << endl;
	cout << "1. Intiger" << endl;
	cout << "2. Floats" << endl;
	cout << "3. boolean" << endl;

	cin >> y;
	if (y == "intiger")
	{
		int x = 100;
		int* ptrx = &x;
		cout << sizeof(x) << " = " << ptrx;
	}
	else if (y == "floats")
		
		{
		float x = 100.0;
		float* ptrx = &x;
			cout << sizeof(x) << " = " << ptrx;
		}
	else
	{
		bool x = true;
		bool* ptrx = &x;
			cout << sizeof(x) << " = " << ptrx;
		
	}

	while (true){}
	return 0;
}