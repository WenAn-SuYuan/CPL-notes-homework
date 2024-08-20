//
// Created by weslie on 2023/12/20.
//
#include<stdio.h>
int main(){
  char **argv ;

  int *names[10] ;//数组中有10个值，每个都是int *

  int (*musician_score_table)[10] ;
  //二维数组

  char *StrCpyStd(char *dest, const char *src) ;
  //一个函数，接受两个char *， 返回一个char *


  int (*comp)(const void *left, const void *right) ;
  //comp 为函数指针，指向一个函数，该函数接受两个void *(可转换，至少是个指针），返回一个int

  int atexit(void (*func)(void)) ;
  //一个函数，函数接受一个参数，这个参数本身是函数指针，指针指向一个接受void并返回void的函数，atexit本身返回值为int

  void (*signal(int sig, void (*handler)(int)))(int) ;
  //signal 是一个函数，函数接收两个参数，一个是int ，一个是函数指针，该指针指向一个接收int返回void的函数，
//signal返回一个指针，该指针指向一个函数，该函数接收int， 返回void
/**
 * 有空解读这个声明，似乎没太理解
 */
  char (*(*func(int num, char *str))[])() ;
  //func是一个函数，接收一个int 和一个char *， 返回一个指针
  //该指针指向一个数组，数组里的每一个元素指向一个指向函数的指针，这个函数没有参数，返回char

  char (*(*arr[3])())[5] ;
  //arr是一个数组，每个元素是一个指针，指针指向一个函数，该函数没有参数，返回值是一个指针，指针指向一个数组，数组里面每一个元素都是char

  return 0 ;
}
/**
* 老师给了两个练习网站，去找一下！！！！
*/