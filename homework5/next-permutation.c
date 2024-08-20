#include<stdio.h>
#define BIG 2008


int main(){
  int n = 0 ;
  int numbers[BIG] = { 0 };
  scanf("%d" , &n);
  for(int i = 1 ; i <= n ; ++i){
    scanf("%d" , &numbers[i]) ;
  }

  int m = 1 ;
  int long_index_before = n - 1 ;
  for(int i = n ; i >= 1 ; --i){
    if(numbers[i] < numbers[i - 1]){
      ++m ;
      --long_index_before ;
    } else {
      break ;
    }
  }

  //debug
//printf("%d %d" , m , long_index_before) ;
  //debug

  int min_max = numbers[long_index_before + 1] ;
  int min_max_index = long_index_before + 1 ;
  for(int i = long_index_before + 1 ; i <= n ; ++i ){
    if(numbers[i] > numbers[long_index_before]){
      min_max = numbers[i] ;
      min_max_index = i ;
    } else {
      break ;
    }
  }

  //debug
  //printf("%d %d " , min_max , min_max_index) ;
  //debug

  int tem = numbers[long_index_before] ;
  numbers[long_index_before] = numbers[min_max_index] ;
  numbers[min_max_index] = tem ;

  for(int i = 1 ; i <= n - m   ; ++i){
    printf("%d " , numbers[i]) ;
  }

  for(int i = n - m + 1 ; i <= n ; ++i){
    printf("%d " , numbers[2 * n - m + 1 - i]) ;
  }


  return 0 ;
}