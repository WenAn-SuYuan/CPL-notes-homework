//
// Created by weslie on 2023/12/3.
//
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 2005

int HeadTailBingo(char *s1, char *s2, int len1 , int len2) ;
void mystrcat(char *s1 , char *s2, int len1, int len2) ;

int main(){
  int T = 0 ;
  scanf("%d" , &T) ;
  while(T--){
    char s1[LEN] ;
    memset(s1 , 0 , sizeof s1);
    char s2[LEN] ;
    memset(s2, 0 , sizeof s2) ;


    scanf("%s %s" , s1 , s2);

    int len1 = strlen(s1) ;
    int len2 = strlen(s2) ;

    int bingo = HeadTailBingo(s1, s2, len1, len2) ;
    //debug
    //printf("%d\n" , bingo) ;
    //debug end
    char cut_s2[LEN] ;
    memset(cut_s2, 0 , sizeof cut_s2) ;
    for(int i = 0 ; i <= len2 - 1 - bingo ; ++i){
      *(cut_s2 + i) = *(s2 + bingo + i) ;
    }

    mystrcat(s1, cut_s2,strlen(s1) ,strlen(cut_s2)) ;

    printf("%s\n" , s1) ;

  }


  return 0 ;
}

int HeadTailBingo(char *s1, char *s2, int len1, int len2){
  int len = len1 >= len2 ? len2 : len1 ;
  char *end1 = len1 + s1 - 1 ;
  while(len > 0) {

    char temp1[LEN] ;
    char temp2[LEN] ;
    memset(temp1, 0 , sizeof temp1) ;
    memset(temp2 , 0 , sizeof temp2) ;
    for(int i = 0 ; i < len ; ++i){
      *(temp1 + i) = *(end1 + 1 - len + i) ;
    }

    for(int i = 0 ; i < len ; ++i){
      *(temp2 + i) = *(s2 + i) ;
    }
    if(strcmp(temp1, temp2) == 0){
      return len ;
    }
    --len ;

  }

  return 0 ;
}

void mystrcat(char *s1 , char *s2, int len1, int len2){
  char *begin = s1 + len1 ;
  for(;  ; ++begin, ++s2){
    *begin = *s2 ;
    if(*s2 == '\0'){
      return ;
    }
  }
}


