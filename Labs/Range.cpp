#include<iostream>
using namespace std;

int main()
{
	float x1 = 5;
	float x2;
	cout << "x1 =" << x1 << endl;
	cout << endl << "where is x2 ?";
	cin >> x2;
	
	if (x1 - 5 <= x2 <= x1 + 5)
	{
		cout << "within 5 units from x1!" << endl;
	}
	else
	{
		cout << "Too far away...." << endl;
	}
	while (true);
	return 0;
}