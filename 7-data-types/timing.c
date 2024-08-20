//
// Created by weslie on 2023/11/16.
//
#include<stdio.h>
long long int Fib(int n) ;
int main() {
  int n = 0;
  scanf("%d", &n);

  long long int ans = Fib(n) ;

  /**
   *  time_t start = time(NULL) ;  ????????????????? why error
   */

  printf("%lld" , ans) ;
  return 0;
}
long long int Fib(int n) {
  if (n <= 1) {
    return n ;
  }

  return Fib(n - 1) + Fib(n - 2) ;
}