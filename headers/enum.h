#ifndef _ENUM_H
#define _ENUM_H

#include <stdio.h>

typedef enum filters{
    blur,
    sharpen,
    thresholding,
    grayEscale,
    rotate180,
    emboss,
    identity
} Filter;

#endif