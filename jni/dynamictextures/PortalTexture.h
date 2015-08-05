#pragma once

#include "mcpe/TickingTexture.h"
#include "mcpe/TextureData.h"

class PortalTexture : public TickingTexture {
public:
	int currentFrame;
	int frameCount;
	int pixelCount;
	char* image;

	PortalTexture(const TextureData&);
	virtual void tick();
};