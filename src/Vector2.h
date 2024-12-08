#ifndef VECTOR2_H
#define VECTOR2_H

namespace Gkit{

class Vector2{
public:
	// Value math
	Vector2(long double x, long double y);
	Vector2 operator +(const Vector2& v) const;
	Vector2 operator +=(const Vector2& v);
	Vector2 operator -(const Vector2& v) const;
	Vector2 operator -=(const Vector2& v);
	int operator *(const Vector2& v) const;

	// Bool math
	bool operator ==(const Vector2& v) const;
	bool operator !=(const Vector2& v) const;
	bool operator < (const Vector2& v) const;
	bool operator <=(const Vector2& v) const;
	bool operator > (const Vector2& v) const;
	bool operator >=(const Vector2& v) const;

	// 操作函数
	inline long double length() const {
		return sqrt(x * x + y * y);
	}
public:
	long double x, y = 0.f;
};// class Vector2

}// namespace Gkit

#endif