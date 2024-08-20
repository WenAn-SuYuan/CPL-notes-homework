//
// Created by weslie on 2023/10/31.
//
#include<stdio.h>

int RadixTrans(int num , int radix);
int main(){
  int p = 0 , q = 0 , r = 0 ;
  scanf("%d %d %d" , &p , &q , &r);
  int multi = p * q ;

  int flag = 0 ;
  for(int radix = 2 ; radix <= 40 ; ++radix) {
    int ans = RadixTrans(multi , radix) ;
    if(ans == r){
      printf("%d" , radix) ;
      flag = 1 ;
      break ;
    }

  }

  if(!flag){
    printf("0") ;
  }

  return 0 ;
}

int RadixTrans(int num , int radix){
  int ans = 0 ;
  int ten = 1;
  int tem = 0 ;
  while(num > 0){
    tem = num % radix ;
    if(tem > 9){
      return -1 ;
    }
    ans = (tem) * ten + ans ;
    num /= radix ;
    ten *= 10 ;
  }

  //printf("%d %d\n", radix , ans) ;
  return ans ;

}