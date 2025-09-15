/*
List.h
Memo
  
Created by Barreloofy on 6/5/25 at 10:32 PM
*/

#ifndef List_h
#define List_h

#include <stdlib.h>
#include <stdio.h>
#include "Bool.h"

typedef struct Node Node;
struct Node {
  char* data;
  Node* previous;
  Node* next;
};

Node* nodeCreate(char*);
bool nodeDestroy(Node*);

typedef struct {
  Node* head;
  Node* tail;
} List;

List listCreate(void);
bool listDestroy(List*);

bool listView(List*);
bool listAppend(List*, Node*);
bool listRemove(List*, unsigned int);

#endif
