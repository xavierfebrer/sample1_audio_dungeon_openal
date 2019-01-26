#pragma once


#include <math.h>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <vector>
#include "Vec2.h"
#include "Rect.h"
#include "PointerInfo.h"
#include "KeyInfo.h"
#include "PointerEventInfo.h"

class Util {
public:
	static const double PI_NUM;

	/** multiply by this to convert from radians to degrees */
	static const double radiansToDegrees;
	static const double radDeg;
	/** multiply by this to convert from degrees to radians */
	static const double degreesToRadians;
	static const double degRad;

	static int toRadians(int degrees);
	static float toRadians(float degrees);
	static double toRadians(double degrees);
	static int toDegrees(int radians);
	static float toDegrees(float radians);
	static double toDegrees(double radians);

	static short minMax(short value, short min, short max);
	static int minMax(int value, int min, int max);
	static float minMax(float value, float min, float max);
	static double minMax(double value, double min, double max);

	template<typename T>
	static bool hasMatrixFormatSize(std::vector<std::vector<T>> const & list, bool emptyAllowed = true);

	static bool equals(const std::string & str1, const std::string & str2);

	static std::string readFileStr(std::string const & filename);

	static int randInt(int min, int max);
	static double random(double min, double max);
	static double random();
	static bool loadFile(const std::string & path, std::string & result);

	template<typename B, typename O>
	static B* getInstanceOf(const O & other);
	template<typename B, typename O>
	static bool instanceOf(const O & other);

	static void util_stbi_set_flip_vertically_on_load(bool flipOnLoad);
	static unsigned char *util_stbi_load(char const *filename, int *x, int *y, int *comp, int req_comp);
	static void util_stbi_image_free(void *retval_from_stbi_load);
private:
	static bool initRandom;
};

/*template<typename T>
inline void Util::clearVecDeletePtrs(std::vector<T> & list) {
for (std::vector<T>::iterator it = list.begin() ; it != list.end(); ++it) {
delete (*it);
} 
list.clear();
}*/

template<typename B, typename O>
inline B * Util::getInstanceOf(const O & other) {
	if (B * v = dynamic_cast<B*>(other)) {
		return v;
	}
	return nullptr;
}

template<typename B, typename O>
inline bool Util::instanceOf(const O & other) {
	if (B * v = dynamic_cast<B*>(other)) {
		return true;
	}
	return false;
}