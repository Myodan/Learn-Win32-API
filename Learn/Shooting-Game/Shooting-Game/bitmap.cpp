#include "framework.h"

int MyLoadBitmap(Image *img, const char *path, int x, int y, int width, int height) {
	BITMAPFILEHEADER *fileHeader = new BITMAPFILEHEADER();
	BITMAPINFOHEADER *infoHeader = new BITMAPINFOHEADER();

	FILE *stream;
	errno_t errno;
	errno = fopen_s(&stream, path, "rb");

	if (errno != 0) {
		printf("ERROR: 파일 로드 중 에러가 발생했습니다. (%d)\n", errno);
		return errno;
	}

	fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, stream);
	fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, stream);

	if (fileHeader->bfType != 0x4D42) {
		printf("ERROR: 올바른 비트맵 파일이 아닙니다.\n");
		return -1;
	}

	if (infoHeader->biBitCount != 32) {
		printf("ERROR: 32bit 비트맵 파일이 아닙니다.\n");
		return -1;
	}

	// [1] 로드 그림 위치로..이동하기 - fseek
	int skip = (y * infoHeader->biWidth + x) * 4;
	fseek(stream, skip, SEEK_CUR);   //SEEK_CUR (현재 위치에서), SEEK_SET(파일 처음에서), SEEK_END(파일끝에서)

	// [2] 이미지 로드..메모리..동적할당하기..
	int size = width * height;

	img->argb = new unsigned int[size];
	img->width = width;
	img->height = height;

	// [3] 이미지를...읽어면서..이동할...간격
	int gap = (infoHeader->biWidth - width) * 4;

	// [4] 이미지 로드하기
	unsigned int *ptr = img->argb;

	for (int i = 0; i < height; i++) {
		fread(ptr, sizeof(unsigned int), width, stream);
		fseek(stream, gap, SEEK_CUR);

		ptr = ptr + width;  //로드한 이미지..저장 라인 주소..증가시키기
	}

	// [5] 파일 닫기
	fclose(stream);

	delete fileHeader;
	delete infoHeader;

	return 0;
}

int MyLoadBitmap(Image *img, const char *path) {
	BITMAPFILEHEADER *fileHeader = new BITMAPFILEHEADER();
	BITMAPINFOHEADER *infoHeader = new BITMAPINFOHEADER();

	FILE *stream;
	errno_t errno;
	errno = fopen_s(&stream, path, "rb");

	if (errno != 0) {
		printf("ERROR: 파일 로드 중 에러가 발생했습니다. (%d)\n", errno);
		return errno;
	}

	fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, stream);
	fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, stream);

	if (fileHeader->bfType != 0x4D42) {
		printf("ERROR: 올바른 비트맵 파일이 아닙니다.\n");
		return -1;
	}

	if (infoHeader->biBitCount != 32) {
		printf("ERROR: 32bit 비트맵 파일이 아닙니다.\n");
		return -1;
	}

	int size = infoHeader->biSizeImage / 4;

	img->width = infoHeader->biWidth;
	img->height = infoHeader->biHeight;
	img->argb = new unsigned int[size];

	fread(img->argb, sizeof(unsigned int), size, stream);

	fclose(stream);

	delete fileHeader;
	delete infoHeader;

	return 0;
}

void MyDrawBitmap(Image *img, float px, float py) {
	//이미지 뒤집어서 불러오기
	//for(int y = img->height - 1, i = 0; y > 0; y--, i++){
	//	for(int x = 0; x < img->width; x++){
	//		SetPixel(x + px, i + py, img->argb[y * img->width + x]);
	//	}
	//}

	for (int y = 0; y < img->height; y++) {
		for (int x = 0; x < img->width; x++) {
			SetPixel(x + px, y + py, img->argb[y * img->width + x]);
		}
	}
}