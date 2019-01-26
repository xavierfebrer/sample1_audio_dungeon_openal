#pragma once

#include "Util.h"

class TextureRegion2D {
public:
	/*const Texture2D * const texture2D;*/
	Rect<> region;

	TextureRegion2D(/*const Texture2D * const texture2D, */const Rect<> & region);
	~TextureRegion2D();
};