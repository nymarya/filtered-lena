#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include "../headers/struct.h"
#include "../headers/enum.h"
#include "../headers/filters.h"

void applyFilter(Filter filter, char type[2], int qual, int line, int column, Pixel original[line][column], Pixel modified[line][column]);

/**
 * This function reads the file with image data.
 * @int lin      Number of lines in the matrix.
 * @int col      Number of columns in the matrix.
 * @Pixel matrix Matrix with image data.
 */
void getImage(int lin, int col, Pixel matrix[lin][col]){
    
    int line, column, quality;
    char type[2];
    FILE *image = fopen("../lena.txt", "r");
    
    fscanf(image, "%s", type);
    fscanf(image, "%i %i", &column, &line);
    fscanf(image, "%i", &quality);
    
    int i, j;
    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            fscanf(image, "%i %i %i", &matrix[i][j].r, &matrix[i][j].g, &matrix[i][j].b);

        }
    }
    fclose(image);
    
    Pixel modified[lin][col];
    memset(modified, 0, sizeof(modified[0][0]) * lin * col);
    for(i = 0; i < 8; i++){
        applyFilter(i, type, quality, lin, col, matrix, modified);
    }
}


/**
 * This function fills the matrix with image data.
 * @char type    Image type.
 * @int lin      Number of lines in the matrix.
 * @int col      Number of columns in the matrix.
 * @int qual     Image quality.
 * @char name    Image name.
 * @Pixel matrix Matrix with image data.
 */
void setImage(char type[2], int lin, int col, int qual, Pixel matrix[lin][col], char name[30]){
    
    char *gallery = "../gallery/";
    char *path = malloc(strlen(gallery) + strlen(name) + 1);
    strcpy(path, gallery);
    strcat(path, name);
    
    FILE *image = fopen(path, "w");
    
    fprintf(image, "%s\n", type);
    fprintf(image, "%i %i\n", col, lin);
    fprintf(image, "%i\n", qual);
    int i, j;
    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            fprintf(image, "%i %i %i\n", matrix[i][j].r, matrix[i][j].g, matrix[i][j].b);
			
        }
    }
    free(path);
    fclose(image);
}

/**
 * This function applies a filter to image.
 * @filter          Filter (enum).
 * @char type       Image type.
 * @int lin         Number of lines in the matrix.
 * @int col         Number of columns in the matrix.
 * @int qual        Image quality.
 * @Pixel original  Matrix in which will be applied the filters.
 * @Pixel modified  Matrix that generates the image.
 */
void applyFilter(Filter filter , char type[2], int qual, int line, int column, Pixel original[line][column], Pixel modified[line][column]){
    switch(filter){
        case blur:
            applyBlur(line, column, original, modified);
            setImage(type, line, column, qual, modified, "blur.ppm");
            break;
        
        case sharpen:
            applySharpen(line, column, original, modified);
            setImage(type, line, column, qual, modified, "sharpen.ppm");
            break;
        
        case thresholding:
            applyThresholding(line, column, original, modified);
            setImage(type, line, column, qual, modified, "thresholding.ppm");
            break;
        
        case grayEscale:
            applyGray(line, column, original, modified);
            setImage(type, line, column, qual, modified, "gray.ppm");
            break;
        
        case rotate180:
            applyRotation(line, column, original, modified);
            setImage(type, line, column, qual, modified, "rotate.ppm");
            break;
        
        case emboss:
            applyEmboss(line, column, original, modified);
            setImage(type, line, column, qual, modified, "emboss.ppm");
            break;
            
        case identity:
            applyIdentity(line, column, original, modified);
            setImage(type, line, column, qual, modified, "identity.ppm");
            break;
        
        default:
            setImage(type, line, column, qual, modified, "original.ppm");
            break;
             
         }

}
