#include<stdio.h>
#define MAX 100

typedef struct node{
  int index ;
  struct node *next ;
}Node;

typedef struct list{
  Node *head ;
  Node *tail ;
}LinkedList;

void Init(LinkedList *list) ;
int main(){
  LinkedList *list_array[MAX] ;




  return 0 ;
}
void Init(LinkedList *list){

}
