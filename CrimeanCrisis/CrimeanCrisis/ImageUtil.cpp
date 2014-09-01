#include "ImageUtil.h"

Image * ImageUtil::loadBmp(char *filename)
{
	Image *image = (Image *)malloc(sizeof(Image));

	unsigned long i; // standard counter.

	// open file
	FILE *file;
	errno_t errorCode = fopen_s(&file, filename, "rb");
	if (file == NULL)
	{
		return NULL;
	}

	// seek through the bmp header, read the width and height
	fseek(file, 18, SEEK_SET);
	if ((fread(&image->sizeX, 4, 1, file) != 1)
		|| (fread(&image->sizeY, 4, 1, file) != 1)) 
	{
		return NULL;
	}

	// read the data.
	fseek(file, 54, SEEK_SET);
	unsigned long size = image->sizeX * image->sizeY * 3;
	image->data = (char *)malloc(size);
	if (image->data == NULL) 
	{
		return NULL;
	}

	if ((i = fread(image->data, size, 1, file)) != 1) 
	{
		return NULL;
	}

	for (i = 0; i < size; i += 3) { // reverse all of the colors. (bgr -> rgb) 
		char temp = image->data[i];
		image->data[i] = image->data[i + 2];
		image->data[i + 2] = temp;
	}
	fclose(file);

	return image;
}