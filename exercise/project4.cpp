#include<iostream>
using namespace std;
int main()
{
	int secretNumber = 7;
	int playerGuess;
	do
	{
		cout<< "Guess a number:"<<endl;
		cin >> playerGuess;
		if (playerGuess < secretNumber)
		{
			cout << "too low!";
		}
		if (playerGuess > secretNumber)
		{
			cout << "too high!";
		}
	}
	while (secretNumber != playerGuess);
			cout << endl << "you win!";
			while(true){}
		return 0;
	}
