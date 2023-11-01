#pragma once
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define getSize(X) _Generic((X), \
                                float*: getSizeFloat(X), \
                                int*: getSizeInt(X), \
                                double*: getSizeDouble(X))

typedef struct project{
    char* name;
    char* date;
    char* author;
    FILE* mainPtr;
    FILE* auxPtr;
}Project;

int getSizeFloat(float v[]);

int getSizeDouble(double v[]);

int getSizeInt(int v[]);

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
