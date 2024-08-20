//
// Created by weslie on 2023/11/27.
//
#include<stdio.h>
#include<stdlib.h>
#define LEN 5
void SelectionSort(int arr[], int len) ;
void WrongSwap(int left , int right) ;
void Swap(int *left , int *right) ;
int GetMinIndex(const int arr[] , int begin , int end) ;
void Print(const int arr[] , int len) ;
int main(){
  int len = 0 ;
  scanf("%d" ,&len) ;
  int *numbers = malloc(len * sizeof(*numbers)) ; //return void *  返回首地址 void表示不确定 可以转成任何数据类型
//调用malloc后 要判定内存分配是否成功
  if(numbers == NULL){ //NULL : null pointer 空指针 不能解引用
    return 0 ;
  }

  for(int i = 0 ; i < len ; ++i){
    scanf("%d" , &numbers[i]) ;
  }

 // int numbers[LEN] = {15 , 78 , 23, 0,50} ;
  Print(numbers,len) ;
  SelectionSort(&numbers[0],len) ;
  Print(numbers,len) ;

  free(numbers) ; //将堆上的numbers空间还给系统 （malloc 分配的空间在堆上）
  /**
   *不能多次free（未定义行为）
   *free后空间无法访问（未定义）
   *
   * int var =100 ; free(var) 错误 非malloc申请的空间 在栈上 不用free
   *
   *
   */

  return 0 ;

}
/**arr: 在表达式中是数组首地址，但数组名本身不是变量
/int arr[] <=> int *arr
 */
void SelectionSort(int *arr , int len){
  for(int i = 0 ; i < len ; ++i){
    int min_index = GetMinIndex(arr, i,len) ;

    //&arr[i] <=> & *(arr + i) <=> arr + i
   Swap(&arr[i] , &arr[min_index]) ;
   // 即 arr + i           arr + min_index
  }
}

/**
 * const : 函数中不会改变数组的值
 *
 *
 *
 */

int GetMinIndex(const int *arr , int begin , int end){
  int min = arr[begin] ;
  int min_index = begin ;
  for(int i = begin + 1 ; i < end ; ++i){
    //arr[i] <=> *(arr + i) 指针并引用 <=> *(i + arr) <=> i[arr] 最后一种行归行但别这样
    // arr + i, arr - i, p - q(指针减法）
    /**
     * if p = 0x100, p + 3 != 0x103
     * p + 3只在数组中 是加上了3 * 每个元素字节数 即指向后面【3】元素
     * q - p 数组中下标的差除以每个元素字节
     * 保证指针计算时要使结果属于你
     */
    if(arr[i] < min){
      min = arr[i] ;
      min_index = i ;
    }
  }

  return min_index ;
}

void Print(const int arr[] , int len){
  printf("\n") ;
  for(int i = 0 ; i < len ; ++i){
    printf("%d" , arr[i]) ;
  }
  printf("\n") ;
}

void Swap(int *left , int *right){
  int temp = *left ;
  *left = *right ;
  *right = temp ;
}

