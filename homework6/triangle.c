//
// Created by weslie on 2023/11/17.
//
#include<stdio.h>
#include <math.h>
#define BIG 2048
#define NUM 1024

void paint(int n , int row , int col , char map[][BIG]) ;
int main(){
  int n = 0 ;
  scanf("%d" , &n) ;


  char map[NUM][BIG] ;
  for(int row = 0 ; row < NUM ; ++row){
    for(int col = 0 ; col < BIG ; ++col){
      map[row][col] = ' ' ;
    }
  }

  paint(n , 0 , 0 , map) ;
  for(int row = pow(2 , n) - 1 ; row >= 0 ; --row){
    for(int col = 0 ; col < pow(2 , n + 1) ; ++col){
      printf("%c" , map[row][col]) ;
    }
    printf("\n") ;
  }




  return 0 ;
}
void paint(int n , int row , int col , char map[][BIG]){
  if(n == 1){
    map[row][col] = '/' ;
    map[row][col + 1] = '_' ;
    map[row][col + 2] = '_' ;
    map[row][col + 3] = '\\' ;
    map[row + 1][col + 1] = '/' ;
    map[row + 1][col + 2] = '\\' ;
    return ;
  }
  paint(n - 1 , row , col , map) ;
  paint(n - 1 , row + pow(2 , n - 1) , col + pow(2 , n - 1) , map) ;
  paint(n - 1 , row , col + pow(2 , n) , map) ;
  return ;
}
