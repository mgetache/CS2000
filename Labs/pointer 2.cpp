#include <iostream>
#include <string>
using namespace std;

int main()
{
	int myarray[3] = { 0,1,2 };

	cout << "Array address:  " << myarray << endl;
	cout << "Item 0 address: " << &myarray[0] << endl;
	cout << "Item 1 address: " << &myarray[1] << endl;
	cout << "Item 2 address: " << &myarray[2] << endl;

	while (true){}
	return 0;
}