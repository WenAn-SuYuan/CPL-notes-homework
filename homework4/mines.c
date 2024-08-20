//
// Created by weslie on 2023/10/23.
//
#include<stdio.h>
#define BIG 105
int main(){
  int n = 0 ;
  scanf("%d" ,&n) ;
  char map_str[BIG][BIG] ;
  for(int i = 0 ; i < n ; ++i){
    scanf("%s" , map_str[i]) ;
    getchar();
  }

  char old_map[BIG][BIG] ;
  for(int row = 0 ; row < n ; ++row){
    for(int col = 0 ; col < n ; col++){
      old_map[row][col] = map_str[row][col] ;
    }
  }

  char new_map[BIG + 2][BIG + 2] ;
  for(int row = 1 ; row <= n ; ++row){
    for(int col = 1 ; col <= n ; ++col){
      new_map[row][col] = old_map[row - 1][col - 1] ;
    }
  }

  char result[BIG][BIG] ;

  int vectors[8][2]  = {{-1 , -1} , {-1 , 0} , {-1 , 1} , {0 , -1} ,  {0 , 1} , {1 , -1} , {1 , 0} , {1 , 1}};
  for(int row = 1 ; row <= n ; ++row){
    for(int col = 1 ; col <= n ; ++col){
      if(new_map[row][col] == '*'){
        result[row - 1][col - 1] = '*' ;
      } else {
        int count = 0 ;
        for(int k = 0 ; k < 8 ; ++k){
          int new_row = row + vectors[k][0] ;
          int new_col = col + vectors[k][1] ;
          if(new_map[new_row][new_col] == '*'){
            count++ ;
          }
        }

        result[row - 1][col - 1] = count + '0' ;

      }
    }
  }

  for(int row = 0 ; row < n ; ++row){
    for(int col = 0 ; col < n ; ++col){
      printf("%c" , result[row][col]);
    }
    printf("\n") ;
  }


  return 0 ;
}
