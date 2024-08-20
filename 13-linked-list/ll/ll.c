//
// Created by weslie on 2023/12/30.
//

#include"ll.h"
#include<stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

//此时用双引号去引用，若用<>则去系统路径寻找该文件，用“”先在自己的project去找，找不到再去系统找

// .c 文件中放函数的实现
void Init(LinkedList *list) {
  list -> head = NULL ;
  list -> tail = NULL ;
}

void Free(LinkedList *list) {

}
// 向单链表中增加节点/////////

bool IsEmpty(LinkedList *list){
  return list->head == NULL ;
}

bool IsSingleton(LinkedList *list) {
  return (!IsEmpty(list)) && (list->head == list->tail) ;
}

int GetHeadVal(const LinkedList *list){
  if(IsEmpty(list)){
    return -1 ;
  }

  assert(IsSingleton(list)) ;
  return list->head->index ;
}



void Print(LinkedList *list){
  if(IsEmpty(list)) return ;

  Node *node = list->head ;

  do {
    printf("%d ", node->index) ;
    node = node->next ;
  } while (node != list->head) ;
}


void Append(LinkedList *list, int index) {
  Node *node = malloc(sizeof *node) ;
  if(node == NULL){
    return ;
  }
  node->index = index ;

  if(IsEmpty(list)) { //不要忘记边界情况：list为空 或 list 只有单个节点
    list->head = node ;
  } else{
    list->tail->next = node ;
  }
  list->tail = node ;
  list->tail->next = list->head ;

}
void Delete(LinkedList *list, Node *prev){

  if(IsEmpty(list)) return ;

  if(IsSingleton(list)){
    free(list->head) ;
    Init(list) ;
    return ;
  }

  Node *cur = prev->next ;
  Node *next = cur->next ;

  prev->next = next ;

  if(cur == list->head){
    list->head = next ;
  } else if(cur == list->tail){
    list->tail = prev ;
  }

  free(cur) ;
}





