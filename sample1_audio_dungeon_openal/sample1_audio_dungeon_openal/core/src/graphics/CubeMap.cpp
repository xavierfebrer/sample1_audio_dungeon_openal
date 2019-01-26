#include "../../include/CubeMap.h"

CubeMap::CubeMap(std::vector<std::string> faces,
	GLint location,
	GLint tMinFilter, GLint tMaxFilter,
	GLint tWrapS, GLint tWrapT, GLint tWrapR,
	GLint level, GLenum type, bool flipOnLoad)
	: faces(faces), location(location),
	tMinFilter(tMinFilter), tMaxFilter(tMaxFilter),
	tWrapS(tWrapS), tWrapT(tWrapT), tWrapR(tWrapR),
	level(level), type(type),
	flipOnLoad(flipOnLoad),
	initialized(false) {
}

CubeMap::~CubeMap() {
}

bool CubeMap::init() {
	if (!initialized) {
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_CUBE_MAP, id);

		for (unsigned int i = 0; i < faces.size(); i++) {
			Util::util_stbi_set_flip_vertically_on_load(flipOnLoad);
			std::string face = faces[i];
			widths.push_back(0);
			int* width = &widths[i];
			heights.push_back(0);
			int* height = &heights[i];
			nrChannelList.push_back(0);
			int* nrChannels = &nrChannelList[i];
			data = Util::util_stbi_load(std::string(face).c_str(), width, height, nrChannels, 0);

			GLenum format;
			if (nrChannelList[i] == 1) {
				format = GL_RED;
			} else if (nrChannelList[i] == 3) {
				format = GL_RGB;
			} else if (nrChannelList[i] == 4) {
				format = GL_RGBA;
			}

			if (data) {
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, level, format, *width, *height, 0, format, type, data);
			} else {
				std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
			}
			Util::util_stbi_image_free(data);
		}

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, tMinFilter);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, tMaxFilter);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, tWrapS);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, tWrapT);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, tWrapR);

		initialized = true;
	}
	return initialized;
}

bool CubeMap::isInitialized() {
	return initialized;
}

void CubeMap::activeBindTextureCubeMap() {
	glActiveTexture(GL_TEXTURE0 + location);
	glBindTexture(GL_TEXTURE_CUBE_MAP, id);
}
