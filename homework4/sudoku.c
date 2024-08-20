//
// Created by weslie on 2023/10/23.
//
#include<stdio.h>
#define LEN 9
int main(){
  int numbers[LEN][LEN] = { 0 } ;
  for(int row = 0 ; row < LEN ; row++){
    for(int col = 0 ; col < LEN ; col++){
      scanf("%d" , &numbers[row][col]);
    }
  }


  int flag = 0 ;
  for(int row = 0 ; row < LEN ; row++){
    int array[LEN] = { 0 };
    for(int col = 0 ; col < LEN ; col ++){
      array[numbers[row][col] - 1] ++ ;
    }

    for(int i = 0 ; i < LEN ; i++){
      if (array[i] != 1){
        flag = 1 ;
        break ;
      }
    }
  }

  for(int col = 0 ; col < LEN ; ++col){
    int array[LEN] = { 0 };
    for(int row = 0 ; row < LEN ; ++row){
      array[numbers[row][col] - 1] ++ ;
    }

    for(int i = 0 ; i < LEN ; ++i){
      if(array[i] != 1){
        flag = 1 ;
        break ;
      }
    }
  }

  for(int row = 1 ; row < LEN ; row += 3) {

    for (int col = 1; col < LEN; col += 3) {
      int array[LEN] = { 0 };
      array[numbers[row - 1][col - 1] - 1]++;
      array[numbers[row - 1][col] - 1]++;
      array[numbers[row - 1][col + 1] - 1]++;
      array[numbers[row][col - 1] - 1]++;
      array[numbers[row][col] - 1]++;
      array[numbers[row][col + 1] - 1]++;
      array[numbers[row + 1][col - 1] - 1]++;
      array[numbers[row + 1][col] - 1]++;
      array[numbers[row + 1][col + 1] - 1]++;

      for (int i = 0; i < LEN; ++i) {
        if (array[i] != 1) {
          flag = 1;
          break;
        }
      }
    }
  }

  if(flag){
    printf("NO\n") ;
  } else {
    printf("YES\n") ;
  }



  return 0 ;
}