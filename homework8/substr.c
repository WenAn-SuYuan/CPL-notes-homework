//
// Created by weslie on 2023/11/28.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
  int len = 100005;
  char *S = malloc(len * sizeof S) ;
  char *T = malloc(len * sizeof T) ;
  scanf("%s" , S) ;
  scanf("%s" , T) ;
  int length_T = strlen(T) ;
  int length_S = strlen(S) ;

  for(int i = 0 ; i <= length_S - length_T ; ++i){
    int flag = 1 ;
    for(int j = 0 ; j < length_T ; ++j){
      if((*(T + j) != *(S + i + j))){
        flag = 0 ;
        break ;
      }
    }

    if(flag){
      printf("%d " , i) ;
    }
  }







  return 0 ;
}