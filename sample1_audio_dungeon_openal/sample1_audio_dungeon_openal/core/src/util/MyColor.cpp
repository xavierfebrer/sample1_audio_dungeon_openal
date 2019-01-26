#include "../../include/MyColor.h"

const double MyColor::MIN_COLOR = 0;
const double MyColor::MAX_COLOR = 1;

MyColor::MyColor(double a, double r, double g, double b)
	: a(Util::minMax(a, MyColor::MIN_COLOR, MyColor::MAX_COLOR)),
	r(Util::minMax(r, MyColor::MIN_COLOR, MyColor::MAX_COLOR)),
	g(Util::minMax(g, MyColor::MIN_COLOR, MyColor::MAX_COLOR)),
	b(Util::minMax(b, MyColor::MIN_COLOR, MyColor::MAX_COLOR)){
}

MyColor::~MyColor() {
}

const double MyColor::getA() const {
	return a;
}

void MyColor::setA(const double a) {
	this->a = Util::minMax(a, MyColor::MIN_COLOR, MyColor::MAX_COLOR);
}

const double MyColor::getR() const {
	return r;
}

void MyColor::setR(const double r) {
	this->r = Util::minMax(r, MyColor::MIN_COLOR, MyColor::MAX_COLOR);
}

const double MyColor::getG() const {
	return g;
}

void MyColor::setG(const double g) {
	this->g = Util::minMax(g, MyColor::MIN_COLOR, MyColor::MAX_COLOR);
}

const double MyColor::getB() const {
	return b;
}

void MyColor::setB(const double b) {
	this->b = Util::minMax(b, MyColor::MIN_COLOR, MyColor::MAX_COLOR);
}

void MyColor::set(const double a, const double r, const double g, const double b) {
	setA(a);
	setR(r);
	setG(g);
	setB(b);
}
