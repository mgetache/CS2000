#include "kitten.hpp"
#include <iostream>
#include <string>
using namespace std;

int kitten::m_kittenCount = 0;

kitten::kitten (string name)
{
	m_name = name;
	m_kittenCount++;
}

void kitten::Display()
{
	cout << m_name << ",  " << "kitten count: " << m_kittenCount << endl;
}