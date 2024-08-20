//
// Created by weslie on 2023/10/26.
//
#include<stdio.h>
#define LEN 10007
int main(){
  int fac = 1 , sum = 0 ;
  int n = 0 ;
  scanf("%d" , &n) ;
  for(int i = 1 ;i < n ; ++i){
    fac = (fac * i) % LEN ;
    sum = (sum + fac) % LEN ;
  }

  printf("%d" , sum) ;
  return 0 ;
}