//
// Created by weslie on 2023/10/16.
//
#include<stdio.h>

void Print(char ch , int count) ;
int main() {
  int lines = 0 ;
  scanf("%d",&lines) ;


  for(int i = 0 ; i < lines ; ++i){
    Print(' ' , lines - i - 1);
    Print('*' , 2 * i + 1) ;

    if(i < lines - 1){
      printf("\n") ;
    }

  }
  return 0 ;
}

void Print(char ch , int count) {
  for (int i = 0; i < count; ++i) {
    printf("%c", ch);
  }
}