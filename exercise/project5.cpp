#include<iostream>
using namespace std;
int main()
{
	cout << "please enter a number between 0 and 5:"<<endl;
	int choice;
	cin >> choice;
	while (choice <= 0 || choice >=5)
	{
		cout << "invalid entry. Try again:";
		cin >> choice;
	}
	cout << "Thank you!";
	while(true){}
	return 0;
}