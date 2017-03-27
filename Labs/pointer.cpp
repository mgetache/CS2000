#include <iostream>
#include <string>
using namespace std;

struct College
{
	string name;
	string state;
};
struct Student
{
	string name;
	College* ptrSchool;
};

int main()
{
	College metro[3];
	metro[0].name = "JCCC";
	metro[1].name = "MCCKC";
	metro[2].name = "KCKCC";

	metro[0].state = "KS";
	metro[1].state = "MO";
	metro[2].state = "KS";

	Student stud[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "please enter student name" << endl;
		cin >> stud[i].name;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << i << "  " << metro[i].name << "  " << metro[i].state << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		int index;
		cout << "Student:  ";
		cout<< stud[i].name << "  " << "please enter school you want to go" << endl;
		cin >> index;


		stud[i].ptrSchool = &metro[index];
	}
		for (int i = 0; i < 5; i++)
		{
			cout << stud[i].name;
			cout<< "  " << stud[i].ptrSchool->name << stud[i].ptrSchool->state;
		}
		
		
	
while (true){}
return 0;
}