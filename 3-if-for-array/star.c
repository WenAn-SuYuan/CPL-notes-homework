//
// Created by weslie on 2023/10/16.
//
#include<stdio.h>
int main() {
  int lines = 0 ;
  scanf("%d",&lines) ;


  for(int i = 0 ; i < lines ; ++i){
    for(int j = 0 ; j < lines - i - 1 ; ++j){
      printf(" ");
    }


    for(int j = 0 ; j < 2 * i + 1 ; ++j){
      printf("*");
    }
    if(i < lines - 1){
      printf("\n") ;
    }

  }
  return 0 ;
}
