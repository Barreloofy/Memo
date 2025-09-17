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

#define DEFAULTBUFFERSIZE 1

typedef struct {
  char* storage;
  size_t size;
  size_t capacity;
} StringBuffer;

bool initStringBuffer(StringBuffer* buffer, size_t capacity);

bool stringBufferAppend(StringBuffer* buffer, char element);

#endif
