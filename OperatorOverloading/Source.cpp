#include "vector3.h"
#include <conio.h>
#include "vld.h"

int main()
{
	// Vector tests:

	// Create two vectors
	CVector3 a(1.0f, 2.0f, 3.0f);
	CVector3 b(1.0f, 2.0f, 3.0f);

	CVector3 c;

	// Zero Vector
	c.Zero();

	// Addition
	CVector3 d = a + b;

	// Subtraction
	CVector3 e = a - b;

	// Scalar Multiplication
	CVector3 f1 = a * 10;

	// Scalar Multiplication
	CVector3 f2 = 10 * a;

	// Scalar Division
	CVector3 g = a / 10;

	// Unary minus
	CVector3 h = -a;

	// Relational Operators
	bool bAEqualsB = (a == b);
	bool bANotEqualsB = (a != b);

	// Combined operations +=
	c = a;
	c += a;

	// Combined operations /=
	c = a;
	c /= 10;

	// Combined operations *=
	c = a;
	c *= 10;

	// Normalization
	c.Normalize();

	// Dot Product
	float fADotB = a * b;

	// Magnitude
	float fMag1 = CVector3::Magnitude(a);
	float fMag2 = CVector3::Magnitude(c);

	// Cross Product
	CVector3 crossProduct = CVector3::CrossProduct(a, c);

	// Distance
	float distance = CVector3::Distance(a, c);

	_getch();

	return 0;

}