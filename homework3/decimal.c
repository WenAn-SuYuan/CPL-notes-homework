//
// Created by weslie on 2023/10/19.
//
#include<stdio.h>
#include <math.h>
int main(){
  int len = 0 , N = 0 ;
  scanf("%d %d", &len , &N);
  getchar() ;

  char word[35] ;
  scanf("%s", word);

  int flag = 0 ,ten_num = 0 ;
  if(N <= 10){
    for(int i = len - 1 ; i >= 0 ; --i ){
      if(word[i] >= '0' && word[i] <= '0' + N - 1){
        ten_num += (word[i] - '0') * pow(N , len - 1 - i);
      } else {
        flag = 1 ;
        break ;
      }
    }
    }

  if(N > 10){
    for(int i = len - 1 ; i >= 0 ; --i ){
      if(word[i] >= '0' && word[i] <= '9'){
        ten_num += (word[i] - '0') * pow(N , len - i - 1) ;
      } else if(word[i] >= 'A' && word[i] <= 'A' + N - 11){
        ten_num += (word[i] - 'A' + 10) * pow(N , len - i - 1) ;
      } else {
        flag = 1 ;
        break ;
      }
    }
  }

  if(flag){
    printf("Error") ;
  } else {
    printf("%d", ten_num) ;
  }




  return 0 ;
}