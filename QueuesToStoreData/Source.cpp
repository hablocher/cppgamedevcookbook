#include <iostream>
#include <queue>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	queue <string> gunInventory;
	gunInventory.push("Ak-47");
	gunInventory.push("BullPup");
	gunInventory.push("Carbine");

	cout << "This is your weapons inventory" << endl << endl;
	cout << "The first gun that you are using is " << gunInventory.front() << endl << endl;
	cout << "There are currently " << gunInventory.size()
		<< " more guns in your inventory is "
		<< gunInventory.front() << "." << endl << endl
		<< gunInventory.back() << " is the last gun in the inventory."
		<< endl;

	_getch();
	return 0;
}