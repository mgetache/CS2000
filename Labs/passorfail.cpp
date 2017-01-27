#include<iostream>
#include<string>
using namespace std;
int main()
{
	float studentPoints;
	float totalPoints;
	cout << "what was your score in the exam?";
	cin >> studentPoints;
	cout << "what was the total point ?";
	cin >> totalPoints;

	float percent = studentPoints / totalPoints * 100;

	if (percent == 70)
	{
		cout<< "score:"<< percent<< "%"  << "pass";
	}
	else
	{
		cout << "score:" << percent << "%" << "fail";
	}
	return 0;
}