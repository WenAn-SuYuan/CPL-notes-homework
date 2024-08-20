//
// Created by weslie on 2023/10/23.
//
#include<stdio.h>
#define BIG 105
int main(){
  int m = 0 , n = 0 ;
  scanf("%d %d" , &m , &n );
  char first_line[BIG] ;
  scanf("%s" , first_line) ;

  int numbers[BIG][BIG + 2] = { 0 };
  for(int col = 1 ; col <= n ; col++){
    numbers[0][col] = first_line[col - 1] - '0' ;
  }

  int neighbors = 0 ;
  for(int row = 1 ; row < m ; ++row){
    for(int col = 1 ; col <= n ; col++ ){
      neighbors =
          numbers[row - 1][col - 1] +
          numbers[row - 1][col] +
          numbers[row - 1][col + 1] ;

      if(neighbors == 3 || neighbors == 0){
        numbers[row][col] = 0 ;
      } else if(neighbors == 2){
        numbers[row][col] = 1 ;
      } else {
        if(numbers[row - 1][col - 1] == 1){
          numbers[row][col] = 0 ;
        } else {
          numbers[row][col] = 1 ;
        }
      }

    }
  }

  for(int row = 1 ; row < m ; ++row){
    for(int col = 1 ; col <= n ; ++col){
      printf("%d", numbers[row][col]) ;
    }
    printf("\n") ;
  }




  return 0 ;
}