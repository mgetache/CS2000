#include<iostream>
#include<string>
using namespace std;
int main()
{
	string homeTown;
	string name;
	cout << "what is your home town?";
	cin >> homeTown;
	if (homeTown.size() > 6)
	{
		cout << endl << "That's a long name!" << endl;
	}
	cout << "what is your name ?" << endl;
	cin >> name;
	cout << endl << "Hello, " << name << "from" << homeTown << "!" << endl;
	return 0;
}