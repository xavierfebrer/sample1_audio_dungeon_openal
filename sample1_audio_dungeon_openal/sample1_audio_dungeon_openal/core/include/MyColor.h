#pragma once

#include "Util.h"

class MyColor {
private:
	double a, r, g, b;
public:
	static const double MIN_COLOR;
	static const double MAX_COLOR;

	MyColor(double a = MAX_COLOR, double r = MAX_COLOR, double g = MAX_COLOR, double b = MAX_COLOR);
	virtual ~MyColor();

	const double getA() const;
	void setA(const double a);
	const double getR() const;
	void setR(const double r);
	const double getG() const;
	void setG(const double g);
	const double getB() const;
	void setB(const double b);
	void set(const double a, const double r, const double g, const double b);
};
