#include <iostream>
#include <string>
#include "CEnemy.h"

using namespace std;

CEnemy::CEnemy(int Age, int Health, string Armour, string Name)
{
	m_iAge = Age;
	m_iHealth = Health;
	m_sArmour = Armour;
	m_sName = Name;
}

int CEnemy::GetAge() const
{
	return m_iAge;
}

int CEnemy::TotalHealth() const
{
	return m_iHealth;
}

string CEnemy::GetArmourName() const
{
	return m_sArmour;
}

string CEnemy::GetName() const
{
	return m_sName;
}

CEnemy::~CEnemy() {

}