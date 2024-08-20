#include<stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct node{
  int index ;
  struct node *next ;
}Node;

typedef struct list{
  Node *head ;
  Node *tail ;
}LinkedList;

void Init(LinkedList *list) ;
void Append(int index, LinkedList *list) ;
int IsEmpty(LinkedList *list) ;
void query(LinkedList *list, Node *p) ;
void Delete(LinkedList *list, Node *prev) ;
int IsSingle(LinkedList *list) ;



int main(){
  LinkedList list ;
  Init(&list) ;
  for(int i = 0 ; i < MAX ; ++i){
    Append(i, &list) ;
  }









  return 0;
}
int IsSingle(LinkedList *list){
  if(list->head == list->tail && !IsEmpty(list)){
    return 1 ;
  }
  return 0 ;
}


void Init(LinkedList *list){
  list->head = NULL ;
  list->tail = NULL ;
}

int IsEmpty(LinkedList *list){
  if(list->head == NULL){
    return 1 ;
  }
  return 0 ;
}

void Append(int index, LinkedList *list){
  Node *node = malloc(sizeof *node) ;
  if(node == NULL){
  printf("????\n") ;
  return ;
}
  node->index = index ;

  if(IsEmpty(list)){
    list->head = node ;
  } else {
    list->tail->next = node ;
  }

  list->tail = node ;
  node->next = NULL ;
}
void query(LinkedList *list, Node *p){
  Node *now = p ;
  while(now != NULL){
    printf("%d", now->index) ;
    if(now->index == 6) return ;
    now = now->next ;
  }
}
void Delete(LinkedList *list, Node *prev){
  if(IsEmpty(list)) return ;
  if(IsSingle(list)){
    free(list->head) ;
    Init(list) ;
  }

  Node *cur = prev->next ;
  Node *next = cur->next ;
  prev->next = next ;

  if(list->head == cur){
    list->head = next ;
  } else if(list->tail == cur){
    list->tail = prev ;
  }

  free(cur) ;


}
void Insert(LinkedList *list, Node *prev, int index){
  Node *node ;
  node->index = index ;
  node->next = prev->next;
  prev->next = node ;

  if(list->tail == prev){
    list->tail = node ;
  }
}




