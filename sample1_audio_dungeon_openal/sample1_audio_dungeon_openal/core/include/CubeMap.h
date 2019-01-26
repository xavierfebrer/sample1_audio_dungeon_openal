#pragma once

#include <glad/glad.h>

#include "Util.h"

class CubeMap {
public:
	std::vector<std::string> faces;
	std::vector<int> widths, heights, nrChannelList;
	unsigned char *data;
	unsigned int id;
	GLint location;

	CubeMap(std::vector<std::string> faces,
		GLint location,
		GLint tMinFilter = GL_NEAREST, GLint tMaxFilter = GL_NEAREST,
		GLint tWrapS = GL_REPEAT, GLint tWrapT = GL_REPEAT, GLint tWrapR = GL_REPEAT,
		GLint level = 0, GLenum type = GL_UNSIGNED_BYTE, bool flipOnLoad = false);
	virtual ~CubeMap();

	virtual bool init();
	virtual bool isInitialized();
	virtual void activeBindTextureCubeMap();
private:
	GLint tWrapS, tWrapT, tWrapR;
	GLint tMinFilter, tMaxFilter;
	GLint level;
	GLenum type;
	bool flipOnLoad;
	bool initialized;
};