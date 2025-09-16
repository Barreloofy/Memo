/*
Note.c
Memo

Created by Barreloofy on 6/7/25 at 3:37 PM
*/

#include "Note.h"

/* Adds a new node to list with the contents returned by noteCreate().
 *
 * - Parameters:
 *    - list: The list of notes.
 */
void noteAdd(List* list) {
  char* note = noteCreate();

  if (note == NULL) {
    printf("Failed To Add Note\n");
    return;
  }

  if (listAppend(list, nodeCreate(note))) {
    printf("--- Note Successfully Added ---\n");
  } else {
    printf("Failed To Add Note\n");
  }
}


/* Creates a new note from standard input.
 *
 * - Returns: A pointer to the beginning of a null-terminated string.
 */
char* noteCreate(void) {
  StringBuffer buffer;
  char currentCharacter;
  bool isEmpty = true;

  if (!stringBufferInit(&buffer, 1)) return NULL;

  printf(
  "\n"
  "--- Add Note ---"
  "\n"
  "Note: ");

  while ((currentCharacter = getchar()) != ASCIILF) {
    if (currentCharacter != ASCIITAB &&
        currentCharacter != ASCIISPACE) isEmpty = false;

    if (!stringBufferAppend(&buffer, currentCharacter)) {
      free(buffer.storage);
      return NULL;
    }
  }

  if (isEmpty) {
    free(buffer.storage);
    return NULL;
  } else {
    stringBufferAppend(&buffer, ASCIINULL);
    return buffer.storage;
  }
}


/* Removes the specified node, i.e, note from list.
 *
 * - Parameters:
 *    - list: The list of notes.
 */
void noteRemove(List* list) {
  unsigned int index = 0;

  if (!listView(list)) return;

  printf("Enter Index of Note To Remove: ");
  scanf("%d", &index);
  while (getchar() != ASCIILF);

  if (listRemove(list, index)) {
    printf("--- Note Successfully Removed ---\n");
  } else {
    printf(
    "--- While Removing Note encountered an Error\n"
    "Make Sure The Index Corresponds To One Of The Notes ---\n");
  }
}
