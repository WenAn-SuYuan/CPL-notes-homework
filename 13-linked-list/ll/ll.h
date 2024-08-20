//
// Created by weslie on 2023/12/30.
//

//macro(宏)
#ifndef LEARNCPL2_13_LINKED_LIST_LL_LL_H_
#define LEARNCPL2_13_LINKED_LIST_LL_LL_H_
//写代码位置

#include <stdbool.h>
//(1) define data type : linked list(循环的链表）
typedef struct node{
  int index ;
  struct node *next ; //良定义：定义后能够确定所占内存
  //Node *next 不行：还不知道Node是谁
} Node;

typedef struct list {
  Node *head ;
  Node *tail ;
} LinkedList;


//（2）functions on linked list (只放声明）
void Init(LinkedList *list) ; //初始化 //经常传入指针
void Free(LinkedList *list) ; //释放
void Append(LinkedList *list, int index) ;
void Print(LinkedList *list) ;
bool IsSingleton(LinkedList *list) ;
void Delete(LinkedList *list, Node *prev) ;
int GetHeadVal(const LinkedList *list) ;
void Insert(LinkedList *list, Node *prev, int index) ;//插入节点
Node *Search(LinkedList *list, int index) ; //搜索



#endif //LEARNCPL2_13_LINKED_LIST_LL_LL_H_
