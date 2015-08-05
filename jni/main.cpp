#include <jni.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <substrate.h>

#include "dynamictextures/PortalTexture.h"
#include "mcpe/TextureUVCoordinateSet.h"
#include "mcpe/Textures.h"


void (*_Textures$loadDynamicTextures)(Textures*);
void Textures$loadDynamicTextures(Textures* tex) {
	// add our new animated texture, uses portal.png from the mod assets
	tex->addTickingTexture(new PortalTexture(tex->getTextureData("portal.png")));
	_Textures$loadDynamicTextures(tex);
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Textures::loadDynamicTextures, (void*) &Textures$loadDynamicTextures, (void**) &_Textures$loadDynamicTextures);

	return JNI_VERSION_1_2;
}
