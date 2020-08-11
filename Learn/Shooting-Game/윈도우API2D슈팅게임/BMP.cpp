#include <Windows.h>
#include <stdio.h>

#include "BMP.h"
#include "graphic.h"

///////비트맵 파일 읽기 함수//////
int readBMP(const char * fileName, Image * img) {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	///////비트맵 파일 읽어오기//////
	FILE * stream;
	errno_t errno;

	errno = fopen_s(&stream, fileName, "rb");

	if (errno == 0) {
		fread(&fileHeader, sizeof(fileHeader), 1, stream);
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		///////////////내부 정보 확인하기/////////////////
		if (fileHeader.bfType != 0x4D42)  //내부가 비트맵 파일이 아님
		{
			printf("올바른 비트맵 파일이 아님\n");
			return -1;
		}

		if (infoHeader.biBitCount != 32) {
			printf("32 비트 비트맵 파일 아님\n");
			return -1;
		}
		////////////////비트맵 데이타 읽어오기////////////
		int size = infoHeader.biSizeImage / 4;

		img->width = infoHeader.biWidth;
		img->height = infoHeader.biHeight;
		img->argb = new unsigned int[size];

		fread(img->argb, sizeof(unsigned int), size, stream);

		fclose(stream);

		return 0;
	}
	else {
		printf("비트맵 파일 열기 실패\n");
		return -1;  //파일 열기 실패
	}
}

int readBMPRect(const char * fileName, Image * img, int x, int y, int width, int height) {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	///////비트맵 파일 읽어오기//////
	FILE * stream;
	errno_t errno;

	errno = fopen_s(&stream, fileName, "rb");

	if (errno == 0) {
		fread(&fileHeader, sizeof(fileHeader), 1, stream);
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		///////////////내부 정보 확인하기/////////////////
		if (fileHeader.bfType != 0x4D42)  //내부가 비트맵 파일이 아님
		{
			printf("올바른 비트맵 파일이 아님\n");
			return -1;
		}

		if (infoHeader.biBitCount != 32) {
			printf("32 비트 비트맵 파일 아님\n");
			return -1;
		}

		///////////이미지에서..특정사각형 영역 읽어오기//////
		//[1]로드 그림 위치로..이동하기 - fseek
		int skip = (y * infoHeader.biWidth + x) * 4;

		fseek(stream, skip, SEEK_CUR);   //SEEK_CUR (현재 위치에서), SEEK_SET(파일 처음에서), SEEK_END(파일끝에서)

		//[2]이미지 로드..메모리..동적할당하기..
		int size = width * height;

		img->argb = new unsigned int[size];
		img->width = width;
		img->height = height;

		//[3]이미지를...읽어면서..이동할...간격
		int gap = (infoHeader.biWidth - width) * 4;

		//[4]이미지 로드하기

		unsigned int * ptr = img->argb;

		for (int i = 0; i < height; i++) {
			fread(ptr, sizeof(unsigned int), width, stream);
			fseek(stream, gap, SEEK_CUR);

			ptr = ptr + width;  //로드한 이미지..저장 라인 주소..증가시키기
		}

		//[5]파일 닫기
		fclose(stream);

		return 0;
	}
	else {
		printf("비트맵 파일 열기 실패\n");
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