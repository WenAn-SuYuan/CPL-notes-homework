//
// Created by weslie on 2023/11/24.
//
#include<stdio.h>
#include<string.h>
#define LEN 1005


int main(){
  int a = 0 , b = 0 , c = 0 ;
  scanf("%d %d %d" , &a , &b , &c) ;

  char string[LEN] ;
  scanf("%s" , string) ;
  int length = strlen(string) ;
  int ans[4] = {0 , a , 0 , b};
  int temp = 0 ;

  for(int i = 0 ; i < length ; ++i){
    if(string[i] == 'W'){
      ans[1] = ans[0] ;
      ans[0] -= c ;
       temp = a ;
      a = c ;
      c = temp ;
    } else if(string[i] == 'S'){
      ans[0] = ans[1] ;
      ans[1] += c ;
      temp = a;
      a = c ;
      c = temp ;
    } else if(string[i] == 'A'){
      ans[3] = ans[2] ;
      ans[2] -= c ;
      temp = c ;
      c = b ;
      b = temp ;
    } else if(string[i] == 'D'){
      ans[2] = ans[3] ;
      ans[3] += c ;
      temp = c ;
      c = b ;
      b = temp ;
    }
  }

  for(int i = 0 ; i < 4 ; ++i){
    printf("%d " , ans[i]) ;
  }








  return 0 ;
}

