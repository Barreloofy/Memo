/*
List.c
Memo

Created by Barreloofy on 6/5/25 at 10:32 PM
*/

#include "List.h"

/* Creates a new empty list.
 *
 * - Returns: The newly created list.
 */
List initList(void) {
  List list = { NULL, NULL };
  return list;
}


/* Deallocates all members of the list and their content.
 *
 * - Parameters:
 *    - list: The list to deallocate.
 *    - Returns: A boolean indicating if the list was successfully deallocated.
 */
bool deinitList(List* list) {
  if (list->head == NULL) {
    return true;
  } else {
    Node* nodeToDestroy = NULL;

    while ((nodeToDestroy = list->head) != NULL) {
      if (nodeToDestroy->next == NULL) {
        if (!deinitNode(nodeToDestroy)) {
          return false;
        } else {
          goto finish;
        }
      }

      list->head = nodeToDestroy->next;
      list->head->previous = NULL;

      if (!deinitNode(nodeToDestroy)) return false;
    }

  finish:
    list->head = NULL;
    list->tail = NULL;
    return true;
  }
}


/* Appends the specified node to list.
 *
 * - Parameters:
 *    - list: The list to append to.
 *    - node: The node to append.
 * - Returns: A boolean indicating if node was successfully added to list.
 */
bool listAppend(List* list, Node* node) {
  if (node == NULL) return false;

  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    Node* tail = list->tail;

    tail->next = node;
    node->previous = tail;

    list->tail = node;
  }

  return true;
}


/* Removes a node from list specifed by its index.
 *
 * - Parameters:
 *    - list: The list to remove from.
 *    - index: The corresponding idnex of the node to remove.
 * - Returns: A boolean indicating if node was successfully removed from list.
 */
bool listRemove(List* list, unsigned int index) {
  unsigned int count = 1;
  Node* currentNode = list->head;

  while (currentNode != NULL) {
    if (count != index) {
      currentNode = currentNode->next;
      count++;
    } else {
      if (currentNode == list->head) {
        if (currentNode == list->tail) {
          list->head = NULL;
          list->tail = NULL;
          return deinitNode(currentNode);
        } else {
          list->head = currentNode->next;
          list->head->previous = NULL;

          currentNode->next = NULL;
          return deinitNode(currentNode);
        }
      } else if (currentNode == list->tail) {
        list->tail = currentNode->previous;
        list->tail->next = NULL;

        currentNode->previous = NULL;
        return deinitNode(currentNode);
      } else {
        Node* previous = currentNode->previous;
        Node* next = currentNode->next;

        previous->next = next;
        next->previous = previous;

        currentNode->previous = NULL;
        currentNode->next = NULL;
        return deinitNode(currentNode);
      }
    }
  }

  return false;
}


/* Displays the content of the list's nodes,
 * in the order they were added to list.
 *
 * - Parameters:
 *    - list: The list to display.
 * - Returns: A boolean indicating if list is empty.
 */
bool listView(const List* list) {
  if (list->head == NULL) {
    printf("\n--- No Note's Yet! ---\n");
    return false;
  } else {
    Node* currentNode = list->head;
    unsigned int count = 1;

    printf("\n--- All Notes ---\n");
    while (currentNode != NULL) {
      printf("%d. %s\n", count++, currentNode->data);
      currentNode = currentNode->next;
    }
    printf("--- All Notes ---\n");

    return true;
  }
}
