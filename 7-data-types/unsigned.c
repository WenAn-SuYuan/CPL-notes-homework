//
// Created by weslie on 2023/11/20.
//
#include<stdio.h>
int main(){
  int array[] = {0 , 1 ,2 ,3 ,4} ;
  int i = -1 ;

  size_t size = sizeof array ; //实际类型是一个无符号的long long或无符号int
   printf("The size of the array is : %zu\n" , size) ;

   if(i <= size){
     printf("i <= sizeof array\n");
   } else {
     printf("i > sizeof array\n") ;
   }
/**
 * 为什么输出i 大于 sizeof array？
 *此时i带符号，size无符号，所以i被升级为无符号，其码大于size
 *所以，慎用无符号类型 ， 除非位运算
 *
 *
 */

  return 0 ;
}