/*
Store.c
Memo
  
Created by Barreloofy on 6/9/25 at 11:47 AM
*/

#include "Store.h"

/* Private helper function of load(), called once a critical state is reached.
 * - Parameters:
 *    - list: The list to build up.
 *    - buffer: The StringBuffer holding the current string.
 *    - file: The file data is processed from.
 *    - isEmpty: A boolean value indicating if the buffer is considered empty.
 */
static void finalizeBuffer(List* list, StringBuffer* buffer, FILE* file, bool* isEmpty) {
  if (*isEmpty) {
    free(buffer->storage);
  } else {
    *isEmpty = true;
    stringBufferAppend(buffer, ASCIINULL);
    listAppend(list, nodeCreate(buffer->storage));
  }
  stringBufferInit(buffer, 1);
}

/* Process text data from a file into a doubly linked list.
 * - Parameters:
 *    - list: The list to build up.
 */
void load(List* list) {
  FILE* file = fopen(FILENAME, "r");
  StringBuffer buffer;
  char currentCharacter;
  bool isEmpty = true;

  if (file == NULL) return;

  if (!stringBufferInit(&buffer, 1)) {
    fclose(file);
    return;
  }

  while ((currentCharacter = fgetc(file)) != EOF && buffer.storage != NULL) {
    if (currentCharacter != ASCIITAB &&
        currentCharacter != ASCIILF &&
        currentCharacter != ASCIISPACE) isEmpty = false;

    if (buffer.size == CHARLIMIT || currentCharacter == ASCIILF) {
      finalizeBuffer(list, &buffer, file, &isEmpty);
    } else {
      stringBufferAppend(&buffer, currentCharacter);
    }
  }

  free(buffer.storage);
  fclose(file);
}

/* Writes data from a list to file.
 * - Parameters:
 *    - list: The list to process data from.
 */
void save(const List* list) {
  FILE* file = fopen(FILENAME, "w");
  Node* currentNode = list->head;

  if (file == NULL) return;

  while (currentNode != NULL) {
    fputs(currentNode->data, file);
    fputc(ASCIILF, file);

    currentNode = currentNode->next;
  }

  fclose(file);
}
