/*
 Note.c
Memo
  
Created by Barreloofy on 6/7/25 at 3:37 PM
*/

#include "Note.h"

void noteAdd(List* list) {
  char* note = noteCreate();

  if (note == NULL) {
    goto operationError;
  } else {
    if (listAppend(list, nodeCreate(note)) == SUCCESS) {
      printf("--- Note Successfully Added ---\n");
      return;
    } else {
      goto operationError;
    }
  }

operationError:
  printf("Failed To Add Note\n");
}

char* noteCreate(void) {
  char* buffer = malloc(sizeof(char));
  int capacity = sizeof(char);
  int size = 0;
  char currentCharacter;

  int isEmpty = 1;

  if (buffer == NULL) return NULL;

  printf("\n--- Add Note ---");
  printf("\nNote: ");

  while ((currentCharacter = getchar()) != '\n') {
    if (currentCharacter != 10 && currentCharacter != 9 && currentCharacter != 32) isEmpty = 0;

    if (size < capacity) {
      buffer[size++] = currentCharacter;
    } else {
      char* bridge = NULL;
      int newCapacity = capacity * 2;

      if (newCapacity <= capacity) {
        free(buffer);
        return NULL;
      }

      capacity = newCapacity;
      bridge = realloc(buffer, capacity);
      if (bridge == NULL) {
        free(buffer);
        return NULL;
      }

      buffer = bridge;
      buffer[size++] = currentCharacter;
    }
  }

  if (!isEmpty) {
    buffer[size] = '\0';
    return buffer;
  } else {
    return NULL;
  }
}

void noteRemove(List* list) {
  unsigned choice = 0;

  if (listView(list)) return;

  printf("Enter Index of Note To Remove: ");
  scanf("%d", &choice);
  while (getchar() != '\n');

  if (listRemove(list, choice - 1) == SUCCESS) {
    printf("--- Note Successfully Removed ---\n");
  } else {
    printf("--- While Removing Note encountered an Error\n");
    printf("Make Sure The Index Corresponds To One Of The Notes ---\n");
  }
}
