//
// Created by weslie on 2023/10/24.
//
#include<stdio.h>
#include <stdbool.h>
#define BIG 100
int main(){
  int n = 0 , m = 0 , x = 0 , y = 0 ;

  scanf("%d %d %d %d" , &n, &m, &x , &y);
  char map[BIG][BIG] ;
  for(int i = 0 ; i < n ; ++i){
    scanf("%s", map[i]) ;
  }

  char new_map[BIG][BIG] ;
  for(int i = 1 ; i <= n ; ++i){
    for(int j = 1 ; j <= m ; ++j){
      new_map[i][j]= map[i - 1][j - 1] ;
    }
  }

  bool vis[BIG][BIG] ;
  for(int i = 0 ; i <= 56 ; ++i){
    for(int j = 0 ; j <= 56 ; ++j){
      vis[i][j] = true ;
    }
  }

  int vectors[4][2] = {{-1 , 0} , {1 , 0 }, {0 , -1} , {0 , 1}};
  int row = x , col = y ;
  int ans = 1 ;
   vis[row][col] = false ;
  int sign = 0 , flag = 1 ;
  int numbers[BIG][BIG] = { {row , col} };
  while(row <= n , col <= m){

    for(int k = 0 ; k < 4 ; ++k){
       flag = 1 ;
      int N_row = row + vectors[k][0] ;
      int N_col = col + vectors[k][1] ;
      if(new_map[N_row][N_col] == '#' && vis[N_row][N_col] == true){
        ++ans ;
        vis[N_row][N_col] = false ;
        row = N_row ;
        col = N_col ;
        flag = 0 ;
        ++sign ;
        break ;
      }
    }

    if(flag){
      break ;
    }

    numbers[sign][0] = row ;
    numbers[sign][1] = col ;

  }

  printf("%d\n" , ans) ;
  for(int i = 0 ; i <= sign ; ++i ){
    printf("%d %d" , numbers[i][0] , numbers[i][1]) ;
    printf("\n") ;
  }

  return 0 ;
}