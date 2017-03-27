# include <iostream>
using namespace std;
# include <string>;

int main()
{
	int * myInt;
	string * myStr;
	float * myFloat;

	myInt = new int;
	myStr = new string;
	myFloat = new float;


	*myInt = 20;
	*myStr = "Melkam";
	*myFloat = 199.99;

	cout << *myInt << endl << *myStr << endl << *myFloat;


	delete myInt;
	delete myStr;
	delete myFloat;
	

	while(true){}
	return 0;
}