#include "framework.h"

Text::Text(wstring text, int size, unsigned int color, float px, float py)
	: GameObject("UI", "Text", true, px, py) {

	/* FreeType ���̺귯�� �ʱ�ȭ */
	this->library = nullptr;
	if (FT_Init_FreeType(&(this->library))) {
		cout << "[ERROR] FreeType ���̺귯�� �ʱ�ȭ ����" << endl;
		return;
	}

	/* �۲� ���� �б� */
	this->face = nullptr;
	if (FT_New_Face(this->library, "asset/ui/koverwatch.ttf", 0, &(this->face))) {
		cout << "[ERROR] �۲� ���� �о���� ����" << endl;
		return;
	}

	this->text = text;
	this->color = color;

	/* �۲� �ɼ� �����ϱ� */
	FT_Set_Pixel_Sizes(face, size, size); // �۲� ũ�� �ɼ�
}

Text::~Text() {
	/* FreType ���̺귯�� ��ȯ */
	FT_Done_Face(face);
	FT_Done_FreeType(library);
}

void Text::start() {

}

void Text::draw() {
	int fx = (int)getPx(), fy = (int)getPy();

	/* ���ڿ� ũ�⸸ŭ �ݺ��ϱ� */
	for (int i = 0; i < text.length(); i++) {
		/* ���ڿ� �ش�Ǵ� �۲�(�Ϻ�) �о���� */
		int index = FT_Get_Char_Index(face, text[i]);			// 1. �ش� ���� ��ġ(index) ã��
		FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);			// 2. ã�� ��ġ���� �۲� ��� �о����
		FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);	// 3. �о�� �۲� ����� �̹����� ��ȯ�ϱ�

		/* ��ȯ�� �̹��� ���� �����ϱ� */
		unsigned char * buffer = face->glyph->bitmap.buffer;	// - �̹��� ĥ ����
		int width = face->glyph->bitmap.width;					// - �̹����� ����ũ��
		int height = face->glyph->bitmap.rows;					// - �̹����� ����ũ��

		/* ������ �̹��� �������̿��� �̹����� ����ϱ� */
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
	this->color = RGB(r, g, b); // �����ʿ� 32��Ʈ RGB��
}

void Text::setText(wstring text) {
	this->text = text;
}