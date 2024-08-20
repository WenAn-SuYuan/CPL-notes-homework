//
// Created by weslie on 2023/11/20.
//
#include<stdio.h>
#define LEN 10005

int FindDearest(int value[] , int len) ;

int main(){
  int n = 0 , L = 0 ;
  scanf("%d %d" , &n , &L) ;

  int value[LEN] = { 0 };
  int max[LEN] = { 0 };

  for(int i = 0 ; i < n ; ++i){
    scanf("%d" , &value[i]) ;
  }
  for(int i = 0 ; i < n ; ++i){
    scanf("%d" , &max[i]) ;
  }

  int total = 0 ;
  int wines = 0 ;
  while(1==1){
    int max_index = FindDearest(value , n) ;
    //printf("%d\n" , max_index) ;


    if(L - wines > max[max_index]){
      wines += max[max_index] ;
      total += value[max_index] * max[max_index] ;
      value[max_index] = 0 ;
  } else {
      total += (L - wines) * value[max_index] ;
      break ;
    }

  }

  printf("%d\n" , total) ;



  return 0 ;
}
int FindDearest(int value[] , int len){
  int max = value[0] ;
  int max_index = 0 ;
  for(int i = 1 ; i < len ; ++i){
    if(value[i] >= max){
      max = value[i] ;
      max_index = i ;
    }
  }
  return max_index ;

}


