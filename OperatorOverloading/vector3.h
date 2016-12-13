#ifndef _VECTOR3_H
#define _VECTOR3_H

#include <cmath>

class CVector3
{
public:
	// Public representation: Not many options here.
	float x;
	float y;
	float z;

	CVector3();
	CVector3(const CVector3& _kr);
	CVector3(float _fx, float _fy, float _fz);

	// Assignment operator
	CVector3& operator =(const CVector3& _kr);

	// Relational operators
	bool operator ==(const CVector3& _kr) const;
	bool operator !=(const CVector3& _kr) const;

	// Vector operations
	void Zero();

	CVector3 operator -() const;
	CVector3 operator +(const CVector3& _kr) const;
	CVector3 operator -(const CVector3& _kr) const;

	// Multiplication and division by scalar
	CVector3 operator *(float _f) const;
	CVector3 operator /(float _f) const;

	// Combined assignment operators to conform to C notation convention
	CVector3& operator +=(const CVector3& _kr);
	CVector3& operator -=(const CVector3& _kr);
	CVector3& operator *=(float _f);
	CVector3& operator /=(float _f);

	// Normalize the vector
	void Normalize();

	//Vector dot product
	// We overload the standard multiplication symbol to do this
	float operator *(const CVector3& _kr) const;

	// Static member functions

	// Compute the magnitude of a vector
	static inline float Magnitude(const CVector3& _kr)
	{
		return (sqrt(_kr.x * _kr.x + _kr.y * _kr.y + _kr.z * _kr.z));
	}

	// Compute the cross product of two vectors
	static inline CVector3 CrossProduct(const CVector3& _krA, const CVector3& _krB)
	{
		return
			(
				CVector3(	_krA.y * _krB.z - _krA.z * _krB.y,
							_krA.z * _krB.x - _krA.x * _krB.z,
							_krA.x * _krB.y - _krA.y * _krB.x)
				);
	}


	// Compute the distance between two points
	static inline float Distance(const CVector3& _krA, const CVector3& _krB)
	{
		float fdx = _krA.x - _krB.x;
		float fdy = _krA.y - _krB.y;
		float fdz = _krA.z - _krB.z;

		return sqrt(fdx * fdx + fdy * fdy + fdz * fdz);
	}

};

// Scalar on the left multiplication, for symmetry
inline CVector3 operator *(float _f, const CVector3& _kr)
{
	return (CVector3(_f * _kr.x, _f * _kr.y, _f * _kr.z));
}


#endif // !_VECTOR3_H

