#include "struct.h"
#include "enum.h"
#include "filters.h"

//This function reads the file with image data.
void getImage(int lin, int col, Pixel matrix[lin][col]);

//This function fills the matrix with image data.
void setImage(char type[2], int lin, int col, int qual, Pixel matrix[lin][col], char name[30]);

//This function applies a filter to image.
void applyFilter(Filter filter, char type[2], int qual, int line, int column, Pixel original[line][column], Pixel modified[line][column]);