//
// Created by weslie on 2023/10/18.
//
#include<stdio.h>
#define LEN 1000000
int main(){
  int T = 0 ;
  scanf("%d", &T);    //T为行数

  for(int m = 0 ; m < T ; m++){
    int n = 0 ;
    scanf("%d" , &n ) ;  //n为整数个数

    int arr[LEN] = { 0 } ;
    for(int j = 0 ; j < LEN && j < n ; j++) {
      scanf("%d", &arr[j]);
    }   //输入数组

    int max = arr[0] ;
    for(int i = 1 ; i < n  ; ++i){
      if(max <= arr[i]){
        max = arr[i] ;
      }
    }

    if(max == arr[n - 1]){
      printf("Yes\n") ;
    } else {
      printf("No\n") ;
    }
  }

  return 0 ;
}