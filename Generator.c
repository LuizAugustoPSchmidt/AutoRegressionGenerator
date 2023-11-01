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

double sumAll(double *v, int exponent){
    double sum = 0;

    for(int i = 0; i < getArraySize(v); i++){
        sum += pow(v[i], exponent);
    }

    return sum;
}

double calcAverage(double v[]){
    double *copy = v;
    return sumAll(copy, 1) / getArraySize(copy);
}