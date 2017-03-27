#include <iostream>
#include <string>
using namespace std;

struct Employee
{
	string name;
};
struct Manager
{
	string name;
	Employee* employees;
	int employeeCount;
};

int main()
{
	string names[16] = {
		"Koios", "Julianna", "Agata", "Arundhati",
		"Zemfira", "Fedya", "Kim", "Ashok",
		"Jouni", "Blandina", "Ampelio", "Rosmunda",
		"Breeshey", "Ferdinand", "Gertrude", "Sarit" };


		cout << "How many managers there should be?" << endl;
		int managerCount;
		cin >> managerCount;

		Manager*managers;
		for (int i =0; i< managerCount; i++)
		{
			
			managers = new Manager[managerCount];
			managers[i].name = names[rand() % 16];
			managers[i].employeeCount = rand() % 4;
			if (managers[i].employeeCount>0)
			{
				managers[i].employees = new Employee[managers[i].employeeCount];
				for (int j = 0; j<managers[i].employeeCount; j++)
				{
					managers[i].employees[j].name = names[rand() % 16];
				}
			}
	}
		for (int m = 0; m < managerCount; m++)
		{
			cout << endl;
			cout << "Manager:           "
				<< managers[m].name << endl;
			cout << "Underling Count:   "
				<< managers[m].employeeCount << endl;

			for (int e = 0; e < managers[m].employeeCount; e++)
			{
				cout << "\t" << e + 1 << ". "
					<< managers[m].employees[e].name << endl;
			}
		}
		for (int i = 0; i<managerCount; i++)
		{

			if (managers[i].employeeCount>0)
			{
				delete[]managers[i].employees;
			}
		}

		delete[]managers;
	while (true){}
	return 0;
}