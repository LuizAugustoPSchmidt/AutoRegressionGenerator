#include <stdio.h>

#define getSize(X) _Generic((X), float: getSizeFloat(X), int: getSizeInt(X), double: getSizeDouble(X))

typedef struct project{
    char* name;
    char* date;
    char* author;
    FILE* mainPtr;
    FILE* auxPtr;
}Project;

int getSizeFloat(v[]);

int getSizeDouble(v[]);

int getSizeInt(v[]);

void initialize_tex_file(FILE *fptr, const char* projectName, const char* author, const char* date);

void end_tex_file(FILE *fptr, const char* projectName);

void makeLinearGraph(float Vx[], float Vy[]);

void makeQuadracticGraph(float a, float b, float c);

void makeCubicGraph(float a, float b, float c, float d);

void makeExponentialGraph(float a, float b);

void makeLogarithmicGraph(); //Same as LogisticalGraph

void makeLogisticalGraph(); //Haven't even studied logistical regression yet, therefore cannot fill in the parameters: GPT to the rescue!

double sumAll(double v[]);

double calcAverage()
