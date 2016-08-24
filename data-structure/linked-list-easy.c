#include <stdio.h>

struct node{
  int data;
  struct node *next;
};

// head pointer는 초기에는 정해지지 않았다.
struct node *head = NULL;

void insertFirst(int data){

  // node를 만든다.
  // node의 크기만큼 메모리 공간을 확보한다.
  struct node *link = (struct node*) malloc(sizeof(struct node));

  // pointer의 member에 접근할 때는 arrow operator를 쓴다고 한다.
  link->data = data;
  // 다음 노드는 기존에 존재하던 노드를 가르킨다.
  // 왜냐하면 함수의 목적이 linked list의 앞에 node를 추가하는 작업이기 때문
  link->next = head;
  // 이제 새로 만든 노드는 head pointer가 되었다.
  head = link;

}

void append(int data){

}

void printHead(){
  struct node *ptr = head;
  printf("pointer : %p", ptr);
}

int main(int argc, char const *argv[]) {

  insertFirst(10);
  insertFirst(20);
  insertFirst(14);
  insertFirst(19);

  printHead();

  return 0;
}
