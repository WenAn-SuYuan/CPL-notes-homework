//
// Created by weslie on 2023/10/28.
//
#include<stdio.h>

int EndNum(int n , int t);
int main(){
  int n = 0 , t = 0  , sum = 0 ;
  scanf("%d %d" , &n , &t);

  for(int i = 1 ; i <= n ; ++i){
    sum += EndNum(i , t);
  }


  printf("%d\n" , sum) ;

  return 0 ;
}

int EndNum(int n , int t){
  int num = 0 ;
  for(int i = 1 , ten = 1; i <= n ; ++i){
    num += ten * t ;
    ten *= 10 ;
  }

  return num ;
}