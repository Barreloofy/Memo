/*
StringBuffer.c
Memo

Created by Barreloofy on 9/5/25 at 6:10 PM
*/

#include "StringBuffer.h"

/* The stringBufferInit() takes a pointer to a StringBuffer
 * and initializes its properties.
 *
 * - Parameters:
 *    - buffer: The StringBuffer to initialize.
 *    - capacity: The initial capacity of buffer.
 * - Returns: A boolean indicating whether initialization was successful.
 */
bool stringBufferInit(StringBuffer* buffer, size_t capacity) {
  buffer->storage = malloc(sizeof(char) * (capacity ? capacity : 1));
  if (buffer->storage == NULL) return false;

  buffer->capacity = (capacity ? capacity : 1);
  buffer->size = 0;

  return true;
}


/* The stringBufferAppend() function will grow the buffer
 * by calling realloc() if size of buffer matches its capacity.
 * In case of overflow or realloc() failing returns false,
 * indicating element was not appended.
 * Failure will not deallocate buffer, instead it will null terminated buffer
 * by setting the last element to null.
 *
 * - Parameters:
 *    - buffer: The StringBuffer to append element to.
 *    - element: The element to append.
 * - Returns: A boolean indicating if element was appended successfully.
 */
bool stringBufferAppend(StringBuffer* buffer, char element) {
  if (buffer->size == buffer->capacity) {
    if (buffer->capacity < (SIZE_T_MAX / 2)) {
      char* bridge = NULL;
      size_t newCapacity = buffer->capacity * 2;

      bridge = realloc(buffer->storage, newCapacity);

      if (bridge == NULL) {
        buffer->storage[buffer->size - 1] = ASCIINULL;
        return false;
      }

      buffer->capacity = newCapacity;
      buffer->storage = bridge;
    } else {
      buffer->storage[buffer->size - 1] = ASCIINULL;
      return false;
    }
  }

  buffer->storage[buffer->size++] = element;
  return true;
}
