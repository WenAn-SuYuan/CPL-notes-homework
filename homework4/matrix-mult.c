//
// Created by weslie on 2023/10/23.
//
#include<stdio.h>
#define N 105
int main(){
  int m = 0 , n = 0 , p = 0 ;
  scanf("%d %d %d" , &m , &n , &p ) ;
  int numbers_m[N][N] = { 0 };
  int numbers_p[N][N] = { 0 };
  for(int row = 0 ; row < m ; row++) {
    for (int col = 0; col < n; col++) {
      scanf("%d", &numbers_m[row][col]);
    }
  }

  for(int row = 0 ; row < n ; row++) {
    for (int col = 0; col < p; col++) {
      scanf("%d", &numbers_p[row][col]);
    }
  }

  int result[N][N] = { 0 };
  for(int row = 0 ; row < m ; row++){
    for(int col = 0 ; col < p ; col++){
      for(int i = 0 ; i < n ; ++i){
        result[row][col] += numbers_m[row][i] * numbers_p[i][col] ;
      }

    }
  }

  for(int row = 0 ; row < m ; ++row){
    for(int col = 0 ; col < p ; ++col){
      printf("%d " , result[row][col]) ;
    }
    printf("\n") ;
  }

  return 0 ;
}