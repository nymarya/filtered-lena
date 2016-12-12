#include "struct.h"
#include "enum.h"

//This function applies blur effect to image.
void applyBlur(int line, int column, Pixel original[line][column], Pixel modified[line][column]);

//This function applies sharpen effect to image.
void applySharpen(int line, int column, Pixel original[line][column], Pixel modified[line][column]);

//This function applies thresholding effect to image.
void applyThresholding(int line, int column, Pixel original[line][column], Pixel modified[line][column]);

//This function applies grayescale effect to image.
void applyGray(int line, int column, Pixel original[line][column], Pixel modified[line][column]);

//This function rotates the image 180 degrees.
void applyRotation(int line, int column, Pixel original[line][column], Pixel modified[line][column]);

//This function applies emboss effect to image.
void applyEmboss(int line, int column, Pixel original[line][column], Pixel modified[line][column]);

//This function applies identity effect to image.
void applyIdentity(int line, int column, Pixel original[line][column], Pixel modified[line][column]);