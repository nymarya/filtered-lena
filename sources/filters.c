#include <stdio.h>
#include "../headers/struct.h"


/**
 * This function applies blur effect to image.
 * @int lin         Number of lines in the matrix.
 * @int col         Number of columns in the matrix.
 * @Pixel original  Matrix in which will be applied the filters.
 * @Pixel modified  Matrix that generates the image.
 */
void applyBlur(int line, int column, Pixel original[line][column], Pixel modified[line][column]){
    int lin, col, i, j, sumR, sumG, sumB;
    
    float blur[3][3] = {
        {0.0625, 0.125, 0.0625},
        {0.125 , 0.25 , 0.125 },
        {0.0625, 0.125, 0.0625}
    };
    
    for(lin = 1; lin < line-1; lin++){
        for(col = 1; col < column-1; col++){
            sumR = 0; sumG = 0; sumB = 0;
            for(i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                    sumR += (original[lin-1 + i][col-1 + j].r) * blur[i][j];
                    sumG += (original[lin-1 + i][col-1 + j].g) * blur[i][j];
                    sumB += (original[lin-1 + i][col-1 + j].b) * blur[i][j];
                }

            }
            
            (sumR > 255)? sumR = 255 : sumR;
            (sumR < 0)? sumR = 0 : sumR;
            (sumG > 255)? sumG = 255 : sumG;
            (sumG < 0)? sumG = 0 : sumG;
            (sumB > 255)? sumB = 255 : sumB;
            (sumB < 0)? sumB = 0 : sumB;
            
            modified[lin][col].r = sumR;
            modified[lin][col].g = sumG;
            modified[lin][col].b = sumB;
            
        }
    }
}

/**
 * This function applies sharpen effect to image.
 * @int lin         Number of lines in the matrix.
 * @int col         Number of columns in the matrix.
 * @Pixel original  Matrix in which will be applied the filters.
 * @Pixel modified  Matrix that generates the image.
 */
void applySharpen(int line, int column, Pixel original[line][column], Pixel modified[line][column]){
    int lin, col, i, j, sumR, sumB, sumG;
    
    float sharpen[3][3] = {
        { 0, -1,  0},
        {-1,  5, -1},
        { 0, -1,  0}
    };
    
    for(lin = 1; lin < line-1; lin++){
        for(col = 1; col < column-1; col++){
            sumR = 0; sumG = 0; sumB = 0;
            for(i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                    sumR += (original[lin-1 + i][col-1 + j].r) * sharpen[i][j];
                    sumG += (original[lin-1 + i][col-1 + j].g) * sharpen[i][j];
                    sumB += (original[lin-1 + i][col-1 + j].b) * sharpen[i][j];
                }

            }
            
            (sumR > 255)? sumR = 255 : sumR;
            (sumR < 0)? sumR = 0 : sumR;
            (sumG > 255)? sumG = 255 : sumG;
            (sumG < 0)? sumG = 0 : sumG;
            (sumB > 255)? sumB = 255 : sumB;
            (sumB < 0)? sumB = 0 : sumB;
            
            modified[lin][col].r = sumR;
            modified[lin][col].g = sumG;
            modified[lin][col].b = sumB;
            
        }
    }
}


/**
 * This function applies thresholding effect to image.
 * @int lin         Number of lines in the matrix.
 * @int col         Number of columns in the matrix.
 * @Pixel original  Matrix in which will be applied the filters.
 * @Pixel modified  Matrix that generates the image.
 */
void applyThresholding(int line, int column, Pixel original[line][column], Pixel modified[line][column]){
    int i, j;
    float media;
    
    for(i = 0; i < line; i++){
        for(j = 0; j < column; j++){
            media = (original[i][j].r + original[i][j].g + original[i][j].b )/3; 
            if(media <= 255/2){
                modified[i][j].r = 0;
                modified[i][j].g = 10;
                modified[i][j].b = 10;
            }
            if(media > 255/2){
                modified[i][j].r = 255;
                modified[i][j].g = 255;
                modified[i][j].b = 255;
            } 
            
        }
    }
}

/**
 * This function applies grayescale effect to image.
 * @int lin         Number of lines in the matrix.
 * @int col         Number of columns in the matrix.
 * @Pixel original  Matrix in which will be applied the filters.
 * @Pixel modified  Matrix that generates the image.
 */
