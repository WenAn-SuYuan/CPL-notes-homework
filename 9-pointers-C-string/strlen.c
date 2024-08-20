//
// Created by weslie on 2023/12/3.
//
#include<stdio.h>
int Strlen(const char *str) ;
int Strlen1(const char *str) ;
int Strlen2(const char *str) ;
size_t StrlenStd(const char *str) ;

int main(){
  char msg[] = "Hello World!" ;
  printf("Strlen(%s) = %d", msg ,Strlen1(msg)) ;



  return 0 ;
}
int Strlen(const char *str){ //const 保护指针的字符串 不保护指针 即指针可以被修改
  int len = 0 ;
  while(str[len] != '\0'){
    len++ ;
  }
  return len ;
}

int Strlen1(const char *str){ //const 保护指针的字符串 不保护指针 即指针可以被修改
  int len = 0 ;
  while(str[len++] != '\0') ;
  /**
   * 注意此处 len++ 是先访问str【len】再自增
   */

  return len - 1 ; //not good   because you will consider why it minus 1 ;
}

int Strlen2(const char *str){ //const 保护指针的字符串 不保护指针 即指针可以被修改
  int len = -1 ;
  while(str[++len] != '\0') ;

  return len ;
}

size_t StrlenStd(const char *str){ //const 保护指针的字符串 不保护指针 即指针可以被修改
  const char *sc ;
  for(sc = str ; *sc != '\0' ; ++sc) ;

  return sc - str ;
}




