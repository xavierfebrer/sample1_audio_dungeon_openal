#pragma once

#include <glad/glad.h>

#include "Util.h"

class Texture2D {
public:
	std::string completePath;
	int width, height, nrChannels;
	unsigned char *data;
	unsigned int id;
	GLint location;

	Texture2D(const std::string & completePath,
		GLint location,
		GLint tMinFilter = GL_NEAREST, GLint tMaxFilter = GL_NEAREST,
		GLint tWrapS = GL_REPEAT, GLint tWrapT = GL_REPEAT,
		GLint level = 0, GLenum type = GL_UNSIGNED_BYTE, bool flipOnLoad = false);
	virtual ~Texture2D();

	virtual bool init();
	virtual bool isInitialized();
	virtual void activeBindTexture();
private:
	GLint tWrapS, tWrapT;
	GLint tMinFilter, tMaxFilter;
	GLint level;
	GLenum type;
	bool flipOnLoad;
	bool initialized;
};