// dynamic allocation and polymorphism

#include <iostream>
#include <conio.h>
#include "vld.h"
#include "Enemy.h"
#include "Dragon.h"
#include "Soldier.h"

int main()
{
	CEnemy* pEnemy1 = new CDragon(100, 50);
	CEnemy* pEnemy2 = new CSoldier(100, 100);

	pEnemy1->PrintHealth();
	pEnemy2->PrintHealth();

	delete pEnemy1;
	delete pEnemy2;
	
	_getch();
	return 0;
}