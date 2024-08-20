//
// Created by weslie on 2023/12/31.
//
#include<stdio.h>
#include <stdlib.h>

typedef struct node {
  int val ;
  struct node *next ;
} Node ;

Node *head, *tail ;
//变量区（上面）


Node *get_node();
//函数声明区

void insert_before_head(int x) ;
void insert_after_tail(int x) ;
void query(Node *head) ;
void insert(Node *node , int x) ;


int main(){
  //head = NULL ;

  head = get_node() ;
  Node *temp = head ;
  head->val = 1 ;
  tail = head ;

  for(int i = 10 ; i < 20 ; ++i){
    insert_before_head(i) ;
  }

  for(int i = 2 ; i < 10 ;++i){
    insert_after_tail(i) ;
  }
  return 0 ;
}
Node *get_node(){
  Node *node = malloc(sizeof (node)) ;
  node->next = NULL ;
  node->val = 0;
  return node ;
};
//创建链表
void insert_before_head(int x){
  Node *p = get_node() ;

  p->val = x ;
  p->next = head ;

  head = p ;
}
void insert_after_tail(int x){
  Node *p = get_node() ;

  p->val = x ;
  p->next = NULL ;
  tail->next = p ;
  tail = p ;
}
void query(Node *head){



}
void insert(Node *node , int x){
   Node *p = get_node() ;
   p->val = x ;
   p->next = node->next ;
   node->next = p ;

   if(node == tail){
     tail = p ;
   }
}

void insert_before_it(Node *node, int x) ;







