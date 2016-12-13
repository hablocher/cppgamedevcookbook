#include "vector3.h"

// Default constructor leaves vector in a indetermined state
CVector3::CVector3()
{

}

// Copy constructor
CVector3::CVector3(const CVector3& _kr)
	: x(_kr.x)
	, y(_kr.y)
	, z(_kr.z)
{

}

// Construct given three values
CVector3::CVector3(float _fx, float _fy, float _fz)
	: x(_fx)
	, y(_fy)
	, z(_fz)
{

}

// Assigment operator, we adhere to C convention and return reference to the value
CVector3& CVector3::operator=(const CVector3& _kr)
{
	x = _kr.x;
	y = _kr.y;
	z = _kr.z;
	return (*this);
}

// Equality operator
bool CVector3::operator==(const CVector3& _kr) const
{
	return (x == _kr.x && y == _kr.y && z == _kr.z);
}

// Inequality operator
bool CVector3::operator!=(const CVector3& _kr) const
{
	return (x != _kr.x || y != _kr.y || z != _kr.z);
}

// Set the vector to zero
void CVector3::Zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

// Unary minus returns the negative of the vector
CVector3 CVector3::operator-() const
{
	return (CVector3(-x, -y, -z));
}

// Binary +, add vectors
CVector3 CVector3::operator+(const CVector3& _kr) const
{
	return (CVector3(x + _kr.x, y + _kr.y, z + _kr.z));
}

// Binary -, subtract vectors
CVector3 CVector3::operator-(const CVector3& _kr) const
{
	return (CVector3(x - _kr.x, y - _kr.y, z - _kr.z));
}

// Multiplication by scalar
CVector3 CVector3::operator*(float _f) const
{
	return (CVector3(x * _f, y * _f, z * _f));
}

// Division by scalar
// Precondition: _f must not be zero
CVector3 CVector3::operator/(float _f) const
{
	// Warning: no check for divide by zero here
	float fOneOverA = 1.0f / _f;
	return (CVector3(x * fOneOverA, y * fOneOverA, z * fOneOverA));
}

CVector3& CVector3::operator+=(const CVector3& _kr)
{
	x += _kr.x;
	y += _kr.y;
	z += _kr.z;

	return (*this);
}

CVector3& CVector3::operator-=(const CVector3& _kr)
{
	x -= _kr.x;
	y -= _kr.y;
	z -= _kr.z;

	return (*this);
}

CVector3& CVector3::operator*=(float _f)
{
	x *= _f;
	y *= _f;
	z *= _f;

	return (*this);
}

CVector3& CVector3::operator/=(float _f)
{
	float fOneOverA = 1.0f / _f;

	x *= fOneOverA;
	y *= fOneOverA;
	z *= fOneOverA;

	return (*this);
}

void CVector3::Normalize()
{
	float fMagSq = x * x + y * y + z * z;

	if (fMagSq > 0.0f)
	{
		// Check for divide-by-zero
		float fOneOverMag = 1.0f / sqrt(fMagSq);

		x *= fOneOverMag;
		y *= fOneOverMag;
		z *= fOneOverMag;
	}
}

// Vector dor product
//   We overload the standard multiplication symbol to do this
float CVector3::operator*(const CVector3& _kr) const
{
	return (x * _kr.x + y * _kr.y + z * _kr.z);
}

