#pragma once
#include "Generator.h"

typedef struct ProjectNode{
    GRAPH info;
    struct ProjectNode* next;
}NODE;

NODE* initialize();

void printList(NODE* listPtr);

NODE* insertBeggining(NODE* listPtr, GRAPH data);

NODE* insertEnd(NODE* listPtr, GRAPH data);

NODE* insertMiddle(NODE* listPtr, GRAPH data);

NODE* insertInOrder(NODE* listPtr, GRAPH data);

NODE* deleteNode(NODE* listPtr, int code);

NODE* destroyList(NODE* listPtr);



