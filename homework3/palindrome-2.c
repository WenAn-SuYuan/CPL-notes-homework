//
// Created by weslie on 2023/10/20.
//
#include<stdio.h>
int main(){
  int n = 0 ;
  char str[10005] ;
  scanf("%d" , &n) ;
  getchar() ;
  scanf("%s" , str) ;

  for(int i = 0 ; i < n ; ++i){
    if(str[i] == '?'){
      str[i] = str[n - 1 - i];
    }
  }

  int numbers[99] = {0};
  for(int i = 0 ; i < 100 ; ++i){
    numbers[i] = i ;
  }
  int count = -1 ;
  for(int i = 0 , j = 0;  i <= ( n - 1 ) / 2  ; ++i) {
    if (!(str[i] == '?')) {
      printf("%c", str[i]);
    } else {
      while(j < 100){
        printf("%02d" , numbers[j]) ;
        count++;
        ++j ;
        break ;
      }
    }
  }

  for(int i = (n - 1) / 2 + 1 ; i < n ; ++i ){
    if(!(str[i] == '?')){
      printf("%c" , str[i]) ;
    } else {
      printf("%02d" , (count % 10) *10+ (count / 10)) ;
      --count ;
    }
  }

  return 0 ;
}