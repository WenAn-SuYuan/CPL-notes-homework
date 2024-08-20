#include<stdio.h>
#define LEN 1000005
int main(){
  int n = 0 , k = 0 ;
  scanf("%d %d" , &n , &k) ;
  int numbers[LEN] = { 0 };
  for(int i = 0 ; i < n ; ++i){
    scanf("%d" , &numbers[i]) ;
  }
  int pivot = numbers[k - 1] ;

  int l = 0 , r = n - 1 ;
  while(1 == 1){
    int temp = 0 , temp1 = 0 ;

    for( ; l != r ; ++l){
      if(numbers[l] >= pivot ){
        break ;
      }
    }

    for( ; r != l ; --r){
      if(numbers[r] < pivot){
        break ;
      }
    }

    temp = numbers[l] ;
    numbers[l] = numbers[r] ;
    numbers[r] = temp ;

    if(r == l && r == k - 1){
      break ;
    } else if (r == l & r != k - 1){
      temp1 = numbers[k - 1] ;
      numbers[k - 1] = numbers[r] ;
      numbers[r] = temp1 ;
      break ;
    }
    if(numbers[k - 1] != pivot){
      for(int i = 0 ; i < n ; ++i) {
        if (numbers[i] == pivot) {
          k = i + 1 ;
        }
      }
    }

  }

  for(int i = 0 ; i < n ; ++i){
    printf("%d " , numbers[i]) ;
  }

  return 0 ;
}