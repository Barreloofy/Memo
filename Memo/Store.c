/*
Store.c
Memo
  
Created by Barreloofy on 6/9/25 at 11:47 AM
*/

#include "Store.h"

void load(List* list) {
  FILE* file = fopen(FILENAME, "r");

  if (file == NULL) {
    return;
  } else {
    char* buffer = malloc(sizeof(char));
    int capacity = sizeof(char);
    int size = 0;
    char currentCharacter;

    int isEmpty = 1;

    while ((currentCharacter = fgetc(file)) != EOF) {
      if (currentCharacter != 10 && currentCharacter != 9 && currentCharacter != 32) isEmpty = 0;

      if (size >= CHARLIMIT) {
        if (!isEmpty) {
          buffer[size] = '\0';
          listAppend(list, nodeCreate(buffer));
        }

        buffer = malloc(sizeof(char));
        capacity = sizeof(char);
        size = 0;
        isEmpty = 1;
      }

      if (currentCharacter == '\n') {
        if (!isEmpty) {
          buffer[size] = '\0';
          listAppend(list, nodeCreate(buffer));
        }

        buffer = malloc(sizeof(char));
        capacity = sizeof(char);
        size = 0;
        isEmpty = 1;
      } else {
        if (size < capacity) {
          buffer[size++] = currentCharacter;
        } else {
          char* bridge = NULL;
          int newCapacity = capacity * 2;

          if (newCapacity <= capacity) goto operationError;

          capacity = newCapacity;
          bridge = realloc(buffer, capacity);
          if (bridge == NULL) goto operationError;

          buffer = bridge;
          buffer[size++] = currentCharacter;
        }
      }
    }

  operationError:
    free(buffer);
    fclose(file);
    return;
  }
}

void save(List* list) {
  FILE* file = fopen(FILENAME, "w");

  if (file == NULL) {
    return;
  } else {
    Node* currentNode = list->head;

    while (currentNode != NULL) {
      fputs(currentNode->data, file);
      fputc('\n', file);

      currentNode = currentNode->next;
    }
  }

  fclose(file);
}
