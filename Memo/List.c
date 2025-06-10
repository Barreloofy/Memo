/*
List.c
Memo
  
Created by Barreloofy on 6/5/25 at 10:32 PM
*/

#include "List.h"

/* Node functions */

Node* nodeCreate(char* data) {
  Node* node = malloc(sizeof(Node));
  if (node == NULL) return NULL;

  node->data = data;
  node->previous = NULL;
  node->next = NULL;

  return node;
}

Result nodeDestroy(Node* node) {
  if (node == NULL || (node->previous != NULL && node->next != NULL)) {
    return ERROR;
  }
  free(node->data);
  free(node);
  return SUCCESS;
}

/* List functions initialize & destroy */

List listCreate(void) {
  List list = { NULL, NULL };
  return list;
}

Result listDestroy(List* list) {
  if (list->head == NULL) {
    return SUCCESS;
  } else {
    Node* oldHead = NULL;

    while ((oldHead = list->head) != NULL) {
      if (oldHead->next == NULL) {
        if (nodeDestroy(oldHead) == ERROR) return ERROR;
        break;
      }

      list->head = oldHead->next;
      list->head->previous = NULL;

      if (nodeDestroy(oldHead) == ERROR) return ERROR;
    }

    list->head = NULL;
    list->tail = NULL;

    return SUCCESS;
  }
}

/* List functions operations */

Result listAppend(List* list, Node* node) {
  if (node == NULL) return ERROR;

  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    Node* tail = list->tail;

    tail->next = node;
    node->previous = tail;

    list->tail = node;
  }

  return SUCCESS;
}

Result listRemove(List* list, unsigned index) {
  unsigned count = 0;
  Node* currentNode = list->head;

  while (currentNode != NULL) {
    if (count != index) {
      currentNode = currentNode->next;
      count++;
    } else {
      Node* previous = currentNode->previous;
      Node* next = currentNode->next;

      if (currentNode == list->head) {
        if (currentNode == list->tail) {
          list->head = NULL;
          list->tail = NULL;
          return nodeDestroy(currentNode);
        } else {
          list->head = currentNode->next;
          list->head->previous = NULL;

          currentNode->next = NULL;
          return nodeDestroy(currentNode);
        }
      }

      if (currentNode == list->tail) {
        list->tail = currentNode->previous;
        list->tail->next = NULL;

        currentNode->previous = NULL;
        return nodeDestroy(currentNode);
      }

      previous->next = next;
      next->previous = previous;

      currentNode->previous = NULL;
      currentNode->next = NULL;
      return nodeDestroy(currentNode);
    }
  }

  return ERROR;
}

Node* listRetrieve(List* list, unsigned index) {
  if (list->head == NULL) {
    return NULL;
  } else {
    unsigned count = 0;
    Node* currentNode = list->head;

    while (currentNode != NULL) {
      if (count == index) {
        return currentNode;
      } else {
        currentNode = currentNode->next;
      }
    }

    return NULL;
  }
}

int listIsEmpty(List* list) {
  return list->head == NULL;
}

Result listView(List* list) {
  if (list->head == NULL) {
    printf("\n--- No Note's Yet! ---\n");
    return ERROR;
  } else {
    Node* currentNode = list->head;
    int count = 1;

    printf("\n--- All Notes ---\n");

    while (currentNode != NULL) {
      printf("%d. %s\n", count++, currentNode->data);
      currentNode = currentNode->next;
    }

    printf("--- All Notes ---\n");

    return SUCCESS;
  }
}
