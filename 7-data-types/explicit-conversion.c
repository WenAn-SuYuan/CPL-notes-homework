//
// Created by weslie on 2023/11/20.
//
#include<stdio.h>
int main() {
  double pi = 3.14159;
  double fraction = pi - (int) pi;


  int num = 1000000000;
  long long int llink1 = num * num;
  long long int llink2 = (long long) num * num;
  printf("%lld\n", llink1);
  printf("%lld\n", llink2);

  return 0;
}