#include <stdio.h>
//#include <direct.h>
#include "Generator.h"
#include <string.h>
#include <stdlib.h>

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

void makeGraph(){}

