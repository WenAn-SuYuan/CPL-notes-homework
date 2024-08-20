//
// Created by weslie on 2023/11/20.
//
#include<stdio.h>
#include<limits.h>
int main(){
  printf("UINT_MAX= %u\n" , UINT_MAX) ;

  unsigned int max = UINT_MAX;
  unsigned int one = 1u ;
  unsigned int two = 2u ;
  printf("max + one = %u\n" , max + one) ;
  printf("one - two = %u\n" , one - two) ;
  /**
   * 回绕现象
   */


  return 0 ;
}