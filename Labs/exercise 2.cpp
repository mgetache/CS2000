# include <iostream>
using namespace std;
# include <string>;

	struct Person
	{
		string name;
		Person* ptrFriend;
	};
int main()
{

	Person * personA = new Person;
	Person * personB = new Person;
	Person * personC = new Person;

	personA ->name = "Harry";
	personB->name = "Ron";
	personC->name = "Hermione";


	personA-> ptrFriend = personB;
	personB->ptrFriend = personC;
	personC->ptrFriend = personA;

	cout << "person A: " << personA->name << ",  friend:  " << personA->ptrFriend->name << endl;
	cout << "person B: " << personB->name << ",  friend:  " << personB->ptrFriend->name << endl;
	cout << "person C: " << personC->name << ",  friend:  " << personC->ptrFriend->name << endl;




	while (true) {}

	return 0;
}