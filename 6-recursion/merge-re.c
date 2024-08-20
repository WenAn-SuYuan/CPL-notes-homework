//
// Created by weslie on 2023/11/20.
//
#include<stdio.h>

#define LEN 7
/**
 * @brief ort nums [left...right] using mergesort
 * @param nums
 * @param left
 * @param right
 */
void Mergesort(int nums[] , int left , int right) ;

/**
 * @brief merge nums[left...mid] and nums[mid + 1 ... right]
 * @param nums
 * @param left
 * @param mid
 * @param right
 */

void Merge(int nums[] , int left , int mid , int right) ;
int main(){
  int numbers[LEN] = {38, 27 ,43, 3 ,9 , 82 , 10} ;

  for(int i = 0 ; i < LEN ; ++i){
    printf("%d" , numbers[i]) ;
  }



  return 0 ;
}
void Mergesort(int nums[] , int left , int right){
  if(left == right){
    return ;
  }

  int mid = (left + right) / 2 ;
  Mergesort(nums, left, mid) ;//ask the mirror
  Mergesort(nums, mid + 1, right) ;//ask the mirror

  Merge(nums , left , mid , right) ;
}
void Merge(int nums[] , int left , int mid , int right){
  static int copy[LEN] = { 0 } ;//static 存储在非栈空间 只会初始化一次 即不会随函数结束而消失
}
