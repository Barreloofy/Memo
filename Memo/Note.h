/*
Note.h
Memo
  
Created by Barreloofy on 6/7/25 at 3:37 PM
*/

#ifndef Note_h
#define Note_h

#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include "Bool.h"
#include "Ascii.h"
#include "StringBuffer.h"

char* noteCreate(void);
void noteAdd(List*);
void noteRemove(List*);

#endif
