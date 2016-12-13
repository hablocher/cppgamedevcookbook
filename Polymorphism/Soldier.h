#ifndef _SOLDIER_H
#define _SOLDIER_H

#include "Enemy.h"
#include <iostream>

using namespace std;

class CSoldier : public CEnemy {
public:
	CSoldier(int m_iHealth, int m_iArmourValue) : CEnemy(m_iHealth, m_iArmourValue) {}
	int TotalHP()
	{
		cout << "Soldier's";
		return m_iHealth + m_iArmourValue;
	}
};

#endif // !_SOLDIER_H
