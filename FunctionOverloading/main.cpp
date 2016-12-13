#include <iostream>
#include <conio.h>
#include "Cspeed.h"

using namespace std;

// This is not overloading as the function differs only 
// in return type
/*int Add(float x, float y)
{
	return x + y;
}*/

int main()
{
	CSpeed speed;

	cout << speed.AddSpeed(2.4f, 7.9f) << endl;
	cout << speed.AddSpeed(4, 5) << endl;
	cout << speed.AddSpeed(4, 9, 12) << endl;

	_getch();
	return 0;
}