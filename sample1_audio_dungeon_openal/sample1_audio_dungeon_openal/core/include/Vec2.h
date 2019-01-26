#pragma once

//INCLUDES
#include <math.h>
#include <string>

//Vec2 CLASS
template<typename T = double>
class Vec2{
public:
	//MEMBERS
	T x;
	T y;

	//CONSTRUCTORS
	Vec2(void);
	Vec2(T xValue, T yValue);
	Vec2(const Vec2 & v);
	Vec2(const Vec2 * v);

	//DECONSTRUCTOR
	~Vec2(void);

	//METHODS
	void Set(T xValue, T yValue);

	T Length() const;
	T LengthSquared() const;
	T Distance(const Vec2 & v) const;
	T DistanceSquared(const Vec2 & v) const;
	T Dot(const Vec2 & v) const;
	T Cross(const Vec2 & v) const;

	Vec2 & Normal();
	Vec2 & Normalize();

	//ASSINGMENT AND EQUALITY OPERATIONS
	inline Vec2 & operator=(const Vec2 & v) { x = v.x; y = v.y; return *this; }
	inline Vec2 & operator=(const T & f) { x = f; y = f; return *this; }
	inline Vec2 & operator-(void) { x = -x; y = -y; return *this; }
	inline bool operator==(const Vec2 & v) const { return (x == v.x) && (y == v.y); }
	inline bool operator!=(const Vec2 & v) const { return (x != v.x) || (y != v.y); }

	//Vec2 TO Vec2 OPERATIONS
	inline const Vec2 operator+(const Vec2 & v) const { return Vec2(x + v.x, y + v.y); }
	inline const Vec2 operator-(const Vec2 & v) const { return Vec2(x - v.x, y - v.y); }
	inline const Vec2 operator*(const Vec2 & v) const { return Vec2(x * v.x, y * v.y); }
	inline const Vec2 operator/(const Vec2 & v) const { return Vec2(x / v.x, y / v.y); }

	//Vec2 TO THIS OPERATIONS
	inline Vec2 & operator+=(const Vec2 & v) { x += v.x; y += v.y; return *this; }
	inline Vec2 & operator-=(const Vec2 & v) { x -= v.x; y -= v.y; return *this; }
	inline Vec2 & operator*=(const Vec2 & v) { x *= v.x; y *= v.y; return *this; }
	inline Vec2 & operator/=(const Vec2 & v) { x /= v.x; y /= v.y; return *this; }

	//SCALER TO Vec2 OPERATIONS
	inline const Vec2 operator+(T v) const { return Vec2(x + v, y + v); }
	inline const Vec2 operator-(T v) const { return Vec2(x - v, y - v); }
	inline const Vec2 operator*(T v) const { return Vec2(x * v, y * v); }
	inline const Vec2 operator/(T v) const { return Vec2(x / v, y / v); }

	//SCALER TO THIS OPERATIONS
	inline Vec2 & operator+=(T v) { x += v; y += v; return *this; }
	inline Vec2 & operator-=(T v) { x -= v; y -= v; return *this; }
	inline Vec2 & operator*=(T v) { x *= v; y *= v; return *this; }
	inline Vec2 & operator/=(T v) { x /= v; y /= v; return *this; }
};






//CONSTRUCTORS
template<typename T>
Vec2<T>::Vec2(void) { }
template<typename T>
Vec2<T>::Vec2(T xValue, T yValue) : x(xValue), y(yValue) { }
template<typename T>
Vec2<T>::Vec2(const Vec2 & v) : x(v.x), y(v.y) { }
template<typename T>
Vec2<T>::Vec2(const Vec2 * v) : x(v->x), y(v->y) { }

//DECONSTRUCTOR
template<typename T>
Vec2<T>::~Vec2(void) { }

//METHODS
template<typename T>
void Vec2<T>::Set(T xValue, T yValue) { x = xValue; y = yValue; }

template<typename T>
T Vec2<T>::Length() const { return sqrt(x * x + y * y); }
template<typename T>
T Vec2<T>::LengthSquared() const { return x * x + y * y; }
template<typename T>
T Vec2<T>::Distance(const Vec2 & v) const { return sqrt(((x - v.x) * (x -     v.x)) + ((y - v.y) * (y - v.y))); }
template<typename T>
T Vec2<T>::DistanceSquared(const Vec2 & v) const { return ((x - v.x) * (x -     v.x)) + ((y - v.y) * (y - v.y)); }
template<typename T>
T Vec2<T>::Dot(const Vec2 & v) const { return x * v.x + y * v.y; }
template<typename T>
T Vec2<T>::Cross(const Vec2 & v) const { return x * v.y + y * v.x; }

template<typename T>
Vec2<T> & Vec2<T>::Normal() { Set(-y, x); return *this; }
template<typename T>
Vec2<T> & Vec2<T>::Normalize(){
	if(Length() != 0){
		T length = LengthSquared();
		x /= length; y /= length;
		return *this;
	}
	x = y = 0;
	return *this;
}
