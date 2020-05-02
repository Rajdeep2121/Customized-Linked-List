#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct Data {
  int a;
} Data;

typedef struct Node {
  Data data;
  struct Node *next;
} Node;

void addNode(Node **list, int position, Data data);
void printList(Node **list);
void printNode(Node *node);
int lengthOfList(Node **list);
void reverseList(Node **list);
Node* getNode(Node **list, int position);
Node deleteNode(Node **list, int position);
Node* sliceList(Node **list, int position_01, int position_02);
int indexInList(Node **list, Data data);
int countInList(Node **list, Data data);
void extendList(Node **to, Node **from);
void clearList(Node **list);
void bubbleSort(Node **list);

#endif
