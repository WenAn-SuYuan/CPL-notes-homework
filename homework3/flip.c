//
// Created by weslie on 2023/10/16.
//
#include<stdio.h>
int main(){
  int n =  0 ;
  int numbers[2005] = { 0 } ;
  scanf("%d", &n) ;

  for(int i = 1 ; i <= n ; ++i){
    for(int j = 1 ; j <= n ; ++j){
      if (j % i == 0){
        if(numbers[j] == 0){
          numbers[j] = 1;
        } else {
          numbers[j] = 0 ;
        }
      }
    }
  }

  for(int i = 1 ; i <= n ; ++i){
    if(numbers[i] == 1){
      printf("%d ", i);
    }
  }

  return 0 ;
}