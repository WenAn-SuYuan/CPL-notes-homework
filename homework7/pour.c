//
// Created by weslie on 2023/11/24.
//
#include<stdio.h>
#define min(x,y) ((x) < (y) ? (x) : (y))
int VA = 0 , VB = 0 , VC = 0 ;
int a_0 = 0 , b_0 = 0 , c_0 = 0 ;

int Judge(int k , int a ,int b , int c)  ;
int main(){
  int k = 0 ;
  scanf("%d" , &k) ;

  scanf("%d %d %d" , &VA , &VB , &VC) ;
  int a = 0 , b = 0 , c = 0 ;
  scanf("%d %d %d" , &a , &b , &c) ;

  scanf("%d %d %d" , &a_0 , &b_0 , &c_0) ;

  int judge = Judge(k, a , b , c);
  if(judge){
    printf("Yes") ;
  } else {
    printf("No") ;
  }


  return 0 ;
}
int Judge(int k , int a ,int b , int c){

  if(k < 0){
    return 0 ;
  }

  if(a == a_0 && b == b_0 && c == c_0){
    return 1 ;
  } else {
    int ans1 = Judge(k - 1 , 0 , min(a + b , VB), c) ;
    int ans2 = Judge(k - 1 ,min(a + b , VA) , 0 , c) ;
    int ans3 = Judge(k - 1 , 0 , b , min(a + c , VC)) ;
    int ans4 = Judge(k - 1 ,min(a + c , VA), b , 0 ) ;
    int ans5 = Judge(k - 1 ,a , min(b + c, VB), 0) ;
    int ans6 = Judge(k - 1 ,a , 0 , min(b + c , VC)) ;
    //printf("%d %d %d %d %d %d ", ans1 ,ans2 , ans3 , ans4 , ans5 , ans6) ;
    return ans1 + ans2 + ans3 + ans4 + ans5 + ans6 ;
  }





}
