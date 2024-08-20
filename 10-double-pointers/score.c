//
// Created by weslie on 2023/12/15.
//
#include<stdio.h>
#include <stdlib.h>

#define NUM_OF_MUSICIANS 4
#define NUM_OF_SCORES 3

void Print(const int table[][NUM_OF_SCORES], int num_of_musicians) ;

int main(){
  /*const int scores[NUM_OF_MUSICIANS][NUM_OF_SCORES] = {
      {0 , 10 ,20},
      {10 , 20,30},
      {20, 30, 40},
      {30, 40, 50}
  } ;*/

  int rows = 0 ;
  printf("Please input the  number of the students.\n") ;
  scanf("%d", &rows) ;

  int (*scores)[NUM_OF_SCORES] = malloc(rows * NUM_OF_SCORES * sizeof (**scores)) ;
  if(scores == NULL){
    return 0 ;
  }
  for(int i = 0 ; i < NUM_OF_MUSICIANS ; ++i){
    for(int j = 0 ; j < NUM_OF_SCORES ; ++j){
      scanf("%d", &scores[i][j]) ;
    }
  }

  Print(scores, NUM_OF_MUSICIANS) ;

  int (*ptr_scores)[NUM_OF_SCORES] = *scores ;
  printf("ptr_scores[3][2] = %d\n", (*(ptr_scores + 3)[2])) ;



  free(scores) ;

  return 0 ;
}
//table :int table[][COL]
//int table[]: int *table
//int table [][COL] : int (*table)[COL]  (不加括号会变成和char *【LEN】相同的内存分布
/**
 *int table[][COL] : int (*table)[COL] 是一个数组 数组中每一个元素都是一个大小为[COL]的数组
 * 数组名table指向第一个元素，即第一个数组的首地址
 *
 *
 */
void Print(const int table[][NUM_OF_SCORES], int num_of_musicians){
  for(int i = 0 ; i < num_of_musicians ; ++i){
    for(int j = 0 ; j < NUM_OF_SCORES ; ++j){
      //table[i][j] : *(*(table + i) + j)
      //table : int (*)[COL]
      //table + i : int (*)[COL] 指向了第i行，即指向了第三个数组
      //*（table + i) : int *  其指向与table + i 相同 但类型并不相同
      // *（table + i) + j : int *
      //* (*(table + i ) + j ) : int
      printf("table[%d][%d] = %d\n", i , j , table[i][j]) ;
    }
    printf("\n\n") ;
  }

}
