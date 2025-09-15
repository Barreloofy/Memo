/*
Store.h
Memo
  
Created by Barreloofy on 6/9/25 at 11:47 AM
*/

#ifndef Store_h
#define Store_h

#include <stdio.h>
#include "Bool.h"
#include "Ascii.h"
#include "StringBuffer.h"
#include "List.h"

#define FILENAME "Data.txt"
#define SYSCHARLIMIT 1024
#define CHARLIMIT SYSCHARLIMIT - 1

void load(List*);
void save(const List*);

#endif
