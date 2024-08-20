//
// Created by weslie on 2023/10/16.
//
#include<stdio.h>
#define LEN 20
int numbers[LEN] = { 0 };
int main(){
  int len = -1 ;
  while(scanf("%d",&numbers[++len]) != EOF);
//input failure ,(EOF , -1)
//number of matched items (match failure), scanf 返回之前成功匹配数

  //TODO: selection sort
  for(int i = 0 ; i < len; ++i) {
    //find the min in numbers[]
    int min = numbers[i] ;
    int min_index = i ;
    for(int j = i + 1 ; j < len ; ++j){
      if(numbers[j] < min){
        min = numbers[j] ;
        min_index = j ;
      }
    }
    //swap numbers[i] and numbers [min_index]
    int temp = numbers[i];
    numbers[i] = numbers[min_index];
    numbers[min_index] = temp ;
  }

  for(int i = 0 ; i < len ; ++i){
    printf("%d" , numbers[i]) ;
  }

  return  0 ;
}