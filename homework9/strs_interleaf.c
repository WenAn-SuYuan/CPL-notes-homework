#include<stdio.h>
#define LEN 1005
#define BIG 5005
#include<stdlib.h>
#include<string.h>

char *InterLeaveString(char *s1 , char *s2, int d1, int d2, int size) ;
int main(){
  int T = 0 ;
  scanf("%d" , &T) ;
  while(T--){
    char *str = malloc(BIG * sizeof(char)) ;
    scanf("%s" , str) ;
    char *s1 = strtok(str, ";") ;
    char *s2 = strtok(NULL , ";") ;
    char *num1 = strtok(NULL, ";") ;
    char *num2 = strtok(NULL, ";") ;
    char *num3 = strtok(NULL, ";") ;
    int d1 = atoi(num1) , d2 = atoi(num2) , size = atoi(num3) ;

    char *s3 = InterLeaveString(s1, s2, d1, d2, size) ;
    printf("%s\n" ,s3) ;

  }

   


  return 0 ;
}
char *InterLeaveString(char *s1 , char *s2, int d1, int d2, int size){
  char *s3 = malloc(2 * LEN * sizeof(char)) ;
  char *temp = s3 ;


  char *end1 = s1 + strlen(s1) - 1 ;
  char *end2 = s2 + strlen(s2) - 1 ;
  char *end3 = s3 + size - 2 ;
  while(1==1){
    char *cease1 = s1 + d1 - 1 ;
    char *cease2 = s2 + d2 - 1 ;
    for(; s1 <= (cease1 <= end1 ? cease1 : end1) && temp <= end3 ; ++s1 , ++temp){
      *temp = *s1 ;
    }

    if(temp == end3 + 1 || (s1 == end1 + 1 && s2 == end2 + 1)){
      *temp = '\0' ;
      break ;
    }

    for(; s2 <= (cease2 <= end2 ? cease2 : end2) && temp <= end3 ; ++s2 , ++temp){
      *temp = *s2 ;
    }

    if(temp == end3 + 1 || (s1 == end1 + 1 && s2 == end2 + 1)){
      *temp = '\0' ;
      break ;
    }

  }

  return s3 ;


}

