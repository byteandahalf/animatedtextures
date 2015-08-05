#pragma once

#include <string>
class TickingTextures;
class TextureData;

class Textures {
public:
	void addTickingTexture(TickingTexture*);
	void loadDynamicTextures();
	const TextureData& getTextureData(const std::string&);
};