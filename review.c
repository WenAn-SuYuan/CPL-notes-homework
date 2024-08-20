//
// Created by weslie on 2024/1/2.
//
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//#include <stdlib.h>
void Swap(int *left, int *right) ;
int GetMinIndex(int begin , int end , int *arr) ;
void Selectionsort(int *arr, int len) ;
int main(){
  char str1[10] = "abc" ;
  char *str2 = "de" ;
  char str3[6] ;
  memset(str3, 0 , sizeof str3) ;
  strcpy(str3, str1) ;
  printf("%s\n", str3) ;
  strcat(str1,str2) ;
  printf("%s %s\n", str1 , str2) ;

  char *num = "123" ;
  printf("%d\n", atoi(num)) ;






  return 0 ;
}

void Swap(int *left, int *right){
  int temp = *left ;
  *left = *right ;
  *right = temp ;
}

int GetMinIndex(int begin , int end , int *arr){
  int min = arr[begin] ;
  int min_index = begin ;
  for(int i = begin ; i < end ; ++i){
    if(arr[i] < min){
      min = arr[i] ;
      min_index = i ;
    }
  }

  return min_index ;
}
void Selectionsort(int *arr, int len){
  for(int i = 0 ; i < len ; ++i){
    int min_index = GetMinIndex(i, len , arr) ;
    Swap(&arr[i], &arr[min_index]) ;
  }
}
int CompareInt(const void *left, const void *right){
  const int *left_int = (const int *)left ;
  const int *right_int = (const int *)right ;
  return (*left_int > *right_int) - (*left_int < *right_int) ;

}

int CompareStr(const void *left, const void *right){
  const char **left_str = (const char **)left ;
  const char **right_str = (const char **)right ;
  return strcmp(*left_str, *right_str) ;
}


