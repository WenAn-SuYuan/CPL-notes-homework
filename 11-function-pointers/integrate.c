//
// Created by weslie on 2023/12/19.
//
#include<stdio.h>
#include <math.h>

#define NUM_OF_PARTITIONS 100000

double Integrate(double low, double high,
                 double (*func)(double)) ;
//(*func)要加括号 增加优先级  ？？？？？？？？？？？？？？？没理解
int main(){
  double low = 0.0;
  double high = 1.0 ;
  double integration = 0.0 ;

  integration = Integrate(low,high, sin) ;
  //此处sin无需加上&，因此时sin会自动转为&sin，即函数指针类型
  printf("%lf", integration) ;

  /**
   * 把函数(指针）放进数组：
   */
 double (*funcs[])(double) = {sin , cos, sqrt};
 for(int i = 0 ; i < 3 ; ++i){
   printf("%lf\n", Integrate(low, high, funcs[i])) ;
 }





  return 0 ;
}

double Integrate(double low, double high,
                 double (*func)(double)){
  double interval = (high - low) / NUM_OF_PARTITIONS ;

  double sum = 0.0 ;
  for(int i = 0 ; i < NUM_OF_PARTITIONS ; ++i){
    double xi = low + interval * i ;
    double yi = func(xi) ;//同样，此处可以写成(*func)(xi) 这里会被一直隐式转为函数指针
    sum += yi * interval ;
  }

  return sum ;
}


