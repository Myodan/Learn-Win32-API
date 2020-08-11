#include <Windows.h>
#include <stdio.h>

#include "BMP.h"
#include "graphic.h"

///////��Ʈ�� ���� �б� �Լ�//////
int readBMP(const char * fileName, Image * img) {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	///////��Ʈ�� ���� �о����//////
	FILE * stream;
	errno_t errno;

	errno = fopen_s(&stream, fileName, "rb");

	if (errno == 0) {
		fread(&fileHeader, sizeof(fileHeader), 1, stream);
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		///////////////���� ���� Ȯ���ϱ�/////////////////
		if (fileHeader.bfType != 0x4D42)  //���ΰ� ��Ʈ�� ������ �ƴ�
		{
			printf("�ùٸ� ��Ʈ�� ������ �ƴ�\n");
			return -1;
		}

		if (infoHeader.biBitCount != 32) {
			printf("32 ��Ʈ ��Ʈ�� ���� �ƴ�\n");
			return -1;
		}
		////////////////��Ʈ�� ����Ÿ �о����////////////
		int size = infoHeader.biSizeImage / 4;

		img->width = infoHeader.biWidth;
		img->height = infoHeader.biHeight;
		img->argb = new unsigned int[size];

		fread(img->argb, sizeof(unsigned int), size, stream);

		fclose(stream);

		return 0;
	}
	else {
		printf("��Ʈ�� ���� ���� ����\n");
		return -1;  //���� ���� ����
	}
}

int readBMPRect(const char * fileName, Image * img, int x, int y, int width, int height) {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	///////��Ʈ�� ���� �о����//////
	FILE * stream;
	errno_t errno;

	errno = fopen_s(&stream, fileName, "rb");

	if (errno == 0) {
		fread(&fileHeader, sizeof(fileHeader), 1, stream);
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		///////////////���� ���� Ȯ���ϱ�/////////////////
		if (fileHeader.bfType != 0x4D42)  //���ΰ� ��Ʈ�� ������ �ƴ�
		{
			printf("�ùٸ� ��Ʈ�� ������ �ƴ�\n");
			return -1;
		}

		if (infoHeader.biBitCount != 32) {
			printf("32 ��Ʈ ��Ʈ�� ���� �ƴ�\n");
			return -1;
		}

		///////////�̹�������..Ư���簢�� ���� �о����//////
		//[1]�ε� �׸� ��ġ��..�̵��ϱ� - fseek
		int skip = (y * infoHeader.biWidth + x) * 4;

		fseek(stream, skip, SEEK_CUR);   //SEEK_CUR (���� ��ġ����), SEEK_SET(���� ó������), SEEK_END(���ϳ�����)

		//[2]�̹��� �ε�..�޸�..�����Ҵ��ϱ�..
		int size = width * height;

		img->argb = new unsigned int[size];
		img->width = width;
		img->height = height;

		//[3]�̹�����...�о�鼭..�̵���...����
		int gap = (infoHeader.biWidth - width) * 4;

		//[4]�̹��� �ε��ϱ�

		unsigned int * ptr = img->argb;

		for (int i = 0; i < height; i++) {
			fread(ptr, sizeof(unsigned int), width, stream);
			fseek(stream, gap, SEEK_CUR);

			ptr = ptr + width;  //�ε��� �̹���..���� ���� �ּ�..������Ű��
		}

		//[5]���� �ݱ�
		fclose(stream);

		return 0;
	}
	else {
		printf("��Ʈ�� ���� ���� ����\n");
		return -1;
	}
}

void drawBMP(float px, float py, Image * img) {
	for (int y = 0; y < img->height; y++) {
		for (int x = 0; x < img->width; x++) {
			unsigned int pixel = img->argb[y * img->width + x];

			setPixel((int)px + x, (int)py + y, pixel);
		}
	}
}

void drawBMP(float px, float py, Image * img, float fillAmount) {
	for (int y = 0; y < img->height; y++) {
		for (int x = 0; x < img->width * fillAmount; x++) {
			unsigned int pixel = img->argb[y * img->width + x];

			setPixel((int)px + x, (int)py + y, pixel);
		}
	}
}