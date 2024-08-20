//
// Created by weslie on 2023/10/12.
//
#include<stdio.h>
#define MAGIC 10007
int main(){
  int n = 0 ;
  scanf("%d",&n); //input n3


  int numbers[30] = {0};

  for (int i = 0 ; i < n ; i++){
    int factorial = 1 ;
    for (int j = 1; j <= i + 1 ; j++){
      factorial = factorial * j ;
      numbers[i] = factorial ;
    }
  }


  long int numbers1[30] = {0} ;
  for (int i = 0 ; i < n; i++){
    numbers1[i] = numbers[i] % MAGIC ;//bug :   13!数据溢出
  }


  int sum1 = 0 ;
  for (int i = 0 ; i < n ; i++){
    sum1 = sum1 + numbers1[i];
  }
  // printf("%d\n",sum1);
//calculate the addend of these results

  int result = sum1 % MAGIC ;
  printf("%d", result);

  return 0 ;
}

