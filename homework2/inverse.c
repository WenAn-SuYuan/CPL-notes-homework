//
// Created by weslie on 2023/10/13.
//
#include<stdio.h>
#define BIG 100000
int main(){
  int n ;
  scanf("%d", &n);
  getchar() ;

  char word [BIG];
  fgets(word , n + 1 ,stdin);

  int k ;
  scanf("%d",&k) ;

  char string[BIG];
  for(int i = 0 ; i <= k - 1 ; i++){
    string[i] = word[k - 1 - i];
  }

  for(int i = k  ; i < n ; i ++){
    string[i] = word[k + n - 1 - i];
  }

  printf("%s", string);
  return 0 ;
}