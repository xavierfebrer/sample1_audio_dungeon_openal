#include "../../include/Color.h"

const double Color::MIN_COLOR = 0;
const double Color::MAX_COLOR = 1;

Color::Color(double a, double r, double g, double b)
	: a(Util::minMax(a, Color::MIN_COLOR, Color::MAX_COLOR)),
	r(Util::minMax(r, Color::MIN_COLOR, Color::MAX_COLOR)),
	g(Util::minMax(g, Color::MIN_COLOR, Color::MAX_COLOR)),
	b(Util::minMax(b, Color::MIN_COLOR, Color::MAX_COLOR)){
}

Color::~Color() {
}

const double Color::getA() const {
	return a;
}

void Color::setA(const double a) {
	this->a = Util::minMax(a, Color::MIN_COLOR, Color::MAX_COLOR);
}

const double Color::getR() const {
	return r;
}

void Color::setR(const double r) {
	this->r = Util::minMax(r, Color::MIN_COLOR, Color::MAX_COLOR);
}

const double Color::getG() const {
	return g;
}

void Color::setG(const double g) {
	this->g = Util::minMax(g, Color::MIN_COLOR, Color::MAX_COLOR);
}

const double Color::getB() const {
	return b;
}

void Color::setB(const double b) {
	this->b = Util::minMax(b, Color::MIN_COLOR, Color::MAX_COLOR);
}

void Color::set(const double a, const double r, const double g, const double b) {
	setA(a);
	setR(r);
	setG(g);
	setB(b);
}
