#pragma once

template<typename T = double>
class Rect {
public:
	T x, y, w, h;

	Rect(T x = 0, T y = 0, T w = 1, T h = 1);
	virtual ~Rect();

	const T getX();
	void setX(T x);
	void incX(T deltaX);
	const T getY();
	void setY(T y);
	void incY(T deltaY);
	void setPos(T x, T y);
	void incPos(T deltaX, T deltaY);
	const T getWidth();
	void setWidth(T width);
	void incWidth(T deltaWidth);
	const T getHeight();
	void setHeight(T height);
	void incHeight(T deltaHeight);
	void setSize(T width, T height);
	void set(T x, T y, T width, T height);
};




template<typename T>
Rect<T>::Rect(T x, T y, T w, T h) : x(x), y(y), w(w), h(h) {
}

template<typename T>
Rect<T>::~Rect() {
}

template<typename T>
const T Rect<T>::getX() {
	return this->x;
}

template<typename T>
void Rect<T>::setX(T x) {
	this->x = x;
}

template<typename T>
void Rect<T>::incX(T deltaX) {
	setX(getX() + deltaX);
}

template<typename T>
const T Rect<T>::getY() {
	return this->y;
}

template<typename T>
void Rect<T>::setY(T y) {
	this->y = y;
}

template<typename T>
void Rect<T>::incY(T deltaY) {
	setY(getY() + deltaY);
}

template<typename T>
void Rect<T>::setPos(T x, T y) {
	setX(x);
	setY(y);
}

template<typename T>
void Rect<T>::incPos(T deltaX, T deltaY) {
	setPos(getX() + deltaX, getY() + deltaY);
}

template<typename T>
const T Rect<T>::getWidth() {
	return this->w;
}

template<typename T>
void Rect<T>::setWidth(T width) {
	this->w = width;
}

template<typename T>
void Rect<T>::incWidth(T deltaWidth) {
	setWidth(getWidth() + deltaWidth);
}

template<typename T>
const T Rect<T>::getHeight() {
	return this->h;
}

template<typename T>
void Rect<T>::setHeight(T height) {
	this->h = height;
}

template<typename T>
void Rect<T>::incHeight(T deltaHeight) {
	setHeight(getHeight() + deltaHeight);
}

template<typename T>
void Rect<T>::setSize(T width, T height) {
	setWidth(width);
	setHeight(height);
}

template<typename T>
void Rect<T>::set(T x, T y, T width, T height) {
	setPos(x, y);
	setPos(width, height);
}
