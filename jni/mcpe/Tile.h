#include "TextureUVCoordinateSet.h"

class Tile {
public:
	char fill[36];
	TextureUVCoordinateSet tex;

	static Tile* tiles[256];
};