//
// Created by weslie on 2023/11/28.
//
#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
int main(){
  int len = 10005 ;
  char *string = malloc(len * sizeof string) ;
  while(scanf("%s" , string) != EOF){
    if(*(string) >= 'a'){
      *(string) += 'A' - 'a' ;
    }

    for(int i = 1 ; i < strlen(string) ;++i){
      if(*(string + i) <= 'Z'){
        *(string + i) += 'a' - 'A' ;
      }
    }

    printf("%s " , string);
  }




  return 0 ;
}