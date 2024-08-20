#include<stdio.h>
#include <string.h>

#define STACK_SIZE 10005
int main() {
  int n = 0;
  scanf("%d", &n);
  char contents[STACK_SIZE] ;
  int len = 0 ;
  while(n--){
    char string[8] ;
    scanf("%s" , string) ;
    if(!strcmp(string , "push")){
      char word[2] ;
      scanf("%s" , word) ;
      contents[len] = word[0] ;
      ++len ;
    } else if(!strcmp(string , "pop")){
      if(len == 0){
        printf("Empty\n") ;
      }else{
        contents[len - 1]  = '\0' ;
        --len ;
      }
    } else if(!strcmp(string , "top")) {
      if (len == 0) {
        printf("Empty\n");
      } else {
        printf("%c\n", contents[len - 1]);
      }
    }else if(!strcmp(string , "print")){
        if(len == 0){
          printf("Empty\n") ;
        }else {
          for(int i = len - 1 ; i >= 0 ; --i){
            printf("| %c |\n" , contents[i]) ;
          }
          printf("|===|\n") ;
        }
      }

  }

  return 0;
}