#include<stdio.h>
#include <math.h>
#define BIG 28
#define EP 1e-4

double f(int array[] , int n , int p , double x) ;
double Sim(int array[] , int n , int p , double a , double b) ;
double GetAnswer(int array[] , int n , int p ,  double l , double r , double ep) ;


int main(){
  int n = 0 , p = 0 ;
  scanf("%d %d" , &n , &p) ;
  int array[BIG] = { 0 };
  for(int i = 0 ; i <= n ; ++i){
    scanf("%d" , &array[i]) ;
  }
  double a = 0.0 , b = 0.0 ;
  scanf("%lf %lf" , &a , &b) ;

  double result = GetAnswer(array , n , p , a , b ,EP ) ;
  printf("%lf" , result) ;

  return 0 ;
}
double f(int array[] , int n , int p , double x){
  double sum = 0.0 ;

  for(int i = 0 ; i <= n ; ++i){
    sum += array[i] * pow(x , i) ;
  }
  return pow(sum , p) ;
}

double Sim(int array[] , int n , int p , double a , double b){
  double result = (4 * f(array, n, p, (a + b) / 2) + f(array, n, p, a) +  f(array, n, p, b)) * (b - a) / 6 ;

  //printf("%lf\n" , result) ;

  return result ;
}

double GetAnswer(int array[] , int n , int p ,  double l , double r , double ep){
  double mid = (l + r) / 2.0 ;
  double S = Sim(array , n , p ,  l , r) ;
  double SL = Sim(array , n , p,  l , mid ) ;
  double SR = Sim(array , n , p,  mid , r ) ;

  if(fabs(SL + SR - S) <= ep * 15){
    return SL + SR + (SL + SR - S) / 15.0 ;
  } else {
    return GetAnswer(array , n , p ,  l , mid , ep / 2.0) + GetAnswer(array , n , p , mid , r , ep / 2.0) ;
  }
}
