#include<stdio.h>
#define BIG 1000005
int main(){
  int n = 0 ;
  scanf("%d",&n);
  int people[BIG] = {0};
  for(int i = 0 ; i <= n; i++){
    scanf("%d",&people[i]);
  }

  int sum = 0 ;
  int helper = 0 ;
  for (int i = 0 ; i <= n ; i++){

    if(sum < i && people[i] != 0){
      helper = helper + i - sum ;
      sum = sum + i - sum + people[i] ;

    } else {
      sum = sum + people[i];
    }
  }

  printf("%d", helper);




  return 0 ;
}