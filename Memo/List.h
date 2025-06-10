/*
List.h
Memo
  
Created by Barreloofy on 6/5/25 at 10:32 PM
*/

#ifndef List_h
#define List_h

#include <stdlib.h>
#include <stdio.h>
#include "Error.h"

typedef struct Node Node;
struct Node {
  char* data;
  Node* previous;
  Node* next;
};

Node* nodeCreate(char*);
Result nodeDestroy(Node*);

typedef struct {
  Node* head;
  Node* tail;
} List;

List listCreate(void);
Result listDestroy(List*);

Result listAppend(List*, Node*);
Result listRemove(List*, unsigned);
Node* listRetrieve(List*, unsigned);
int listIsEmpty(List*);
Result listView(List*);

#endif
