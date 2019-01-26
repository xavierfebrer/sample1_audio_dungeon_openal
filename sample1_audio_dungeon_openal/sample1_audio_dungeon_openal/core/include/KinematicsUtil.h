#pragma once

#include "Util.h"

class KinematicsUtil {
public:
};
inline double dF(double iPos, double iVel, double acc, double time) {
	return iPos + iVel*time + 0.5*acc*(time*time);
}
/*inline double dFV(double iVel, double fVel, double time) {
return ((iVel + fVel)*0.5) * time;
}*/
inline double fVel(double iVel, double acc, double time) {
	return iVel + acc * time;
}
/*inline double fVelD(double iVel, double acc, double d) {
return sqrt((iVel * iVel) + 2*acc*d);
}*/