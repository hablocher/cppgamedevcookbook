#include "CSpeed.h"

CSpeed::CSpeed()
{

}

CSpeed::~CSpeed()
{

}

int CSpeed::AddSpeed(int x, int y, int z)
{
	return x + y + z;
}

int CSpeed::AddSpeed(int x, int y)
{
	return x + y;
}

float CSpeed::AddSpeed(float x, float y)
{
	return x + y;
}