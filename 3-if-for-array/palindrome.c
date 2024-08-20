//
// Created by weslie on 2023/10/23.
//
#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#define LEN 21
char string[LEN] = " " ;
int main(){
  scanf("%20s" , string) ;

  int length = strlen(string) ;

  bool is_palindrome = true ;
  for(int i = 0 , j = length - 1 ; i < j ; i++ , j--){
    if(string[i] != string[j]){
      is_palindrome = false ;
      break ;
    }
  }

  if(is_palindrome){
    printf("Yes") ;
  } else {
    printf("No") ;
  }


  return 0 ;
}