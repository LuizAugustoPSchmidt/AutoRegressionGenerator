#include "LinkedList.h"

NODE* initialize(){
    return NULL;
}

void printList(NODE* listPtr){
    for(NODE* auxPtr = listPtr; auxPtr; auxPtr = auxPtr->next){
        printf("\nGraph code: %d", auxPtr->info.graphCode);
    }
}

NODE* insertBeggining(NODE* listPtr, GRAPH data){
    NODE* new = (NODE*) malloc (sizeof(NODE));

    new->next = listPtr;
    new->info = data;

    listPtr = new;

    return listPtr;
}

NODE* insertEnd(NODE* listPtr, GRAPH data){
    if(listPtr){
        NODE* new = (NODE*) malloc (sizeof(NODE));
        NODE* auxPtr = listPtr;

        new->info = data;
        new->next = NULL;

        for(auxPtr = listPtr; auxPtr; auxPtr = auxPtr->next);

        auxPtr->next = new;

        return listPtr;
    }else{
        NODE* new = (NODE*) malloc (sizeof(NODE));
        new->info = data;
        new->next = NULL;
        listPtr = new;
        return listPtr;
    }
}

NODE* insertMiddle(NODE* listPtr, GRAPH data){
    printf("Rework the insertMiddle function to actually insert in the middle. I can do nothing if I don't have a condition to determine the position in which to insert.");
    return NULL;
}

NODE* insertInOrder(NODE* listPtr, GRAPH data){
    //Now we're talking
    if(listPtr){
        NODE* new = (NODE*) malloc (sizeof(NODE));
        new->info = data;

        NODE* ptAux = listPtr;
        while(ptAux && ptAux->info.graphCode < data.graphCode){
            ptAux = ptAux->next;
        }
        new->next = ptAux->next;
        ptAux->next = new;
    }
    return listPtr;
}

NODE* deleteNode(NODE* listPtr, int code){
    NODE* prev;
    NODE* ptAux;

    while(ptAux != NULL && !(ptAux->info.graphCode == code)){
        prev = ptAux;
        ptAux = ptAux->next;
    }

    if(ptAux == NULL){
        return listPtr;
    }

    if(prev == NULL){
        listPtr = listPtr->next;
    }else{
        prev->next = ptAux->next;
        ptAux->next = NULL;
    }
    free(ptAux);
    return listPtr;
}

NODE* destroyList(NODE* listPtr){
    NODE* ptAux;

    while(listPtr != NULL){
        ptAux = listPtr;
        listPtr = listPtr->next;
        free(ptAux);
    }

    free(listPtr);
    return NULL;
}
