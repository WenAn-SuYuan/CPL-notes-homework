//
// Created by weslie on 2023/10/16
//
#include<stdio.h>
#define LEN 10

int BinarySearch(int key , const int dict[], int len) ;
int main (){
  int key = 0 ;
  scanf("%d", &key) ;
  const int dict[LEN] = {1, 1, 2 , 3, 5 , 8 ,13,21 ,34,55};


  int index = BinarySearch(key, dict, LEN) ;

  //TODO: binary search for key in dict[]

  printf("%d",index) ;
  return 0 ;
}


int BinarySearch(int key , const int dict[] , int len){
  int low = 0 ;
  int high  = len - 1 ;

  while(low <= high) {
    int mid = (low + high) / 2 ;

    if (key > dict[mid]){
      low = mid + 1 ;
    } else if(key < dict[mid]){
      high = mid - 1 ;
    } else {
      return mid ;
    }
  }

  return -1 ;
}