//
// Created by weslie on 2023/11/22.
//
#include<stdio.h>
#include <unistd.h>
#define LEN 805
#define TRAN 100
#define LIT 605
int ChangeToRight(int row , int col , int d , int value[][LEN]) ;
int ChangeToLeft(int row , int col , int d , int value[][LEN]) ;
int ChangeToDown(int row , int col , int d , int value[][LEN]) ;

int main(){
  int n = 0 , m = 0 , d = 0 ;
  scanf("%d %d %d" , &n , &m , &d) ;
  int map[LEN][LEN] = { 0 };
  for(int row = 1 ; row <= n ; ++row){
    for(int col = 1 ; col <= m ; ++col){
      scanf("%d" , &map[row][col]) ;
    }
  }

  int value[LEN][LEN] = { 0 };
  for(int row = 1 ; row <= n ; ++row){
    for(int col = 0 ; col <= m ; ++col){
      value[row + TRAN][col + TRAN] = map[row][col] ;
    }
  }

  int odds_or_not = 1 ;
  if(n % 2 == 0){
    odds_or_not = 0 ;
  }

  int end = 1 ;
  int row = 1 , col = 1 ;
  int ansN = 0 ;
  int right = 1 ;
  int max_index[LIT][2] = { 0 };
  int max_value = 0 ;
  int now_value = 0 ;
  int flag = 1 ;
  while(end){
    if(row == 1 && col == 1){   // 起始情况
      ansN = 1 ;
      max_index[0][0] = row;
      max_index[0][1] = col ;

      for(int i = 0 ; i <= d ; ++i){
        for(int j = 0 ; j <= d - i ; ++j){
          max_value += value[row + TRAN + i][col + TRAN + j] ;
        }
      }
       now_value = max_value ;
      ++col ;
    } else if(flag){                    // 普通情况
      if(right){
        now_value += ChangeToRight(row , col , d , value) ;
      } else {
        now_value += ChangeToLeft(row , col , d , value) ;
      }
      //judge
      if(now_value > max_value){
        max_value = now_value ;
        for(int i = 0 ; i < ansN ; ++i){
          max_index[i][0] = 0 ;
          max_index[i][1] = 0 ;
        }
        ansN = 1 ;
        max_index[0][0] = row ;
        max_index[0][1] = col ;

      } else if(now_value == max_value){
        ++ansN ;
        max_index[ansN - 1][0] = row ;
        max_index[ansN - 1][1] = col ;
      }
      //judge end

      if(!odds_or_not){
        if(row == n && col == 1){
          end = 0 ;

        }
      } else {
        if(row == n && col == m){
          end = 0 ;
        }
      }


      if((col == 1 || col == m) && (flag)){
        flag = 0 ;
      }

      if(!flag){
        ++row ;
      }

      if(right && flag){
        ++col;
      } else if(flag && !right){
        --col ;
      }

    }else if(!flag){                                                  //向下走情况
      now_value += ChangeToDown(row , col , d , value) ;

      if(now_value > max_value){
        max_value = now_value ;
        for(int i = 0 ; i < ansN ; ++i){
          max_index[i][0] = 0 ;
          max_index[i][1] = 0 ;
        }
        ansN = 1 ;
        max_index[0][0] = row ;
        max_index[0][1] = col ;

      } else if(now_value == max_value){
        ++ansN ;
        max_index[ansN - 1][0] = row ;
        max_index[ansN - 1][1] = col ;
      }
      //judge end
      if(right){
        right = 0;
        --col ;
      } else {
        right = 1 ;
        ++col ;
      }


      flag = 1 ;
    } /*else if(row == n && col == m){ // 终止情况 ， bug
      end = 0 ;
      if(right){
        now_value += ChangeToRight(row , col , d , value) ;
      } else {
        now_value += ChangeToLeft(row , col , d , value) ;
      }

      //judge
      if(now_value > max_value){
        max_value = now_value ;
        for(int i = 0 ; i < ansN ; ++i){
          max_index[i][0] = 0 ;
          max_index[i][1] = 0 ;
        }
        ansN = 1 ;
        max_index[0][0] = row ;
        max_index[0][1] = col ;

      } else if(now_value == max_value){
        ++ansN ;
        max_index[ansN - 1][0] = row ;
        max_index[ansN - 1][1] = col ;
      }
      //judge end

    }*/
   /* //debug
    printf("%d " , max_value) ;
    printf("%d\n" , ansN) ;

    for(int i = 0 ; i < ansN ; ++i){
      printf("%d " , max_index[i][0]) ;
      printf("%d\n" , max_index[i][1]) ;

      sleep(1) ;
    }

    printf("--------\n") ;
    //debug end*/
  }

  printf("%d " , max_value) ;
  printf("%d\n" , ansN) ;
  for(int i = 0 ; i < ansN ; ++i){
    printf("%d " , max_index[i][0]) ;
    printf("%d\n" , max_index[i][1]) ;
  }

  return 0 ;
}
int ChangeToRight(int row , int col , int d , int value[][LEN]){
  int sum = 0 ;
  for(int i = 0 ;i <= d ; ++i){
    sum += - value[row + TRAN - i][col - d - 1 + i + TRAN] + value[row - i + TRAN][col + d - i + TRAN] ;
  }

  for(int i = 1 ; i <= d ; ++i){
    sum += - value[row + i + TRAN][col - d - 1 + i + TRAN] + value[row + i + TRAN][col + d - i + TRAN] ;
  }
  return sum ;
}

int ChangeToLeft(int row , int col , int d , int value[][LEN]){
  int sum = 0 ;
  for(int i = 0 ; i <= d ; ++i){
    sum += value[row - i + TRAN][col + i - d + TRAN] - value[row - i + TRAN][col + d + 1 - i + TRAN] ;
  }

  for(int i = 1 ; i <= d ; ++i){
    sum += value[row + i + TRAN][col + i - d + TRAN] - value[row + i + TRAN][col + d + 1 - i + TRAN] ;
  }

  return sum ;
}

int ChangeToDown(int row , int col , int d , int value[][LEN]) {
  int sum = 0;
  for (int i = 0; i <= d; ++i) {
    sum += -value[row - d - 1 + i + TRAN][col - i + TRAN] + value[row + d - i +TRAN][col - i +TRAN];
  }

  for (int i = 1; i <= d; ++i) {
    sum += -value[row - d - 1 + i +TRAN][col + i +TRAN] + value[row + d - i +TRAN][col + i +TRAN];
  }
  return sum ;
}