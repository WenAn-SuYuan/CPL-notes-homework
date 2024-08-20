//
// Created by weslie on 2023/10/26.
//
#include<stdio.h>
#include<math.h>
int main(){
  double x = 0.0 ;
  int n = 0 ;
  scanf("%lf %d",&x ,&n);
//input x n

  double y = 0.0;
  double series = 0.0 ;
  for(int i = 0 ; i <= n ; i++){
    series = series + (pow(-1,i) * pow(x , 2 * i + 1)) / (2.0 * i + 1.0);
  }
  y = 4 * series ;
//calculate the result

  printf("%.10f\n",y);

  return 0 ;
}