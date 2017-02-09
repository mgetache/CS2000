#include <iostream>
#include <string>
using namespace std;

string GetEnglish(string hindi)
{
	if (hindi == "billee")
	{
		cout << "cat" << endl << endl;
	}
	else if (hindi == "kutta")
	{
		cout << "Dog" << endl << endl;
	}
	else if (hindi == "medhak")
	{
		cout << "frog" << endl << endl;
	}
	else if (hindi == "khargosh")
	{
		cout << "Rabbit" << endl << endl;
	}
	else
	{
		cout << "word not found" << endl << endl;
	}
	return hindi;

}
string GetHindi(string eng)
{
	if (eng == "cat")
	{
		cout << "billee" << endl<<endl;
	}
	else if (eng == "dog")
	{
		cout << "kutta" << endl<<endl;
	}
	else if (eng == "frog")
	{
		cout << "medhak" << endl<<endl;
	}
	else if (eng == "rabbit")
	{
		cout << "khargosh" << endl<<endl;
	}
	else
	{
		cout << "word not found" << endl<<endl;
	}
	return eng;
}
void EnglishToHindi(string eng)
{
	cout << "please enter a word" << endl<<endl;
	cin >>eng;
	GetHindi(eng);
	

}
void HindiToEnglish(string hindi)
{
	cout << "please enter a word" << endl << endl;
	cin >> hindi;
	GetEnglish(hindi);


}
void DisplayMenu(string x, string y, string z)
{
	x = "English to Hindi choose 1";
	y = "Hindi to English choose 2 ";
	z = "To quit choose 3";
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;

}
int main()
{
	char choice;
	bool exit = false;
	while (exit == false)
	{
		DisplayMenu("x", "y", "z");
		cin >> choice;
		if (choice == '1')
		{
			EnglishToHindi("eng");
		}
		 else if (choice == '2')
		{
			HindiToEnglish("hindi");
		}
		else
		{
			exit = true;
		}
	}




	while (true) {}
	return 0;
}