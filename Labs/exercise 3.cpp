# include <iostream>
using namespace std;
# include <string>
#include <cstdlib>      
#include <ctime>  
int main()
{
	srand(time(NULL)); 
	int size;
	cout << "amount of lotto balls" << endl;
	cin >> size;

	int* lottoNumbers;
	lottoNumbers = new int[size];

	for (int i = 0 ; i < size; i++)
	{
		*lottoNumbers = rand() % 101;
		
		cout <<" " << *lottoNumbers;

	}

	delete lottoNumbers;
	while (true){}
	return 0;


}
