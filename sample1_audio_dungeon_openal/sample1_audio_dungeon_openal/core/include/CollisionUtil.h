#pragma once

#include "Util.h"

template<typename T = double>
class CollisionUtil {
private:
	CollisionUtil();
	virtual ~CollisionUtil();
public:
	static inline bool collision(T x1, T y1, T w1, T h1, T x2, T y2, T w2, T h2);
	static inline bool collision(T x1, T y1, T x2, T y2, T w2, T h2);
	static inline bool collision(const Vec2<T> &vec1, T w1, T h1, const Vec2<T> &vec2, T w2, T h2);
	static inline bool collision(const Rect<T>& rect1, const Rect<T>& rect2);
	static inline bool collision(const Vec2<T>& vec1, const Rect<T>& rect2);
	static inline bool collision(T x1, T y1, const Rect<T>& rect2);
};

template<typename T>
bool CollisionUtil<T>::collision(T x1, T y1, T w1, T h1, T x2, T y2, T w2, T h2) {
	return x1 <= x2 + w2 && x1 + w1 >= x2
		&& y1 <= y2 + h2 && y1 + h1 >= y2;
}

template<typename T>
bool CollisionUtil<T>::collision(T x1, T y1, T x2, T y2, T w2, T h2) {
	return x1 >= x2 && x1 <= x2 + w2
		&& y1 >= y2 && y1 <= y2 + h2;
}

template<typename T>
bool CollisionUtil<T>::collision(const Vec2<T>& vec1, T w1, T h1, const Vec2<T>& vec2, T w2, T h2) {
	return collision(vec1.x, vec1.y, w1, h1, vec2.x, vec2.y, w2, h2);
}

template<typename T>
bool CollisionUtil<T>::collision(const Rect<T>& rect1, const Rect<T>& rect2) {
	return collision(rect1.x, rect1.y, rect1.w, rect1.h, rect2.x, rect2.y, rect2.w, rect2.h);
}

template<typename T>
bool CollisionUtil<T>::collision(const Vec2<T>& vec1, const Rect<T>& rect2) {
	return collision(vec1.x, vec1.y, rect2.x, rect2.y, rect2.w, rect2.h);
}

template<typename T>
bool CollisionUtil<T>::collision(T x1, T y1, const Rect<T>& rect2) {
	return collision(x1, y1, rect2.x, rect2.y, rect2.w, rect2.h);
}