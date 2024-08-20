//
// Created by weslie on 2023/11/16.
//
#include<stdio.h>

int Tiles(int n) ;
int main(){
  int n = 0 ;
  scanf("%d" , &n) ;

  int ans = Tiles(n) ;

  printf("%d" , ans) ;

  return 0 ;
}
int Tiles(int n){
  if(n <= 2){
    return n ;
  }

  return Tiles(n - 1) + Tiles(n - 2) ;
}