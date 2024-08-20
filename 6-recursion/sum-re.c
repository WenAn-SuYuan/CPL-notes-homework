//
// Created by weslie on 2023/11/16.
//
#include<stdio.h>

int Sum(const int numbers[] ,int len) ;

int main(){
  const int numbers[] = {1, 2, 3, 4, 5};
  int sum = Sum(numbers , sizeof numbers / sizeof numbers[0]) ;

  //int sum = Sum(numbers , sizeof numbers / sizeof(int)) ;
  //sizeof 后跟类型（要加括号） ： 计算这种类型占多大空间
  //       后跟变量名： 计算该变量占多大空间
  //该用现在的方法避免后续想更改类型时麻烦

  printf("%d", sum) ;

  return 0 ;
}

int Sum(const int numbers[] , int len){
  if(len == 0){
    return 0 ;
  }

  int partial_sum = Sum(numbers , len - 1) ;
  return partial_sum + numbers[len - 1] ;

}