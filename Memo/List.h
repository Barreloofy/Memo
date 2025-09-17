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
#include "Node.h"

typedef struct {
  Node* head;
  Node* tail;
} List;

List initList(void);
bool deinitList(List*);

bool listView(const List*);
bool listAppend(List*, Node*);
bool listRemove(List*, unsigned int);

#endif
