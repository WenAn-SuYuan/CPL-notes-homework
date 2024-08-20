//
// Created by weslie on 2023/10/16.
//
#include<stdio.h>
int main(){
  int number = 0 ;
  scanf("%d", &number);

  //TODO; count number of digits
  int num_of_digits = 0 ;

 do {
   number /= 10 ;
   num_of_digits++ ;
 } while (number > 0) ;


 printf("%d",num_of_digits) ;
  return 0 ;
}