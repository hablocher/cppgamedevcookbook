#include "CEnemy.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "vld.h"

using namespace std;

int main() {
	CEnemy* pEnemy = new CEnemy(10, 100, "DrEvil", "GOLD");

	int iAge;
	int iHealth;
	string sName;
	string sArmour;

	iAge = pEnemy->GetAge();
	iHealth = pEnemy->TotalHealth();
	sArmour = pEnemy->GetArmourName();
	sName = pEnemy->GetName();

	cout << "Name of the enemy is : " << sName << endl;
	cout << "Name of " << sName << "'s armour is : " << sArmour << endl;
	cout << "Health of " << sName << " is : " << iHealth << endl;
	cout << sName << "'s age is: " << iAge;

	delete pEnemy;
	_getch();
}