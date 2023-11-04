/*
AutoRegGen - Luiz Augusto Schmidt
LINUX version
Please use as you see fit
*/

#include "Generator.h"
//#include "LinkedList.h"

#define getArraySize(v) (sizeof(v)/sizeof(v[0])) 

int main(){
    Project project;
    GRAPH auxGraphBuff;
    int graphRegType;

    initialize_project(&project);

    for(int i = 0; i < project.graphQuant; i++){
        fetchGraphInfo(&auxGraphBuff);
        selectRegType(project, auxGraphBuff); 
    }

    end_tex_file(project.mainPtr, project);
    return 0;
}