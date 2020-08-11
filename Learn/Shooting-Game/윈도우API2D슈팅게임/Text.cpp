#include "framework.h"

Text::Text(wstring text, int size, unsigned int color, float px, float py)
	: GameObject("UI", "Text", true, px, py) {

	/* FreeType 라이브러리 초기화 */
	this->library = nullptr;
	if (FT_Init_FreeType(&(this->library))) {
		cout << "[ERROR] FreeType 라이브러리 초기화 실패" << endl;
		return;
	}

	/* 글꼴 파일 읽기 */
	this->face = nullptr;
	if (FT_New_Face(this->library, "asset/ui/koverwatch.ttf", 0, &(this->face))) {
		cout << "[ERROR] 글꼴 파일 읽어오기 실패" << endl;
		return;
	}

	this->text = text;
	this->color = color;

	/* 글꼴 옵션 지정하기 */
	FT_Set_Pixel_Sizes(face, size, size); // 글꼴 크기 옵션
}

Text::~Text() {
	/* FreType 라이브러리 반환 */
	FT_Done_Face(face);
	FT_Done_FreeType(library);
}

void Text::start() {

}

void Text::draw() {
	int fx = (int)getPx(), fy = (int)getPy();

	/* 문자열 크기만큼 반복하기 */
	for (int i = 0; i < text.length(); i++) {
		/* 문자에 해당되는 글꼴(일부) 읽어오기 */
		int index = FT_Get_Char_Index(face, text[i]);			// 1. 해당 문자 위치(index) 찾기
		FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);			// 2. 찾은 위치에서 글꼴 모양 읽어오기
		FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);	// 3. 읽어온 글꼴 모양을 이미지로 변환하기

		/* 변환된 이미지 정보 생성하기 */
		unsigned char * buffer = face->glyph->bitmap.buffer;	// - 이미지 칠 정보
		int width = face->glyph->bitmap.width;					// - 이미지의 가로크기
		int height = face->glyph->bitmap.rows;					// - 이미지의 세로크기

		/* 생성한 이미지 정보를이용해 이미지를 출력하기 */
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				unsigned char value = buffer[y * width + x];
				if (value) {
					// 0x00ffffff
					// 0000 0000 1111 1111 1111 1111 1111 1111
					unsigned int color = value << 24 | this->color;
					setPixel(x + fx, y + fy, color);
				}
			}
		}

		fx += face->glyph->advance.x / 64;
		fy += face->glyph->advance.y / 64;
	}
}

void Text::setSize(int size) {
	FT_Set_Pixel_Sizes(face, size, size);
}

void Text::setSize(int xSize, int ySize) {
	FT_Set_Pixel_Sizes(face, xSize, ySize);
}

void Text::setColor(unsigned int color) {
	this->color = color;
}

void Text::setColor(int r, int g, int b) {
	this->color = RGB(r, g, b); // 수정필요 32비트 RGB로
}

void Text::setText(wstring text) {
	this->text = text;
}