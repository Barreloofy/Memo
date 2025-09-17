/*
Node.c
Memo
  
Created by Barreloofy on 9/16/25 at 7:06 PM
*/

#include "Node.h"

/* Creates a new node with the specified null-terminated string.
 *
 * - Parameters:
 *    - data: A null-terminated string.
 * - Returns: On Success The pointer of the newly created node otherwise NULL.
 */
Node* initNode(char* data) {
  if (data == NULL) {
    return NULL;
  } else {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) return NULL;

    node->data = data;
    node->previous = NULL;
    node->next = NULL;

    return node;
  }
}


/* Deallocates node and its data.
 *
 * - Parameters:
 *    - node: The node to deallocate.
 * - Returns: A boolean indicating if the node was successfully deallocated.
 */
bool deinitNode(Node* node) {
  if (node == NULL) return false;

  free(node->data);
  free(node);

  return true;
}
