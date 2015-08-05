#pragma once

#include "TextureUVCoordinateSet.h"
class Textures;

class TickingTexture {
public:

	TextureUVCoordinateSet atlasTemplate;
	int horizontalFrames;
	unsigned char* frameBuffer;
	int pixelCount;

	TickingTexture(const TextureUVCoordinateSet&, int);
	virtual ~TickingTexture();

	virtual void tick() = 0;
	virtual void bindTexture(Textures*);
};