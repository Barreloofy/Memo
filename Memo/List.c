/*
List.c
Memo

Created by Barreloofy on 6/5/25 at 10:32 PM
*/

#include "List.h"

Node* nodeCreate(char* data) {
  Node* node = malloc(sizeof(Node));
  if (node == NULL) return NULL;

  node->data = data;
  node->previous = NULL;
  node->next = NULL;

  return node;
}

bool nodeDestroy(Node* node) {
  if (node == NULL || (node->previous != NULL && node->next != NULL)) return false;

  free(node->data);
  free(node);

  return true;
}

List listCreate(void) {
  List list = { NULL, NULL };
  return list;
}

bool listDestroy(List* list) {
  if (list->head == NULL) {
    return true;
  } else {
    Node* nodeToDestroy = NULL;

    while ((nodeToDestroy = list->head) != NULL) {
      if (nodeToDestroy->next == NULL) {
        if (!nodeDestroy(nodeToDestroy)) {
          return false;
        } else {
          goto finish;
        }
      }

      list->head = nodeToDestroy->next;
      list->head->previous = NULL;

      if (!nodeDestroy(nodeToDestroy)) return false;
    }

  finish:
    list->head = NULL;
    list->tail = NULL;
    return true;
  }
}

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
          return nodeDestroy(currentNode);
        } else {
          list->head = currentNode->next;
          list->head->previous = NULL;

          currentNode->next = NULL;
          return nodeDestroy(currentNode);
        }
      } else if (currentNode == list->tail) {
        list->tail = currentNode->previous;
        list->tail->next = NULL;

        currentNode->previous = NULL;
        return nodeDestroy(currentNode);
      } else {
        Node* previous = currentNode->previous;
        Node* next = currentNode->next;

        previous->next = next;
        next->previous = previous;

        currentNode->previous = NULL;
        currentNode->next = NULL;
        return nodeDestroy(currentNode);
      }
    }
  }

  return false;
}

bool listView(List* list) {
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
