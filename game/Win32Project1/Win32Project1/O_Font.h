#pragma once

#include "Texture.h"
#include "SDL_ttf.h"



class O_Font : public Texture
{
private:
	TTF_Font* _font;
	SDL_Color _fontColor;

public:
	O_Font(const char* fontName, int fontSize);
	~O_Font();

	void SetText(const char* text, int x, int y);
};