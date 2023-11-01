#pragma once
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define getArraySize(v) (sizeof(v)/sizeof(v[0])) //Do not use this macro with pointers, only with arrays

typedef struct project{
    char* name;
    char* date;
    char* author;
    FILE* mainPtr;
    FILE* auxPtr;
}Project;

void initialize_tex_file(FILE *fptr, Project project);

void end_tex_file(FILE *fptr, Project project);

void makeLinearGraph(float Vx[], float Vy[]);

void makeQuadracticGraph(float a, float b, float c);

void makeCubicGraph(float a, float b, float c, float d);

void makeExponentialGraph(float a, float b);

void makeLogarithmicGraph(); //Same as LogisticalGraph

void makeLogisticalGraph(); //Haven't even studied logistical regression yet, therefore cannot fill in the parameters: GPT to the rescue!

double sumAll(double v[], int exponent);

double calcAverage(double v[]);
