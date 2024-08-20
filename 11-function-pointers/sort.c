//
// Created by weslie on 2023/12/19.
//
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <string.h>
/**
 * void qsort(void *ptr, size_t count , size_t size , int (*comp)(const void * , const void *)) ;
 * 参数用void：不知道会排序什么类型 选用最宽泛的
 *comp 接受的不是数，是数的指针
 *comp传指针原因：1.性能，无需拷贝 2.不存在const void，无法接着写
 */

typedef int (*CompareFunction)(const void *, const void *) ;//给函数指针一个类型，不同于以往typedef语法

void PrintInts(const int *integers, size_t len) ;
void PrintStrs(const char *str[], size_t len) ;
int CompareInts(const void *left, const void *right) ;
int CompareStrs(const void *left, const void *right) ;
int CompareStrWrong(const void *left, const void *right) ;


int main(){

  int integers[] = {-2 , 99, 0 , -743, 2, INT_MIN , 4} ;
  int size_of_integers = sizeof integers / sizeof *integers ;

  //int (*comp)(const void * , const void *) = CompareInts ;
  CompareFunction comp = CompareInts ;  //typedef 后当作int double 一样使用就好
  /**
   * comp是一个函数指针，指向CompareInt
   */

  qsort(integers, size_of_integers, sizeof integers[0], CompareInts) ;
  printf("%x\n\n\n", CompareInts) ;

  PrintInts(integers, size_of_integers) ;

  const char *names[] = {
      "Luo Dayou",
      "Cui Jian",
      "Dou Wei",
      "Zhang Chu" ,
      "Wan Qing",
      "Li Zhi",
      "Yao",
      "ZuoXiao",
      "Ershou Rose",
      "Hu Mage"
  } ;

  size_t size_of_names = sizeof names /sizeof *names ;

  qsort(names, size_of_names, sizeof names[0],
        CompareStrs) ;
  PrintStrs(names, size_of_names) ;

  return 0 ;
}
//
int CompareInts(const void *left, const void *right){
  /**
   * 目标：确定left right类型
   * 现在只知道left right是指针，但不知道是什么类型的指针
   * 实际上，我们要比较两个整数的大小
   * 所以，类型为int *， 所以将left right由void *强制转换为int *
   */

  const int *left_int = left ; //指针类型强制转换
  int right_int = *(const int *)right ;

  return (*left_int > right_int) - (*left_int < right_int) ;
  //这一行达到了三个if效果：大于返回1，小于-1， 等于0

}

int CompareStrs(const void *left, const void *right){
  //left, right : char **
  //被比较的是两个char *
  //他们是char **
  const char *const *left_str = (const char **)left ;//为什么没有像int那样的强制类型转换？????????????????????
  const char *const *right_str = right ;

  return strcmp(*left_str, *right_str) ; //strcpm needs char *
}

int CompareStrWrong(const void *left, const void *right){
  const char *left_str = left ;
  const char *right_str = right ;

  return strcmp(left_str, right_str) ;
}
//错因：此时按照地址排序


void PrintInts(const int *integers, size_t len){
  for(int i = 0 ; i < len ; ++i) printf("%d\n", integers[i]) ;
}

void PrintStrs(const char *str[], size_t len){
  for(int i = 0 ; i < len ; ++i) printf("%s\n", *(str + i)) ;
}
