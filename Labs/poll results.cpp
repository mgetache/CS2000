#include<iostream>
#include <string>
#include <fstream>
using namespace std;


struct Option
{
	string title;
	int count;
};

struct Poll
{
	string question;
	Option options[4];
};
int main()
{
	Poll myPoll;

	myPoll.question = "What is the best food?";

	myPoll.options[0].title = "Pizza";
	myPoll.options[0].count = 0;

	myPoll.options[1].title = "Veggie Taco";
	myPoll.options[1].count = 0;

	myPoll.options[2].title = "Samosas";
	myPoll.options[2].count = 0;

	myPoll.options[3].title = "Sushi";
	myPoll.options[3].count = 0;

	bool exit = true;
	while (exit == true)
	{
		cout << "What is the best food ?\n" << "0. Pizza \n" << "1. Veggie Taco \n" << "2. Samosas \n" << "3. Sushi \n" << "4. Exit" << endl;
		cout << "\n what is your selection ?" << endl;

		int x;
		cin >> x;
		if (x == 4)
		{
			exit = false;
		}
		
		myPoll.options[x].count++;
	}

	ofstream output ("result.txt");

	output << "Question " << "\n What is the best food ?" << "\n Results" << endl;

	output << "Pizza ......" << myPoll.options[0].count << endl;
	output << "Veggie Taco." << myPoll.options[1].count << endl;
	output << "Samosas....." << myPoll.options[2].count << endl;
	output << "Sushi......." << myPoll.options[3].count << endl;

	output.close();
	while (true) {}

	return 0;
}