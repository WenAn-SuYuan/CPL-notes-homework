//
// Created by weslie on 2023/10/25.
//
#include<stdio.h>
#define BIG 1000
int main(){
  int n = 0 , a = 0 ;
  scanf("%d" , &n) ;
  int array[10 * BIG] = { 0 } ;
  for(int i = 0 ; i < 2 * n - 1 ; ++i){
    scanf("%d" , &a) ;
    ++array[a] ;
  }

  for(int i = 0 ; i < 10 * BIG ; ++i){
    if(array[i] == 1){
      printf("%d" , i) ;
    }
  }


  return 0 ;
}