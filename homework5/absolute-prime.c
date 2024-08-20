//
// Created by weslie on 2023/10/29.
//
#include<stdio.h>
#include<math.h>
int IsPrime(int x) ;
int main(){
  int n = 0 ;
  scanf("%d" , &n);

  int count = 0 ;
  for(int i = 2 ; i <= n ; ++i){
    int flag = IsPrime(i) ;
    if(i < 10 && flag){
      ++count ;
    }

    if(i > 10 && i < 100 && flag){
      int nag = IsPrime((i / 10) + 10 * (i % 10)) ;
      if(nag){
        ++count ;
      }
    }

    if(flag && i > 100){
      int sign = IsPrime(i / 100 + 10 * ((i / 10) % 10) + 100 * (i % 10)) ;
      if(sign){
        ++count ;
      }
    }
  }

  printf("%d" , count) ;


  return 0 ;
}

int IsPrime(int x){
  int flag = 1; // 1 表示该数是素数
  for (int i = 2; i <= sqrt(x + 0.5); i++) {
    if (x % i == 0) {
      flag = 0;
    }
  }
  return flag ;
}