#include <iostream>
#include <conio.h>
#include <string>
#include "Stack.h"

using namespace std;

template<class T>
void Print(T array[], int array_size)
{
	for (int nIndex = 0; nIndex < array_size; ++nIndex)
	{
		cout << array[nIndex] << "\t";
	}
	cout << endl;
}

int main()
{
	int iArray[5] = { 4, 5, 6, 6, 7 };
	char cArray[3] = { 'c', 's', 'b' };
	string sArray[3] = { "Kratos", "Dr Evil", "Mario" };

	// Printing any type of elements
	Print(iArray, sizeof(iArray) / sizeof(*iArray));
	Print(cArray, sizeof(cArray) / sizeof(*cArray));
	Print(sArray, sizeof(sArray) / sizeof(*sArray));

	Stack<int> iStack;

	// Pushes an element to the bottom of the stack
	iStack.push(7);

	cout << iStack.top() << endl;

	for (int i = 0; i < 10; i++)
	{
		iStack.push(i);
	}

	// Removes an element from the top of the stack
	iStack.pop();


	// Prints the top of stack
	cout << iStack.top() << endl;

	_getch();
}