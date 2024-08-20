//
// Created by weslie on 2023/11/16.
//
#include<stdio.h>

int Bsearch(int key , const int dict[] , int low ,int high) ;
int main(){



  return 0 ;
}
int Bsearch(int key , const int dict[] , int low ,int high){
  if(low > high){
    return -1 ;
  }

  int mid = (low + high) / 2 ;
  if(dict[mid] == key){
    return mid ;
  }

  if(dict[mid] > key){
    return Bsearch(key , dict ,  low, mid - 1) ;
  }

  if(dict[mid] < key){
    return Bsearch(key , dict, mid + 1 , high) ;
  }
}
