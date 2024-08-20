#include<stdio.h>
#include <string.h>
#define LEN 100005

int main(){
  int T = 0 ;
  scanf("%d" , &T) ;
  char contents[LEN] ;
  memset(contents , 0 , sizeof contents) ;

  while(T--){
    int flag = 1 ;
    char string[LEN] ;
    memset(string , 0 , sizeof string) ;
    int top = 0 ;
    scanf("%s" , string);
    int len = strlen(string) ;
    for(int i = 0 ; i < len ; ++i){
      if(string[i] == '(' || string[i] == '[' || string[i] == '{'){
        contents[top] = string[i] ;
        ++top ;
      } else if(string[i] == ')'){
        if(contents[top - 1] == '('){
          contents[top - 1] = '\0' ;
          --top ;
        } else {
          flag = 0 ;
          break ;
        }
      } else if(string[i] == ']'){
        if(contents[top - 1] == '['){
          contents[top - 1] = '\0' ;
          --top ;
        } else {
          flag = 0 ;
          break ;
        }
      } else if(string[i] == '}'){
        if(contents[top - 1] == '{'){
          contents[top - 1] = '\0' ;
          --top ;
        } else {
          flag = 0 ;
          break;
        }
      }
    }
    if(flag && !top ){
      printf("True\n") ;
    } else {
      printf("False\n") ;
    }



  }




  return 0 ;
}
