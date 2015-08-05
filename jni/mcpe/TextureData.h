#pragma once

#include <string>
#include <vector>

class ImageData {
public:
	int width, height;
	char* pixels;
	int format;
	int mipmap;
};

class TextureData : public ImageData {
	bool bilinear;
	int id;
	std::vector<ImageData> mipmaps;
};