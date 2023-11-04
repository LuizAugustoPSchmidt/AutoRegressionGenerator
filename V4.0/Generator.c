#include "Generator.h"

void initialize_project(Project* project){
    printf("Welcome to AutoRegGen!\n\n");

    printf("Please insert the project's name: ");
    fgets(project->name, 256, stdin); //In no world is this any safe. But I don't wanna focus on details right now. I'll solve this later 
    fputs("\n", stdout);

    printf("Please insert the full path to the folder in which to create the project: ");
    fgets(project->path, 256, stdin);

    if(!mkdir(project->path, 0777)){

        sprintf(project->path, "%s/%s.tex", project->path, project->name);

        if((project->mainPtr = fopen(project->path, "w")) != NULL){
            printf("Please insert the authors' name: ");
            fgets(project->author, 512, stdin);
            fputs("\n", stdout);

            printf("Insert today's date: ");
            fgets(project->date, 12, stdin);
            fputs("\n", stdout);

            printf("Please insert the number of grpahs you want to generate: ");
            scanf("%d", &project->graphQuant);
            fputs("\n", stdout);
            
            system("clear");

        }else{
            printf("Erro ao criar arquivo .tex");
            perror("Failed to create file ending in .tex");
        }
    }else{
        printf("Erro ao criar pasta para o projeto");
        perror("Failed to create directory for the project");
    }

}

void fetchGraphInfo(GRAPH* graph){
    printf("Insert the graph's code: ");
    scanf("%i", &graph->graphCode);
    puts("\n");

    printf("Insert the graph's title: ");
    fgets(graph->title, 32, stdin);
    puts("\n");
    
    printf("Insert the graph's color: ");
    fgets(graph->color, 16, stdin);
    puts("\n");

    printf("Insert the graph's x label: ");
    fgets(graph->xLabel, 64, stdin);
    puts("\n");

    printf("Insert the graph's y label: ");
    fgets(graph->yLabel, 64, stdin);
    puts("\n");

    printf("Insert the number of points: ");
    scanf("%i", &graph->arrSize);
    puts("\n");

    for(int i = 0; i < graph->arrSize; i++){
        printf("--------------------");

        printf("Insert x%i: ", i + 1);
        scanf("%lf", &graph->x[i]);

        printf("\nInsert y%i: ", i + 1);
        scanf("%lf", &graph->y[i]);

        printf("--------------------");
    }

}

void selectRegType(Project project, GRAPH auxGraphBuff){
    int graphRegType;
    printf("Insert regression type: \n");
    printf("1 - Linear\n2 - Quadratic");
    scanf("%i", &graphRegType);
    switch(graphRegType){
        case 1:
            makeLinearGraph(auxGraphBuff, project.mainPtr);
            break;
        case 2: 
            makeQuadracticGraph(auxGraphBuff, project.mainPtr);
            break;
    }
}

void initialize_tex_file(FILE *fptr, Project project){
    //Apparently it's too much for a single buffer. But it's still more readable this way
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

void makeLinearGraph(GRAPH info, FILE* fptr){
    /*y = ax + b*/
    //Color has to be a string accepted by the LaTeX file
    double* coeficients; //Remember: [0] is "a", [1] is "b"

    coeficients = linearRegression(info.x, info.y, info.arrSize);

    /*Continue code here*/
    fprintf(fptr, "\\begin{tikzpicture}\n\t\\begin{axis}[title=%s,\n\txlabel={%s},\n\tylabel={%s}]\n", info.title, info.xLabel, info.yLabel);
    fprintf(fptr, "\t\t\\addplot[%s, samples=200]{%lf x + %lf}", info.color,  coeficients[0], coeficients[1]);
    fprintf(fptr, "\\addplot table {data%i.dat}", info.graphCode);
    fputs("% This document was made using AutRegGen, which calculates the coefficients for various regression types. The data is included in one of the .dat files present in this project", fptr);
    fputs("\n\t\\end{axis}\n\\end{tikzpicture}", fptr);

    free(coeficients);
}

void makeQuadracticGraph(GRAPH info, FILE* fptr){
    double* coeficients;

    coeficients = quadraticRegression(info.x, info.y, info.arrSize);

    /*Continue code here*/

    free(coeficients);
}

void makeCubicGraph(GRAPH info, FILE* fptr) {}

void makeExponentialGraph(GRAPH info, FILE* fptr){}

void makeLogarithmicGraph(GRAPH info, FILE* fptr){}

void makeLogisticalGraph(GRAPH info, FILE* fptr){}

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

double devToMean(double* a, double* b, int size, int exponent_a, int exponent_b){
    double sum = 0;
    for(int i = 0; i < 0; i++){
        sum += (a[i] - getAvg(a, size, exponent_a)) * (b[i] - getAvg(b, size, exponent_b));
    }
    return sum;
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
        printf("Don't forget to free regLinCoefs!!");
        return regLinCoefs;
    }else{
        perror("Cannot divide by 0!");
        free(regLinCoefs);
        return NULL;
    }
}


double* quadraticRegression(double x[], double y[], int size){
    //This is gonna be confusing - brace yourselves
    const double s_xx = devToMean(x, x, size, 1, 1);
    const double s_xy = devToMean(x, y, size, 1, 1);
    const double s_x2y = devToMean(x, y, size, 2, 1);
    const double s_xx2 = devToMean(x, x, size, 1, 2);
    const double s_x2x2 = devToMean(x, x, size, 2, 2); 

    const double den = s_xx * s_x2x2 - s_xx2 * s_xx2;

    double* quadRegCoefs = (double*)malloc(3*sizeof(double)); // [0] is "a", [1] is "b", [2] is "c"
    printf("Remember to free quadRegCoefs!");

    if(den != 0){
        quadRegCoefs[0] = (s_x2y * s_xx - s_xy * s_xx2) / den;
        quadRegCoefs[1] = (s_xy * s_x2x2 - s_x2y * s_xx2) / den;
        quadRegCoefs[2] = (getAvg(y, size, 1) - quadRegCoefs[1] * getAvg(x, size, 1) - quadRegCoefs[0] * getAvg(x, size, 2));
        return quadRegCoefs;
    }else{
        printf("Cannot divide by 0!");
        free(quadRegCoefs);
        return NULL;
    }
}
/*
double* cubicRegression(double x[], double y[], int size){}

double* exponentialRegression(double x[], double y[], int size){}

double* logarithmicRegression(double x[], double y[], int size){}

double* logisticalRegression(double x[], double y[], int size){}

double* inverseRegression(double x[], double y[], int size){}

double* inverseSquaredRegression(double x[], double y[], int size){}
*/