//
// Created by weslie on 2023/11/16.
//
#include<stdio.h>
int Pascal(int a , int b) ;
int main(){
  int a = 0 , b = 0 ;
  scanf("%d %d" , &a , &b) ;

  int ans = Pascal(a , b) ;
  printf("%d" , ans) ;

  return 0 ;
}
int Pascal(int a, int b){
  if(b == 1 || b == a){
    return 1 ;
  }

  return Pascal(a - 1 , b) + Pascal(a - 1 , b - 1) ;

}