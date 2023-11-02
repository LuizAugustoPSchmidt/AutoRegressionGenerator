#include "Generator.h"

void initialize_tex_file(FILE *fptr, Project project){
    fprintf(fptr, "\\documentclass{article}\n");
    fprintf(fptr, "\n\\usepackage{graphicx}\n");
    fprintf(fptr, "\\usepackage{pgfplotstable}\n");
    fprintf(fptr, "\\usepackage{amsmath}\n");
    fprintf(fptr, "\\usepackage{amssymb}\n");
    fprintf(fptr, "\n\\title{%s}\n", project.name);
    fprintf(fptr, "\\author{%s}\n", project.author);
    fprintf(fptr, "\\date{%s}\n", project.date);
    fprintf(fptr, "\n\\begin{document}\n");
    fprintf(fptr, "\\maketitle\n");
}

void end_tex_file(FILE *fptr, Project project){
    char* auxString;

    fprintf(fptr, "\\end{document}");
    fclose(fptr);

    sprintf(auxString, "cd %s", project.name);
    system(auxString);

    sprintf(auxString, "pdflatex --shell-escape %s.tex", project.name);
    system(auxString);
}

void makeLinearGraph(float *Vx, float *Vy){}

void makeQuadracticGraph(float a, float b, float c){}

void makeCubicGraph(float a, float b, float c, float d) {}

void makeExponentialGraph(float a, float b){}

void makeLogarithmicGraph(){}

void makeLogisticalGraph(){}

double sumAll(double *v, int vSize, int exponent){
    double sum = 0;

    for(int i = 0; i < vSize; i++){ 
        sum += pow(v[i], exponent);
    }

    return sum;
}

double getAvg(double* v, int size, int exponent){
    return (double)sumAll(v, size, exponent) / size;
}

double* linearRegression(double x[], double y[], int size){ //This could be fun to write in Haskell
    const double avgX = getAvg(x, size, 1);
    const double avgY = getAvg(y, size, 1);

    double num = 0, den = 0;
    /*regLinCoefs must be malloced in order to be able to return it, as you cannot return values allocated in the stack*/
    double* regLinCoefs = (double*) malloc(2*sizeof(double)); //pos[0] is coef. "a" and pos[1] is coef. "b"

    for(int i = 0; i < size; i++){
        num += (x[i] - avgX)*(y[i] - avgY);
        den += (x[i] - avgX)*(x[i] - avgX);
    }

    if(den){
        regLinCoefs[0] = num / den;
        regLinCoefs[1] = avgY - regLinCoefs[0] * avgX;
        return regLinCoefs;
    }else{
        perror("Cannot divide by 0!");
        free(regLinCoefs);
        return NULL;
    }
}

double* quadraticRegression(double x[], double y[], int size){}

double* cubicRegression(double x[], double y[], int size){}

double* exponentialRegression(double x[], double y[], int size){}

double* logarithmicRegression(double x[], double y[], int size){}

double* logisticalRegression(double x[], double y[], int size){}

double* inverseRegression(double x[], double y[], int size){}

double* inverseSquaredRegression(double x[], double y[], int size){}
