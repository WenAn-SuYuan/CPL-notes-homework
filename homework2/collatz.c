//
// Created by weslie on 2023/10/26.
//
#include<stdio.h>
int main(){
  int n = 0 ;
  scanf("%d",&n) ;

  int max = n ;
  int i = 0 ;
  for( i = 0 ; n > 1 ; i++){
    if(n % 2 == 0){
      n = n / 2 ;
    } else {
      n = 3 * n + 1;
    }
    if (n >= max){
      max = n ;
    }
  }

  printf("%d %d", i, max);

  return 0 ;
}