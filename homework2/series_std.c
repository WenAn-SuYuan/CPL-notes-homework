//
// Created by weslie on 2023/10/26.
//
#include<stdio.h>
#include<math.h>
int main(){
  double x = 0.0 ;
  int n = 0 ;
  scanf("%lf %d" , &x, &n) ;
  double sum = 0 ;

  for(int i = 0 ; i <= n ; ++i){
    sum += 4 * (pow(-1 , i) * pow(x , 2 * i + 1) * 1.0/ (2 * i + 1)) ;
  }

  printf("%.10lf" , sum) ;

  return 0 ;
}