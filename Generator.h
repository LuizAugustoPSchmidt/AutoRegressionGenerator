/*Note: all - I repeat: ALL - arrays MUST be malloced, otherwise they are not accessible to other functions properly*/

//This could be far better organized - between graphMakers and regressionMakers and all, but dor now it's ok. I wanna focus on the implementation
//Turns out I'm gonna apply my data structures knowledge here
#pragma once
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define calcAvg(v) (sumAll(v, 1)/getArraySize(v))

typedef struct project{
    char* name;
    char* date;
    char* author;
    FILE* mainPtr;
    FILE* auxPtr;
}Project;

typedef struct graph{
    int* x;
    int* y;
    int graphCode;
}GRAPH;

void initialize_tex_file(FILE *fptr, Project project);

void end_tex_file(FILE *fptr, Project project);

void makeLinearGraph(float Vx[], float Vy[]);

void makeQuadracticGraph(float a, float b, float c);

void makeCubicGraph(float a, float b, float c, float d);

void makeExponentialGraph(float a, float b);

void makeLogarithmicGraph(); //Same as LogisticalGraph

void makeLogisticalGraph(); //Haven't even studied logistical regression yet, therefore cannot fill in the parameters: GPT to the rescue!

void makeInverseGraph();

void makeInverseSquaredGraph();

double sumAll(double v[], int vSize, int exponent);

double getAvg(double* v, int size, int exponent);

double* linearRegression(double x[], double y[]);

double* quadraticRegression(double x[], double y[]);

double* cubicRegression(double x[], double y[]);

double* exponentialRegression(double x[], double y[]);

double* logarithmicRegression(double x[], double y[]);

double* logisticalRegression(double x[], double y[]);

double* inverseRegression(double x[], double y[]);

double* inverseSquaredRegression(double x[], double y[]);