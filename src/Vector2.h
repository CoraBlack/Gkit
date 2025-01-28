#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>
#include <functional>	// include hash for template specialization and size_t for adaptation

namespace Gkit{

class Vector2{
public:
	// Value math
	Vector2(long double x, long double y);
	Vector2 operator + (const Vector2&     v) const;
	Vector2 operator + (const long double& d) const;
	void    operator +=(const Vector2& 	   v);
	void    operator +=(const long double& d);
	Vector2 operator - (const Vector2&     v) const;
	Vector2 operator -=(const Vector2&     v);
	int     operator * (const Vector2& v) const;

	// Bool math
	bool operator ==(const Vector2& v) const;
	bool operator !=(const Vector2& v) const;
	bool operator < (const Vector2& v) const;
	bool operator <=(const Vector2& v) const;
	bool operator > (const Vector2& v) const;
	bool operator >=(const Vector2& v) const;

	// Operation function
	inline long double length() const {
		return sqrt(x * x + y * y);
	}
public:
	long double x, y = 0.00;
};// class Vector2

}// namespace Gkit

// Add std:: Specialized version of hash
namespace std {
	template <>
	struct hash<Gkit::Vector2> {
		std::size_t operator()(const Gkit::Vector2& v) const {
			return std::hash<long double>()(v.x) ^ (std::hash<long double>()(v.y) << 1);
		}
	};
}


#endif