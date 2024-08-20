//
// Created by weslie on 2023/12/23.
//
#include<stdio.h>
#include <string.h>
#define LEN 10005
#define MAX(p, q) ( (p) > (q) ? (p) : (q) )
void Print(int array[], int len, char name[]) ;
int main(){
  int p = 0 , q = 0 ;
  scanf("%d %d", &p , &q) ;
  char name[11] ;
  scanf("%s", name) ;
  int num1[LEN] = { 0 }, num2[LEN] = { 0 } ;

  for(int i = p ; i >= 0 ; --i) scanf("%d", &num1[i]) ;
  for(int i = q ; i >= 0 ; --i) scanf("%d", &num2[i]) ;

  int array[2 * LEN] = { 0 };
  for(int i = MAX(p , q) ; i >= 0 ; --i) array[i] = num1[i] + num2[i] ;
  Print(array, MAX(p,q), name) ;
  printf("\n") ;
  memset(array, 0 ,2 * LEN) ;

  for(int i = MAX(p, q); i >= 0 ; --i) array[i] = num1[i] - num2[i] ;
  Print(array, MAX(p, q) , name) ;
  printf("\n") ;
  memset(array, 0 ,2 * LEN) ;

  for(int i = p ; i >= 0 ; --i){
    for(int j = q ; j >= 0 ; --j){
      array[i + j] += (num1[i] * num2[j]) ;
    }
  }

  Print(array, p + q , name) ;


  return 0 ;
}

void Print(int array[], int len, char name[]){
  for(int i = len ; i >= 1 ; --i){
    if(array[i] == 0) {
      --len ;
      continue ;
    }
    if(array[i] > 0 && i != len) printf("+") ;
    if(array[i] != 1 && array[i] != -1){
      printf("%d", array[i]) ;
    } else if(array[i] == -1) {
      printf("-") ;
    }

    printf("%s", name);
    if(i != 1) printf("^%d", i) ;

  }

  if(array[0] > 0) printf("+") ;
  if(array[0] != 0) printf("%d", array[0]) ;

  if(!len && array[0] == 0) printf("0") ;

  return ;
}