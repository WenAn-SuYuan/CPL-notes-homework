//
// Created by weslie on 2023/12/2.
//
#include<stdio.h>
int main(void){
  //char msg[] = {"H", "e" ,            }
  char msg[] = "Hello World" ;
  msg[0] = 'N' ;
  printf("%s\n" ,msg) ;

  char *ptr_msg = "Hello World" ;
  ptr_msg[0] = 'N' ;
  printf("%s\n" , msg) ;


  return 0 ;
}