/*
main.c
Memo
  
Created by Barreloofy on 6/5/25 at 10:29 PM
*/

#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include "Note.h"
#include "Store.h"

void terminateProcess(List*);

int main(void) {
  List notes = listCreate();
  int choice = 0;

  load(&notes);

  printf("\n--- Memo CLI Notebook ---\n");

  while (1) {
    printf("\n");
    printf("1.  -Add\n");
    printf("2.  -Remove\n");
    printf("3.  -View\n");
    printf("4.  -Exit\n");

    printf("\nEnter Choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n');

    switch (choice) {
    case 1:
        noteAdd(&notes);
        break;
    case 2:
        noteRemove(&notes);
    case 3:
        listView(&notes);
        break;
    case 4:
        terminateProcess(&notes);
    default: break;
    }
  }
}


void terminateProcess(List* list) {
  save(list);

  if (listDestroy(list) == ERROR) {
    fprintf(stderr, "Unexpected Error While Terminating Process\n");
    return;
  } else {
    exit(EXIT_SUCCESS);
  }
}
