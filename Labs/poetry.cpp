#include<iostream>
#include <string>
#include <fstream>
using namespace std;
#include <cstdlib>      
#include <ctime> 

struct PoemMaker
{
	string nouns[10];
	string adjectives[10];

	void LoadNouns(string filename)
	{
		ifstream nounfile(filename);
		for (int i = 0; i < 10; i++)
		{
			nounfile >> nouns[i];
			
		}
		nounfile.close();
	}
	void LoadAdjectives(string filename)
	{
		ifstream adjfile(filename);
		for (int i = 0; i < 10; i++)
		{
			adjfile >> adjectives[i];
		}
		adjfile.close();

	}
	string GetRandomNoun()
	{
		
		int randomNumber = rand() % 10;

		return nouns [randomNumber];
	}
	string GetRandomAdjective()
	{
		int randomNumber = rand() % 10;

		return adjectives[randomNumber];
	}
	string GeneratePoem(int lines)
	{
		string poem = " ";
		
		for (int i = 0; i < lines; i++)
		{
			poem += " ";
			poem += GetRandomNoun();
			poem += " ";
			poem += GetRandomAdjective();
			poem += "\n";
		}
		return poem;
	}

	
};

int main()
{
	srand(time(NULL));

	PoemMaker poemMaker;
	poemMaker. LoadNouns ( "nouns.txt");
	poemMaker.LoadAdjectives("adjectives.txt");

	string poem = poemMaker.GeneratePoem(5);
	cout << poem;


	while (true) {}
	return 0;
}