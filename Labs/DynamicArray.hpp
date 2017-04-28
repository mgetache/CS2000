#ifndef _DYNAMIC_ARRAY_HPP
#define _DYNAMIC_ARRAY_HPP
#include <string>
using namespace std;

class DynamicArray
{
private:
	int m_size;
	string * m_arr;
	

public:
	DynamicArray(int size);
	~DynamicArray();
	void Set(int index, string value);
	string Get(int index);
	int GetSize();
	void Display();

};
#endif