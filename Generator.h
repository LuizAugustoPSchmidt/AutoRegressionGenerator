/*Note: all - I repeat: ALL - arrays MUST be malloced, otherwise they are not accessible to other functions properly*/

//This could be far better organized - between graphMakers and regressionMakers and all, but for now it's ok. 
//I wanna focus on the implementation right now.

//Turns out I'm gonna apply my data structures knowledge here
#pragma once
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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

void makeLinearGraph(double Vx[], double Vy[], int size);

void makeQuadracticGraph(double Vx[], double Vy[], int size);

void makeCubicGraph(float a, float b, float c, float d);

void makeExponentialGraph(float a, float b);

void makeLogarithmicGraph(); //Same as LogisticalGraph

void makeLogisticalGraph(); //Haven't even studied logistical regression yet, therefore cannot fill in the parameters: GPT to the rescue!

void makeInverseGraph();

void makeInverseSquaredGraph();

double sumAll(double v[], int vSize, int exponent);

double getAvg(double* v, int size, int exponent);

double S(double* a, double* b, int size, int exponent_a, int exponent_b);

double* linearRegression(double x[], double y[], int size);

double* quadraticRegression(double x[], double y[], int size);

double* cubicRegression(double x[], double y[], int size);

double* exponentialRegression(double x[], double y[], int size);

double* logarithmicRegression(double x[], double y[], int size);

double* logisticalRegression(double x[], double y[], int size);

double* inverseRegression(double x[], double y[], int size);

double* inverseSquaredRegression(double x[], double y[], int size);