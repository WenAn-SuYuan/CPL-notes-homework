//
// Created by weslie on 2023/11/16.
//
#include<stdio.h>
#define BIG 10005 //change it later


int find(int x , int a[]) ;
int main(){
  int n = 0 ;
  scanf("%d" , &n) ;
  int a[BIG] = { 0 } ;
  for(int i = 1 ; i <= n ; ++i){
    scanf("%d" , &a[i]) ;
  }

  for(int i = 1 ; i <= n ; ++i){
    printf("%d " , find(i , a)) ;
  }



  return 0 ;
}
int find(int x , int a[]){
  if(x == a[x]){
    return x ;
  }

  return find(a[x] , a) ;

}