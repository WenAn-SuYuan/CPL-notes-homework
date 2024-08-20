//
// Created by weslie on 2023/10/25.
//
#include<stdio.h>
#define LEN 1005
int main() {
  int n = 0;
  scanf("%d", &n);
  char str[LEN];
  scanf("%s", str);

  int numbers[150] = {0};

  for (int i = 0; i < n; ++i) {
    ++numbers[str[i]];
  }
  //桶计数
  int tem[150] = {0};
  for(int i = 'A' ; i <= 'z' ; ++i ){
    tem[i] = numbers[i] ;
  }

  int max = numbers['A'];
  for (int i = 'A'; i <= 'z'; ++i) {
    if (numbers[i] >= max) {
      max = numbers[i];
    }
  }
  //寻找max

  int exist = 0 ;

  int flag = 0 ;
  while (max > 0) {

    for (int i = 'a'; i <= 'z'; ++i) {
      flag = 0 ;
      if (numbers[i] != 0) {
        flag = 1 ;
        if (numbers[i] == max) {
          printf("=");
          --numbers[i] ;
        } else {
          printf(" ");
        }
      }

      if (numbers[i - 'a' + 'A'] != 0) {
        flag = 1 ;
        if (numbers[i - 'a' + 'A'] == max) {
          printf("=");
          --numbers[i - 'a' + 'A']  ;
        } else {
          printf(" ");
        }
      }

      if(flag) {
        printf(" ");
        exist = i ;
      }
    } //循环a 至 z ，输出每行


      printf("\n") ;
      --max ;
  }

  int nag = 0 ;
  for(int i = 'a' ; i <= 'z' ; ++i){
    nag = 0 ;
    if(tem[i] != 0){
      nag = 1 ;
      printf("-") ;
    }

    if(tem[i - 'a' + 'A'] != 0 ){
      nag = 1 ;
      printf("-") ;
    }
    if(nag && i != exist) {
      printf("-");
    }
  }

  printf("\n") ;
  int sign = 0 ;
  for(int i = 'a' ; i <= 'z' ; ++i){
    sign = 0 ;
    if(tem[i] != 0 ){
      sign = 1 ;
      printf("%c" , i) ;
    }

    if(tem[i - 'a' + 'A'] != 0 ){
      sign = 1 ;
      printf("%c" , i - 'a' + 'A') ;
    }
    if(sign) {
      printf(" ");
    }
  }



  return 0 ;
}