#include <stdio.h>
#include <stdlib.h>
#include "../headers/image.h"
#include "../headers/struct.h"
#include "../headers/enum.h"
#include "../headers/filters.h"


int main(){
    
	int line, column;
    char type[2];
    FILE *image = fopen("../lena.txt", "r");
    fscanf(image, "%s", type);
    fscanf(image, "%i %i", &column, &line);
    fclose(image);

	Pixel matrix[line][column];

	getImage(line, column, matrix);

	return 0;
}


