//
// Created by weslie on 2023/10/12.
//
#include<stdio.h>
#define BIGGEST 105
int main(){

  int n = 0 ;
  scanf("%d",&n) ;  //input n

  int numbers[BIGGEST] = { 0 };
  for(int i = 0 ; i < BIGGEST && i < (2 * n - 1 ); i++){
    scanf("%d",&numbers[i]);
  }

  int numbers1[10 * BIGGEST] = {0};
  for(int i = 0 ; i < 10 * BIGGEST && i < (2 * n - 1 ) ; i++){
    numbers1[numbers[i]]++ ;
  }

//debug section
  /*for(int i = 0 ; i < 6 ; i++){
      printf("%d\n",numbers1[i]);
  }*/
//debug section end

  for(int i = 0 ; i < 10 * BIGGEST ; i++){
    if (numbers1[i] == 1){
      printf("%d",i);
      break;
    }
  }

  return 0 ;
}