//
// Created by weslie on 2023/10/16.
//
#include<stdio.h>
#include<stdbool.h>

bool IsPrime(int number) ;

int main(){
  int max = 0 ;
  scanf("%d", &max) ;

  int count = 0 ;
  //TODO: print primes between 1 and max
  for (int number = 2 ; number <= max ; ++number){
    if(IsPrime(number)){
      printf("%d ",number);
      count++ ;
    }
  }

  printf("\n count is %d",count) ;

  return 0 ;
}

bool IsPrime(int number){

  for(int factor = 2 ; factor * factor <= number ; ++factor){
    if (number % factor == 0 ){
      return false ;
    }
  }

  return true ;
}
