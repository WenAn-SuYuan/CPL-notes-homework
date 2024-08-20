//
// Created by weslie on 2023/12/21.
//
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 15000
#define NUM 105

int CompareStr(const void *left, const void *right) ;

int main(){
  char *string = malloc(LEN * sizeof (char)) ;
  scanf("%s", string) ;
  char *str[NUM] ;
  char delim[2] ;
  scanf("%s", delim) ;
  str[0] = strtok(string, delim);
  int sum = 1 ;
  while((str[sum] = strtok(NULL, delim)) != NULL) ++sum ;

  qsort(str,sum,sizeof str[0], CompareStr) ;

  for(int i = 0 ; i < sum ; ++i){
    printf("%s\n", *(str + i)) ;
  }

  free(string) ;
  return 0 ;
}
int CompareStr(const void *left, const void *right){
  const char **str_left = (const char **)left ;
  const char **str_right = (const char **)right ;
  return strcmp(*str_left, *str_right) ;
}
