#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Image {
	unsigned long sizeX;
	unsigned long sizeY;
	char *data;
};

class ImageUtil
{
public:
	static Image * loadBmp(char *filename);
};