#pragma once
#include "Generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct ProjectNode{
    GRAPH info;
    struct ProjectNode* next;
}NODE;
 
 NODE* initialize();

 void printList(NODE* listPtr);



