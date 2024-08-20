//
// Created by weslie on 2023/11/16.
//
#include<stdio.h>

int GCD(int a , int b);
int main(){



  return 0 ;
}
/*int GCD(int a , int b){
  if(b == 0){
    return a ;
  }

  return GCD(b , a % b) ;

}*/

int GCD(int a , int b){
  while(b != 0){
  int tem = a ;
  a = b ;
  b = tem % b ;
  }

  return a ;
}//迭代版本

