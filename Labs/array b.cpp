#include <iostream>
#include <string>
using namespace std;

int main()
{
	string names[5] = { "Xia", "Shang", "Zhou", "Qin", "Han" };
	
	int index = 0;
	int arraySize = 5;
	while (index < arraySize)
	{
		cout << names[index] << endl;
		index += 1;
		
	}

	while (true) {}
	return 0;

}