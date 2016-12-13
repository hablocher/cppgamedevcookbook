#ifndef _CENEMY_H
#define _CENEMY_H

#include <string>
using namespace std;

class CEnemy
{
public:
	string GetName() const;
	int GetAge() const;
	string GetArmourName() const;
	int TotalHealth() const;

	//ctors
	CEnemy(int, int, string, string);

	//dtors
	~CEnemy();

private:
	int m_iAge;
	int m_iHealth;
	string m_sName;
	string m_sArmour;

};
#endif