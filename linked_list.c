#include "linked_list.h"

void addNode(Node **list, int position, Data data)
{
  if (position == 0 || *list == NULL) {
    Node *node_to_add;
    node_to_add = (Node *)malloc(sizeof(Node));
    node_to_add->next = NULL;
    node_to_add->data = data;
    node_to_add->next = *list;
    *list = node_to_add;
    return;
  }
  Node *iter;
  Node *prev;
  iter = *list;
  prev = *list;
  int i = 0;
  while (iter) {
    if (i == position) {
      break;
    }
    prev = iter;
    iter = iter->next;
    i++;
  }
  Node *node_to_add;
  node_to_add = malloc(sizeof(Node));
  node_to_add->next = NULL;
  node_to_add->data = data;
  node_to_add->next = iter;
  prev->next = node_to_add;
}

void printNode(Node *node)
{
  printf("data: %d ", node->data.a);
}

void printList(Node **list)
{
  if (!(*list)) {
    printf("list is empty\n");
    return;
  }
  Node *iter = *list;
  while (iter) {
    printf("%d ", iter->data.a);
    iter = iter->next;
  }
  printf("\n");
}

int lengthOfList(Node **list)
{
  Node *iter = *list;
  int len = 0;
  while (iter) {
    len++;
    iter = iter->next;
  }
  return len;
}

Node* getNode(Node **list, int position)
{
  Node *iter = *list;
  int i = 0;
  while (iter) {
    if (i == position) {
      break;
    }
    iter = iter->next;
    i++;
  }
  return iter;
}

void reverseList(Node **list)
{
  Node *curr = *list;
  Node *prev = NULL;
  Node *next = *list;

  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *list = prev;
}

Node deleteNode(Node **list, int position)
{
  if (!list) {
    Node temp;
    return temp;
  }
  Node *iter = *list;
  Node *prev = *list;
  bool found = false;

  int i = 0;
  while (iter) {
    if (i == position) {
      found = true;
      break;
    }
    prev = iter;
    iter = iter->next;
    i++;
  }

  if (found) {
    if (position == 0) {
      *list = iter->next;
    }
    else {
      prev->next = iter->next;
    }
    Node temp;
    temp.data = iter->data;
    temp.next = iter->next;
    free(iter);
    return temp;
  }
}

Node* sliceList(Node **list, int position_01, int position_02)
{
  Node *new_list = NULL;
  Node *iter = *list;

  int i = 0;
  bool found = false;
  while (iter) {
    if (i == position_01) {
      found = true;
      break;
    }
    iter = iter->next;
    i++;
  }
  if (!found) {
    return NULL;
  }
  while (iter) {
    if (i == position_02) {
      break;
    }
    addNode(&new_list, i - position_01, iter->data);
    iter = iter->next;
    i++;
  }
  return new_list;
}

int indexInList(Node **list, Data data)
{
  Node *iter = *list;
  int i = 0;
  while (iter) {
    if (memcmp(&data, &iter->data, sizeof(Data)) == 0) {
      return i;
    }
    iter = iter->next;
    i++;
  }
  return -1;
}

int countInList(Node **list, Data data)
{
  Node *iter = *list;
  int count = 0;
  while (iter) {
    if (memcmp(&data, &iter->data, sizeof(Data)) == 0) {
      count++;
    }
    iter = iter->next;
  }
  return count;
}

void extendList(Node **to, Node **from)
{
  int i = lengthOfList(to);
  Node *iter = *from;
  while (iter) {
    addNode(to, i, iter->data);
    iter = iter->next;
    i++;
  }
}

void clearList(Node **list)
{
  int len = lengthOfList(list);
  for (int i = 0; i < len; i++) {
    deleteNode(list, 0);
  }
}

void bubbleSort(Node **list){
  Node *x,*y;
  int temp;
  for (x=*list ; x!=NULL ; x=x->next){
    for(y=x->next ; y!=NULL ; y=y->next){
      if((x->data.a) > (y->data.a)){
        temp=y->data.a;
        y->data.a=x->data.a;
        x->data.a=temp;
      }
    }
  }
}
