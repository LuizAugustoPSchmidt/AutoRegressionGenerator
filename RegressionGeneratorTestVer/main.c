#include "Generator.h"
#include "LinkedList.h"

#define getArraySize(v) (sizeof(v)/sizeof(v[0]))

int main(){
    Project project;

    /*I'm only doing this to test this version. It's absolutely not the end product nor it's gonna last long*/
    //project.mainPtr = fopen("~/home/luiz/Documents/geral/test.tex", "w");
    //initialize_project(&project);

    double Vx[6], Vy[6];

    for(int i = 0; i < (int)getArraySize(Vx); i++){
        printf("--------------------");
        printf("Insert x%i: ", i + 1);
        scanf("%lf", &Vx[i]);
        printf("\nInsert y%i: ", i + 1);
        scanf("%lf", &Vy[i]);
        printf("--------------------");
    }

    double* regLinCoefs_main = linearRegression(Vx, Vy, getArraySize(Vx));

    system("clear");

    printf("\na = %lf\nb = %lf", regLinCoefs_main[0], regLinCoefs_main[1]);

    return 0;
}
