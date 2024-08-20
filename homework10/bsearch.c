//
// Created by weslie on 2023/12/19.
//
#include<stdio.h>
#include<stdlib.h>
#define LEN 10000

int compare(const void *a , const void *b) ;
int main(){
  int n = 0 , q = 0 ;
  scanf("%d %d", &n , &q) ;
  int *numbers = malloc(LEN * sizeof(int)) ;
  int *numbers_move1 = numbers ;
  int *numbers_move2 = numbers ;
  int *numbers_end = numbers + n ;
  while(numbers_move2 < numbers_end){
    scanf("%d", numbers_move2) ;
    ++numbers_move2 ;
  }
  //numbers_move2 quit
  while(q--){
    int key = 0 ;
    scanf("%d", &key) ;
    int *num = bsearch(&key, numbers, n ,sizeof(int), compare) ;
    if(num != NULL){
      printf("%d\n", num - numbers) ;
    } else {
      printf("-1\n") ;
    }
  }


  free(numbers) ;
  return 0 ;
}
int compare(const void *a , const void *b){
  return (*(int *)a - *(int *)b) ;
}
