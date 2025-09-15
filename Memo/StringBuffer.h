/*
StringBuffer.h
Memo
  
Created by Barreloofy on 9/5/25 at 6:10 PM
*/

#ifndef StringBuffer_h
#define StringBuffer_h

#include <stdlib.h>
#include <limits.h>
#include "Bool.h"
#include "Ascii.h"

typedef struct {
  char* storage;
  size_t size;
  size_t capacity;
} StringBuffer;

bool stringBufferInit(StringBuffer* buffer, size_t capacity);

bool stringBufferAppend(StringBuffer* buffer, char element);

#endif
