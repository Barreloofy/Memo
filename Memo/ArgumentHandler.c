/*
ArgumentHandler.c
Memo
  
Created by Barreloofy on 9/15/25 at 2:39 PM
*/

#include "ArgumentHandler.h"

/* Appends the contents of argumentVector to file
 * when the program gets executed with the -add flag.
 *
 * - Parameters:
 *    - argumentCount: The number of arguments passed to the program.
 *    - argumentVector: The arguments passed to the program.
 */
static void handleAdd(int argumentCount, char* argumentVector[]) {
  if (argumentCount < 3) {
    printf(
    "The -add option requires one or more text arguments. Example: %s -add Hello, World!\n",
    argumentVector[0]);
  } else {
    unsigned int index;
    FILE* file = fopen(FILENAME, "a");

    if (file == NULL) {
      printf("%s could not add note\n", argumentVector[0]);
      return;
    }

    for (index = 2; index < argumentCount; index++) {
      fprintf(
      file,
      "%s%c",
      argumentVector[index],
      (index == argumentCount -1) ? ASCIILF : ASCIISPACE);
    }

    fclose(file);
  }
}


/* The function responsible for handling any arguments passed to the program.
 *
 * - Parameters:
 *    - argumentCount: The number of arguments passed to the program.
 *    - argumentVector: The arguments passed to the program.
 */
void handleArguments(int argc, char* argv[]) {
  if (strcmp(argv[1], "-add") == 0) {
    handleAdd(argc, argv);
  } else {
    printf(
    "'%s' is not a valid option. Use -add followed by text. Example: %s -add Hello, World!\n",
    argv[1],
    argv[0]);
  }
}
