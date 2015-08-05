#pragma once

enum TextureFile {
	Tiles,
	Items
};

class TextureUVCoordinateSet {
public:
	float minU;
	float minV;
	float maxU;
	float maxV;
	int width;
	int height;
	int index;
	int file;
};