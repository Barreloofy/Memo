/*
main.c
Memo

Created by Barreloofy on 6/5/25 at 10:29 PM
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Bool.h"
#include "Ascii.h"
#include "List.h"
#include "Note.h"
#include "Store.h"
#include "ArgumentHandler.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    List notes = initList();
    unsigned int choice = 0;

    load(&notes);

    printf("\n--- Memo CLI Notebook ---\n");

    while (true) {
      printf(
      "\n"
      "1.  -Add\n"
      "2.  -Remove\n"
      "3.  -View\n"
      "4.  -Exit\n"
      "\n"
      );

      printf("Enter Choice: ");
      scanf("%u", &choice);
      while (getchar() != ASCIILF);

      switch (choice) {
      case 1:
        noteAdd(&notes);
        break;
      case 2:
        noteRemove(&notes);
        break;
      case 3:
        listView(&notes);
        break;
      case 4:
        save(&notes);
        exit(EXIT_SUCCESS);
      default: break;
      }
    }
  } else {
    handleArguments(argc, argv);
  }
}
