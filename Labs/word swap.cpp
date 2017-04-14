#include<iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
	

	cout << "What words will you want to search ?" << endl;

	string search;
	cin >> search;

	cout << "What words will you want to replace it with ?" << endl;
	string replace;
	cin >> replace;

	string buffer;

	ifstream input ("swap.txt");
	ofstream output ("modified.txt");

	while (input >> buffer)
	{
		if (buffer == search)
		{
			output << replace << " ";

		}
		else
		{
			output << buffer << " ";
		}
	 }

	input.close();
	output.close();

	while (true) {}


	return 0;
}