void applyGray(int line, int column, Pixel original[line][column], Pixel modified[line][column]){
    int i, j;
    for (i = 0; i < line; i++){
        for (j = 0; j < column; j++){
            modified[i][j].r = (int) ((0.299 * original[i][j].r) + (0.587 * original[i][j].g) + (0.144 * original[i][j].b)); 
            modified[i][j].g = modified[i][j].r; 
            modified[i][j].b = modified[i][j].r; 

            
            if (modified[i][j].r > 255){
                modified[i][j].r = 255;
                modified[i][j].g = 255;
                modified[i][j].b = 255;

            }       
        
        }
    }

}

/**
 * This function rotates the image 180 degrees.
 * @int lin         Number of lines in the matrix.
 * @int col         Number of columns in the matrix.
 * @Pixel original  Matrix in which will be applied the filters.
 * @Pixel modified  Matrix that generates the image.
 */
void applyRotation(int line, int column, Pixel original[line][column], Pixel modified[line][column]){
    int i, j, lin=0;
    
    for(i = line-1; i > 0; i--){
        for(j = 0; j < column; j++){
            
            modified[lin][j].r = original[i][j].r;
            modified[lin][j].g = original[i][j].g;
            modified[lin][j].b = original[i][j].b;

        }
        lin++;
    }
}

/**
 * This function applies emboss effect to image.
 * @int lin         Number of lines in the matrix.
 * @int col         Number of columns in the matrix.
 * @Pixel original  Matrix in which will be applied the filters.
 * @Pixel modified  Matrix that generates the image.
 */
void applyEmboss(int line, int column, Pixel original[line][column], Pixel modified[line][column]){
  
   int lin, col, i, j, sumR, sumG, sumB;
    
    float emboss[3][3] = {
        {-2, -1, 0},
        {-1,  1, 1},
        { 0, 1,  2}
    };
    
     for(lin = 1; lin < line-1; lin++){
        for(col = 1; col < column-1; col++){
            sumR = 0; sumG = 0;  sumB = 0;
            for(i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                    sumR += (original[lin-1 + i][col-1 + j].r) * emboss[i][j];
                    sumG += (original[lin-1 + i][col-1 + j].g) * emboss[i][j];
                    sumB += (original[lin-1 + i][col-1 + j].b) * emboss[i][j];
                }

            }
            
            (sumR > 255)? sumR = 255 : sumR;
            (sumR < 0)? sumR = 0 : sumR;
            (sumG > 255)? sumG = 255 : sumG;
            (sumG < 0)? sumG = 0 : sumG;
            (sumB > 255)? sumB = 255 : sumB;
            (sumB < 0)? sumB = 0 : sumB;
            
            modified[lin][col].r = sumR;
            modified[lin][col].g = sumG;
            modified[lin][col].b = sumB;
            
        }
    }
}

/**
 * This function applies identity effect to image.
 * @int lin         Number of lines in the matrix.
 * @int col         Number of columns in the matrix.
 * @Pixel original  Matrix in which will be applied the filters.
 * @Pixel modified  Matrix that generates the image.
 */
void applyIdentity(int line, int column, Pixel original[line][column], Pixel modified[line][column]){
  
   int lin, col, i, j, sumR, sumG, sumB;
    
    float identity[3][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    
   for(lin = 1; lin < line-1; lin++){
        for(col = 1; col < column-1; col++){
            sumR = 0; sumG = 0; sumB = 0;
            for(i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                    sumR += (original[lin-1 + i][col-1 + j].r) * identity[i][j];
                    sumG += (original[lin-1 + i][col-1 + j].g) * identity[i][j];
                    sumB += (original[lin-1 + i][col-1 + j].b) * identity[i][j];
                }

            }
            
            (sumR > 255)? sumR = 255 : sumR;
            (sumR < 0)? sumR = 0 : sumR;
            (sumG > 255)? sumG = 255 : sumG;
            (sumG < 0)? sumG = 0 : sumG;
            (sumB > 255)? sumB = 255 : sumB;
            (sumB < 0)? sumB = 0 : sumB;
            
            modified[lin][col].r = sumR;
            modified[lin][col].g = sumG;
            modified[lin][col].b = sumB;
            
        }
    }
}