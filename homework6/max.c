#include<stdio.h>
#define BIG 10005

int main(){
  int n = 0 ;
  scanf("%d" , &n) ;
  int array[BIG] = { 0 };
  for(int i = 1 ; i <= n ; ++i){
    scanf("%d" , &array[i]) ;
  }

  int ans[BIG][2] = { 0 };

  for(int i = 1 ; i <= n ; ++i){
    int min_index = i , max_index = i ;

    for(int j = i - 1 ; j >= 1 ; --j){
      if(array[j] <= array[i]){
        min_index = j ;
      } else {
        break ;
      }
    }

    for(int j = i ; j <= n ; ++j){
      if(array[j] <= array[i]){
        max_index = j ;
      } else {
        break ;
      }
    }

    ans[i][0] = min_index ;
    ans[i][1] = max_index ;
  }

  for(int i = 1 ; i <= n ; ++i){
    printf("%d " , ans[i][0]) ;
    printf("%d\n" , ans[i][1]) ;
  }



  return 0 ;
}