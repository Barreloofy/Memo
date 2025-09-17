/*
Node.h
Memo
  
Created by Barreloofy on 9/16/25 at 7:06 PM
*/

#ifndef Node_h
#define Node_h

#include <stdlib.h>
#include <stdio.h>
#include "Bool.h"

typedef struct Node Node;
struct Node {
  char* data;
  Node* previous;
  Node* next;
};

Node* initNode(char*);
bool deinitNode(Node*);

#endif
