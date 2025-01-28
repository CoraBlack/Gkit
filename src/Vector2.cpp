#include <math.h>
#include "Vector2.h"

Gkit::Vector2::Vector2(long double x, long double y) {
	this->x = x;
	this->y = y;
	return;
}

Gkit::Vector2 Gkit::Vector2::operator +(const Vector2& v) const {
	return Vector2(x + v.x, y + v.y);
}

Gkit::Vector2 Gkit::Vector2::operator +(const long double& d) const {
	return Vector2(this->x + d, this->y + d);
}

void Gkit::Vector2::operator += (const Vector2& v) {
	x += v.x; 
	y += v.y;
	return;
}

void Gkit::Vector2::operator += (const long double& d) {
	x += d; 
	y += d;
	return;
}

Gkit::Vector2 Gkit::Vector2::operator - (const Vector2& v) const {
	return Vector2(x - v.x, y - v.y);
}

Gkit::Vector2 Gkit::Vector2::operator -= (const Vector2& v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

int Gkit::Vector2::operator * (const Vector2& v) const {
	return (this->x * v.x + this->y * v.y);
}



bool Gkit::Vector2::operator==(const Vector2& v) const {
	if (this->x == v.x && this->y == v.y) {
		return true;
	} else {
		return false;
	}
}

bool Gkit::Vector2::operator!=(const Vector2& v) const{
	if (this->x != v.x && this->y != v.y) {
		return true;
	} else {
		return false;
	}
}

bool Gkit::Vector2::operator< (const Vector2& v) const{
	if (sqrt(x * x + y * y) < sqrt(v.x * v.x + v.y * v.y)) {
		return true;
	} else {
		return false;
	}
}

bool Gkit::Vector2::operator<=(const Vector2& v) const{
	if (sqrt(x * x + y * y) <= sqrt(v.x * v.x + v.y * v.y)) {
		return true;
	}
	else {
		return false;
	}
}

bool Gkit::Vector2::operator> (const Vector2& v) const{
	if (sqrt(x * x + y * y) > sqrt(v.x * v.x + v.y * v.y)) {
		return true;
	}
	else {
		return false;
	}
}

bool Gkit::Vector2::operator>=(const Vector2& v) const{
	if (sqrt(x * x + y * y) >= sqrt(v.x * v.x + v.y * v.y)) {
		return true;
	}
	else {
		return false;
	}
}

