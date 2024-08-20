//
// Created by weslie on 2023/10/28.
//
#include<stdio.h>
#define SIZE 1005
int main(){
  int n = 0 ;
  scanf("%d" , &n);
  int map[SIZE][SIZE] = { 0 };
  map[0][n / 2] = 1 ;
  for(int i = 2 , x = 0 , y = n / 2 ; i <= 9 ; ++i){
    int new_x = (x == 0) ? 2 : (x - 1) ;
    int new_y = (y + 1) % 3 ;
    if(map[new_x][new_y] == 0 ){
      map[new_x][new_y] = i ;
      x = new_x ;
      y = new_y ;
    } else {
      map[x + 1][y] = i ;
      x = x + 1 ;
    }

  }

  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < n ; ++j){
      printf("%d " , map[i][j]) ;
    }
    printf("\n") ;
  }



  return 0 ;
}