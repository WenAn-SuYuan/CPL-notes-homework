//
// Created by weslie on 2023/12/3.
//
#include<stdio.h>

int Strcmp(const char *s1, const char *s2) ; // 输出s1 - s2 最后值
int main(){
  const char *str1 = "hi, c" ;
  const char *str2 = "hi, C" ;




  return 0 ;
}
int Strcmp(const char *s1, const char *s2) {
  while(*s1 == *s2 && *s1 != '\0'){
    s1++ ;
    s2++ ;
  }
  //return *s1 - *s2 ; 错误,C语言标准未规定char是否有符号，一旦无符号则回绕，出现问题
  if(*s1 == '\0' && *s2 == '\0'){
    return 0 ;
  }

  return (*(const unsigned char *)s1)
             < (*(const unsigned char *)s2) ? -1 : 1 ;
  //此时问题：未考虑相等情况 加强while
}

int StrcmpStd(const char *s1, const char *s2){
  for(; *s1 == *s2 ; s1++ , s2++){
    if(*s1 == '\0'){
      return 0 ;
    }
  }
  return (*(const unsigned char *)s1)
             < (*(const unsigned char *)s2) ? -1 : 1 ;
}

