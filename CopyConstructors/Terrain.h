#pragma once
#include <iostream>

using namespace std;

class CTerrain
{
public:
	CTerrain() {};
	~CTerrain() {};

	CTerrain(const CTerrain &T)
	{
		cout << "\n Copy Constructor";
	}

	CTerrain& operator =(const CTerrain &T)
	{
		cout << "\n Assignment Operator";
		return *this;
	}

};