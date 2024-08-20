//
// Created by weslie on 2023/11/2.
//
#include<stdio.h>
#define BIG 10005 // change it larger later

int BinarySearch(int tB , int a[] , int n) ;
int main(){
  int n = 0 , m = 0 , t = 0 ;
  scanf("%d %d %d" , &n , &m , &t) ;
  int a[BIG] = { 0 } ;
  int b[BIG] = { 0 };
  for(int i = 0 ; i < n ; ++i){
    scanf("%d" , &a[i]) ;
  }
  for(int i = 0 ; i < m ; ++i){
    scanf("%d" , &b[i]) ;
  }
// input

int flag = 1 ;
int min = BinarySearch(t - b[0] , a , n);
  for(int i = 1 ; i < m ; ++i){
    flag = 1 ;
    int ready = BinarySearch(t - b[i] , a , n ) ;
    //printf("%d " , ready) ;//debug
    if(ready == -1){
      flag = 0;
    }

    if(min == -1 && flag){
      min = ready ;
    } else if(flag && ready < min){
      min = ready ;
    }

}

  printf("%d" , min) ;

  return 0 ;
}

int BinarySearch(int tB , int a[] , int n){
  int low = 0 ;
  int high = n - 1 ;
  int min =  tB + 1 ;
  while(low <= high){
    int mid = (low + high) / 2 ;
    if(tB - a[mid] < 0){
      high = mid - 1 ;
    } else if(tB - a[mid] == 0){
      return 0 ;
    } else {
      min = tB - a[mid] ;
      low = mid + 1 ;
    }
  }

  if(min == tB + 1){
    return -1 ;
  } else {
    return min ;
  }

}