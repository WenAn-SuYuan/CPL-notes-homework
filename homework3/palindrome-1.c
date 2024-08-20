//
// Created by weslie on 2023/10/16.
//
#include<stdio.h>
#define MAX 10005
int main(){
  int n = 0 ;
  char numbers[MAX] = { 0 };
  scanf("%d", &n) ;
  getchar();
  scanf("%s",numbers);

  for(int i = 0 ; i < n && i < MAX ; ++i) {
    if (numbers[i] == '?') {
      numbers[i] = numbers[n - 1 - i];
    }
  }

  printf("%s",numbers);
  return 0 ;
}