#include "PortalTexture.h"
#include "mcpe/TextureData.h"
#include "mcpe/Tile.h"
#include <memory>

PortalTexture::PortalTexture(const TextureData& data) :
	// Tile 87 is Netherrack, so that's the texture that will display this animation
	TickingTexture(Tile::tiles[87]->tex, 1) {

	// width * height pixels, 4 bytes per pixel (for RGBA data)
	pixelCount = data.width * data.height * 4;
	image = new char[pixelCount];
	// copy the image into a permanent pixel buffer in PortalTexture
	memcpy(image, data.pixels, pixelCount);
	frameCount = data.height / 16;
	currentFrame = 0;
}

void PortalTexture::tick() {
	// copy the next frame into the current frame buffer
	memcpy(frameBuffer, image + (currentFrame << 10), 1024);
	currentFrame++;
	// if we run out of frames to diplay, restart to frame 0
	if(currentFrame >= frameCount) currentFrame = 0;
}