//
// Created by weslie on 2023/10/16.
//
#include<stdio.h>
int main(){
  int n = 0 ;
  int k = 0 ;
  scanf("%d", &n) ;
  scanf("%d", &k) ;

  int count = n ;
  int numbers[1000] = { 0 };
  for(int i = 1 ; i <= count ; ++i){
    numbers[i] =  1 ;
  }

  for(int i = 0 ; n > 1 ; n-- ){
    for (int add = 0 ; add < k ; ){
      add = add + numbers[i] ;
      if (add == k){
        break ;
      }
      i = (i + 1) % (count + 1) ;
    }
    numbers[i] = 0 ;

  }

  for(int i = 0 ; i <= count ; ++i){
    if(numbers[i] == 1){
      printf("%d", i) ;
    }
  }



  return 0 ;
}
