//
// Created by weslie on 2023/10/14.
//
#include<stdio.h>
#include<math.h>
int main(){
  int a ,b , c , d , e ;
  printf("Enter ISBN :") ;
  scanf("%d-%d-%d-%d-%d" , &a , &b , &c , &d , &e ) ;
  printf("GS! prefix: %d\n", a) ;
  printf("Group Identifier: %d\n", b) ;
  printf("Publisher code: %d\n", c) ;
  printf("Item number: %d\n" , d) ;
  printf("Check digit : %d\n" , e) ;



  return 0 ;
}

