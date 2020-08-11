#pragma once

#include "GameObject.h"

/* FreeType 라이브러리 헤더 */
#include "font/ft2build.h"
#include FT_FREETYPE_H

/* FreeType 라이브러리 추가 */
#pragma comment (lib, "font/release/freetype.lib")

class Text : public GameObject {
private:
	FT_Library library;
	FT_Face face;
	wstring text;
	unsigned int color;

public:
	Text(wstring text, int size, unsigned int color, float px, float py);
	~Text();

	void start();
	void draw();

	void setSize(int size);
	void setSize(int xSize, int ySize);
	void setColor(unsigned int color);
	void setColor(int r, int g, int b);
	void setText(wstring text);
};