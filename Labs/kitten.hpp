#ifndef _KITTEN_HPP
#define _KITTEN_HPP

#include <string>
#include <iostream>
using namespace std;

class kitten
{
private:

	string m_name;

public:
	static int m_kittenCount;
	kitten(string name );
	void Display();

#endif
};
