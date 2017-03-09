#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x = 0;
	float y = 1.2;
	string z = "Melkam";

	int *ptrx = &x;
	float *ptry = &y;
	string *ptrz = &z;

	cout << ptrx << " = " << *ptrx << endl;
	cout << ptry << " = " << *ptry << endl;
	cout << ptrz << " = " << *ptrz << endl;

	while (true){}
	return 0;
}