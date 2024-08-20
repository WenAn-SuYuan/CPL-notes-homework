#include<stdio.h>
#include <stdlib.h>
#define BIG 100005

int main(){
  int n = 0 , m = 0 ;
  scanf("%d %d", &n ,&m) ;

  int *arr[BIG] ;
  for(int i = 1 ; i <= n ; ++i){
    arr[i] = malloc(sizeof(int)) ;
    *arr[i] = i ;
  }
  int *arr_move[BIG] ;
  for(int i = 0 ; i <= n  ; ++i){
    arr_move[i] = arr[i] ;
  }

  while(m--){
    int x = 0 , y = 0 ;
    scanf("%d %d", &x, &y) ;

    arr[y] = realloc(arr[y], (arr_move[y] - arr[y] + arr_move[x] - arr[x] + 2) * sizeof(int)) ;
    while(*arr[x] != 0){
      if(*arr[y] == 0){
        *arr[y] = *(arr_move[x]) ;
      } else{
        *(++arr_move[y]) = *(arr_move[x]) ;
      }

      if(arr_move[x] == arr[x]){
        *arr[x] = 0 ;
        arr[x] = realloc(arr[x], sizeof(int)) ;
        break ;
      }

      arr_move[x]-- ;
    }

  }

  for(int i = 1 ; i <= n ; ++i){
    for(; arr[i] <= arr_move[i] ; ++arr[i]){
      printf("%d ", *arr[i]) ;
    }

    printf("\n") ;
  }





  return 0 ;
}
