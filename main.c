#include <stdio.h>
#include "linked_list.h"

int main()
{
  Node *list = NULL;
  Data data;
  printf("----------------------------------------------------------------\n");
  printf("------------------------Linked List-----------------------------\n");
  printf("Press the corresponding number to do the appropriate function. \n");
  printf(" 1. Add node\n");
  printf(" 2. View the list\n");
  printf(" 3. Find the length of the list\n");
  printf(" 4. Reverse the list\n");
  printf(" 5. Get node at position\n");
  printf(" 6. Delete a element of the list\n");
  printf(" 7. Slice the list\n");
  printf(" 8. Find the index of a particular element\n");
  printf(" 9. Count a particular element in a list\n");
  printf("10. Sort \n");
  printf("11. Clear the list\n");
  printf("12. Exit\n");
  while (true) {
    int num;
    printf("What would you like to do ? ");
    scanf("%d", &num);

    if (num == 1) {
      int i_data;
      int position;
      printf("Enter Data and Position: ");
      scanf("%d%d", &i_data, &position);
      data.a = i_data;
      addNode(&list, position, data);
    }
    else if (num == 2) {
      printf("List: ");
      printList(&list);
    }
    else if (num == 3) {
      int len = lengthOfList(&list);
      printf("Length: %d\n", len);
    }
    else if (num == 4) {
      reverseList(&list);
    }
    else if (num == 5) {
      int position;
      printf("Enter the position: ");
      scanf("%d", &position);
      Node *node = getNode(&list, position);
      printNode(node);
    }
    else if (num == 6) {
      int position;
      printf("Enter position for Deletion: ");
      scanf("%d", &position);
      deleteNode(&list, position);
    }
    else if (num == 7) {
      int start, end;
      printf("Enter start and end for slice: ");
      scanf("%d%d", &start, &end);
      Node *slice = sliceList(&list, start, end);
      printList(&slice);
    }
    else if (num == 8) {
      int temp;
      printf("Enter data to find position: ");
      scanf("%d", &temp);
      data.a = temp;
      int index = indexInList(&list, data);
      printf("Index: %d", index);
    }
    else if (num == 9) {
      int temp;
      printf("Enter element to count: ");
      scanf("%d", &temp);
      data.a = temp;
      int count = countInList(&list, data);
      printf("Count: %d", count);
    }
    else if (num == 10) {
      bubbleSort(&list);
    }
    else if (num == 11) {
      clearList(&list);
      printf("List has been cleared\n");
    }
    else if (num == 12) {
      break;
    }
    printf("\n");
  }
  return 0;
}
