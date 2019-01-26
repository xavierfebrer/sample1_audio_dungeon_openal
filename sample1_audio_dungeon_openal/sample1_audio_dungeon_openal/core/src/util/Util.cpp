#include "../../include/Util.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "../../../core/include/stb_image.h"
#endif

const double Util::PI_NUM = 3.1415927;
const double Util::radiansToDegrees = 180.0 / Util::PI_NUM;
const double Util::radDeg = Util::radiansToDegrees;
const double Util::degreesToRadians = Util::PI_NUM / 180.0;
const double Util::degRad = Util::degreesToRadians;
bool Util::initRandom = false;

int Util::toRadians(int degrees) {
	return degrees * degreesToRadians;
}

float Util::toRadians(float degrees) {
	return degrees * degreesToRadians;
}

double Util::toRadians(double degrees) {
	return degrees * degreesToRadians;
}

int Util::toDegrees(int radians) {
	return radians * radiansToDegrees;
}

float Util::toDegrees(float radians) {
	return radians * radiansToDegrees;
}

double Util::toDegrees(double radians) {
	return radians * radiansToDegrees;
}

short Util::minMax(short value, short min, short max) {
	return std::max(min, std::min(max, value));
}

int Util::minMax(int value, int min, int max) {
	return std::max(min, std::min(max, value));
}

float Util::minMax(float value, float min, float max) {
	return std::max(min, std::min(max, value));
}

double Util::minMax(double value, double min, double max) {
	return std::max(min, std::min(max, value));
}

template<typename T>
bool Util::hasMatrixFormatSize(std::vector<std::vector<T>> const & list, bool emptyAllowed) {
	int initSize = list.size();
	if (!emptyAllowed && initSize == 0) {
		return false;
	}
	for (size_t i = 0; i < list.size(); i++) {
		if (initSize != list[i].size()) {
			return false;
		}
	}
	return true;
}

bool Util::equals(std::string const & str1, std::string const & str2) {
	return str1.compare(str2) == 0;
}

std::string Util::readFileStr(std::string const & filename) {
	std::ifstream ifs(filename, std::ifstream::in);
	if (ifs) {
		ifs.seekg(0, std::ios::end);
		size_t len = ifs.tellg();
		ifs.seekg(0);
		std::string contents(len + 1, '\0');
		ifs.read(&contents[0], len);
		return contents;
	}
	return "";
}

int Util::randInt(int min, int max) {
	if (!initRandom) {
		initRandom = true;
		srand(time(NULL));
	}
	return rand() % (max + 1) + min;
}

double Util::random(double min, double max) {
	double lower_bound = min < max ? min : max;
	double upper_bound = max < min ? min : max;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(lower_bound, upper_bound);
	return dis(gen);
}

double Util::random() {
	return random(0, 1);
}

bool Util::loadFile(const std::string & path, std::string & result) {
	// We create the file object, saying I want to read it
	std::fstream file(path.c_str(), std::fstream::in) ;

	// We verify if the file was successfully opened
	if(file.is_open())
	{
		// We use the standard getline function to read the file into
		// a std::string, stoping only at "\0"
		std::getline(file, result, '\0') ;

		// We return the success of the operation
		return ! file.bad() ;
	}

	// The file was not successfully opened, so returning false
	return false ;
}

void Util::util_stbi_set_flip_vertically_on_load(bool flipOnLoad) {
	stbi_set_flip_vertically_on_load(flipOnLoad);
}

unsigned char * Util::util_stbi_load(char const * filename, int * x, int * y, int * comp, int req_comp) {
	return stbi_load(filename, x, y, comp, req_comp);
}

void Util::util_stbi_image_free(void *retval_from_stbi_load) {
	return stbi_image_free(retval_from_stbi_load);
}
