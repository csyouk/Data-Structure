// http://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
  int key;
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

// 리스트를 전부 보여준다.
void printList()
{
  struct node *ptr = head;
  printf("\n[ ");
  // 처음부터 보여준다.
  while(ptr != NULL)
  {
    // -> left to right operator.
    // arrow operator 라고 부른다.
    // access a member of a struct
    // which is referenced by the pointer
    printf("(%d,%d,%p) ", ptr->key, ptr->data, ptr->next);
    ptr = ptr -> next;
  }
  printf("]\n");
}

void insertFirst(int key, int data)
{
  struct node *link = (struct node*) malloc(sizeof(struct node));
  link->key = key;
  link->data = data;
  link->next = head;
  head = link;
}

struct node* deleteFirst()
{
  struct node *tempLink = head;
  head = head -> next;
  return tempLink;
}

bool isEmpty()
{
  return head == NULL;
}

int length()
{
  int length = 0;
  struct node *current;
  for (current = head; current != NULL; current = current -> next) {
    length++;
  }
  return length;
}

struct node* find(int key){
  struct node* current = head;
  if(head==NULL)
  {
    return NULL;
  }

  while(current -> key != key)
  {
    if(current -> next == NULL)
    {
      return NULL;
    } else {
      current = current->next;
    }
  }
  return current;
}

struct node* delete(int key)
{
  struct node* current = head;
  struct node* previous = NULL;
  if(head==NULL){
    return NULL;
  }
  while(current -> key != key)
  {
    if(current->next == NULL)
    {
      return NULL;
    } else {
      previous = current;
      current = current->next;
    }
  }
  if(current == head){
    head = head->next;
  }else{
    previous->next = current->next;
  }
  return current;
}



int main(){
  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);
  insertFirst(4,1);
  insertFirst(5,40);
  insertFirst(6,56);

  printf("original list : ");
  printList();

  printf("Length of node : %d\n", length());
  return 0;
}
