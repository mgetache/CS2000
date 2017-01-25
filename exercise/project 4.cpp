// it wont give us a correc answer, this is do to in our program we have only one conditon to check, that is whether it is less than or greater than but not equal to each other.
// if we have another condition in our program that is to check "==" we would get they are the same. (that is including cout<<" they are the same";
#include<iostream>
#include<string>
using namespace std;
int main()
{
	char letter1, letter2;
	cout << "please inter two alphabets";
	cin >>letter1 >>letter2;
	if (letter1 < letter2)
	{
		cout << " first letter comes first";
	}
	
	else
	{
		cout << "second letter comes first";
	}
	while (true){}
	return 0;
}