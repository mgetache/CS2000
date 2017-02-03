#include<iostream>
using namespace std;

float percentToDecimal(float percent)
{
	float decimal = percent / 100;
	return decimal;
}
int main()
{
	float a, b, c;
	a = percentToDecimal(50);
	b = percentToDecimal(12.5);
	c = percentToDecimal(99.99);
	
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
	
	while (true){}
	return 0;

}