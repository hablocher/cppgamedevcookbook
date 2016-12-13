#ifndef _DRAGON_H
#define _DRAGON_H

#include "Enemy.h"
#include <iostream>

using namespace std;

class CDragon : public CEnemy {
public:
	CDragon(int m_iHealth, int m_iArmourValue) : CEnemy(m_iHealth, m_iArmourValue)
	{

	}
	int TotalHP()
	{
		cout << "Dragon's ";
		return m_iHealth * 2 + 3 * m_iArmourValue;
	}
};

#endif // !_DRAGON_H
