#ifndef _ENEMY_H
#define _ENEMY_H

#include <iostream>

using namespace std;

class CEnemy {
protected:
	int m_iHealth, m_iArmourValue;
public:
	CEnemy(int iHealth, int iArmourValue) : m_iHealth(iHealth), m_iArmourValue(iArmourValue) {}
	virtual int TotalHP(void) = 0;
	void PrintHealth()
	{
		cout << "Total health is " << this->TotalHP() << '\n';
	}
};

#endif // !_ENEMY_H

