//
// Created by weslie on 2023/12/3.
//
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void Strcpy(char *dest, const char *src) ;
void Strcpy1(char *dest, const char *src) ;
void Strcpy2(char *dest, const char *src) ;
void Strcpy3(char *dest, const char *src) ;
void Strcpy4(char *dest, const char *src) ;
void Strcpy5(char *dest, const char *src) ;
char *StrcpyStd(char *dest, const char *src) ;

int main(){
  const char *src = "Hello World!" ;
  char *dest = malloc(strlen(src) + 1) ;
  Strcpy1(dest , src) ;

  printf("dest = %s\n" , dest) ;


  return 0 ;
}
void Strcpy(char *dest, const char *src){
  int i = 0 ;
  while(src[i] != '\0'){
    dest[i] = src[i] ;
    i++ ;
  }
  dest[i] = '\0' ;
}

void Strcpy1(char *dest, const char *src){
  int i = 0 ;
  while((dest[i] = src[i]) != '\0'){ //此处比较src【i】是否为\0
    i++ ;
  }
}

void Strcpy2(char *dest, const char *src){
  int i = 0 ;
  while((*(dest + i) = *(src + i)) != '\0'){
    i++ ;
  }
}

void Strcpy3(char *dest, const char *src){
  while((*dest = *src) != '\0'){
    src++ ;
    dest++ ;
  }
}

void Strcpy4(char *dest, const char *src){
  while((*dest++ = *src++) != '\0') ;
  /**
   * ++优先级高于* 有问题？
   * 实际没有，++运算符两个作用，一个是+1，而他的值仍是原来的
   *最后仍然是先解引用再加
   *                       难点
   *
   */
}

void Strcpy5(char *dest, const char *src){
  while((*dest++ = *src++)) ;
  /**
   * 涉及对\0理解
   * \0 在计算机中表示就是0
   * 所以变成问*dest++是否为真
   *
   *与NULL区别：NULL是0被强制转换成空指针，而\0本身就是0
   */
   // 该代码不推荐！！！！！
   //由于意图很模糊
}

char *StrcpyStd(char *dest, const char *src){
  for(char *s = dest ;(*s++ = *src) != '\0' ; ) ;
  return dest ;
}


