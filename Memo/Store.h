/*
Store.h
Memo
  
Created by Barreloofy on 6/9/25 at 11:47 AM
*/

#ifndef Store_h
#define Store_h

#include <stdio.h>
#include "List.h"

#define FILENAME "Data.txt"
#define CHARLIMIT 1023

void load(List*);
void save(List*);

#endif
