#include<stdio.h>
#include <string.h>
#define LEN 10

void SelectionSort(const char *arr[], int len) ;
void Swap(const char **left ,const char **right) ;
int GetMinIndex( const char *arr[] , int begin , int end) ;
void Print(const char *arr[] , int len) ;
int main(){
  //[]优先级高于*
 const char *musicians[LEN] = {
"Luo Dayou",
"Cui Jian",
"Dou Wei",
"Zhang Chu" ,
"Wan Qing",
"Li Zhi",
"Yao",
"ZuoXiao",
"Ershou Rose",
"Hu Mage"
  } ;

  Print(musicians, LEN) ;


  return 0 ;
}

/**
 * selectionsort 为何可以加上从const？数组不是变了吗？
 * 答：要明确const保护谁
 * 此处const保护的是char 即保护人名  并没有保护指针本身  我们做的事是对指针本身的修改
 * 若想保护指针本身 ：const char * const arr[] 前一个保护人名 后一个保护指针
 *
 *
 */
void SelectionSort(const char *arr[] , int len){
  for(int i = 0 ; i < len ; ++i){
    int min_index = GetMinIndex(arr, i,len) ;

   //前面加了const后，形参变为const char **
   //所以swap也要跟着加上const
    Swap(arr + i , arr + min_index) ;
   /**
    * Swap 中要求两个char **类型参数   但仍然此时仍然传入arr+i
    * 希望传入两个指针的地址
    * arr char *[]  也就是char **
    * 理解： arr是一个数组 数组中全是指针 arr是这个数组的首地址 即指针的指针
    */
  }
}



int GetMinIndex(const char *arr[] , int begin , int end){
  char *min = arr[begin] ;
  int min_index = begin ;
  for(int i = begin + 1 ; i < end ; ++i){

    if(strcmp(arr[i], min) < 0){
      min = arr[i] ;
      min_index = i ;
    }
  }

  return min_index ;
}

void Print(const char *arr[] , int len){
  printf("\n") ;
  for(int i = 0 ; i < len ; ++i){
    printf("%s\n " , arr[i]) ;
  }
  printf("\n") ;
}

void Swap(const char **left ,const char **right){
  char *temp = *left ;
  *left = *right ;
  *right = temp ;
}

/**
 * swap : 地址交换过程
 *
 *
 */
