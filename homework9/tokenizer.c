//
// Created by weslie on 2023/12/6.
//
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100005
#define LENGTH 5005
const char *reserved[16] = {"const", "int", "float", "double", "long", "static",
                            "void", "char" , "extern", "return", "break",
                            "enum", "struct", "typedef", "union", "goto"};
const char *operator[11] = {"+", "-", "*", "/", "=", "==",
                            "!=", ">=", "<=", ">", "<"};

int Judge(char *s, const char *block );
char *ans ;
char *ans_move ;


int main(){
  ans = malloc(LEN * sizeof (char)) ;
  ans_move = ans ;
  char *s = malloc(LENGTH * sizeof (char)) ;
  int flag = 1 ;
  while(scanf("%s", s) != EOF){

    char *position = strchr(s, ';') ;
    if(position == NULL){
      flag = Judge(s, " ") ;
      if(!flag){
        break ;
      }
    } else {
      char *s_cpy = malloc(LENGTH * sizeof(char)) ;
      memset(s_cpy, 0 , LENGTH * sizeof(char)) ;
      char *s_cpy_move = s_cpy ;
      char *s_end = s + strlen(s) - 1 ;
      char *s_move = s ;
      while(1==1){
        if(*s_move != ';'&& s_move <= s_end){
          *s_cpy_move = *s_move ;
          ++s_move ;
          ++s_cpy_move ;
        } else {
          if (s_cpy == s_cpy_move && s_move <= s_end) {
            *ans_move = '\n';
            ++ans_move;
            ++s_move ;
          } else if(s_move > s_end && s_cpy != s_cpy_move){
            flag = Judge(s_cpy, " ") ;
            break;
          } else if(*s_move == ';'){
            flag = Judge(s_cpy, "\n");
            memset(s_cpy, 0, LENGTH * sizeof(char));
            s_cpy_move = s_cpy;
            ++s_move ;
            if (!flag) {
              break;
            }
          } else {
            break ;
          }

        }

      }
      if(!flag){
        break ;
      }


    }

  }

  if(flag){
    printf("%s" , ans) ;
  } else {
    printf("Compile Error") ;
  }





  return 0 ;
}
int Judge(char *s, const char *block){
  for(int i = 0 ; i < 16 ; ++i){
    if(strcmp(s, reserved[i]) == 0){
      strcat(ans, "reserved") ;
      ans_move += strlen("reserved") ;
      *ans_move = *block ;
      ++ans_move ;
      return 1 ;
    }
  }//reserved


  int int_flag = 1 ;
  for(int i = 0 ; i < strlen(s) ; ++i){
    if(!(s[i] >= '0' && s[i] <= '9')){
      int_flag = 0 ;
      break ;
    }
  }
  if(int_flag){
    strcat(ans, "integer") ;
    ans_move += strlen("integer") ;
    *ans_move = *block ;
    ++ans_move ;
    return 1 ;

  }
  //integer


  int int_float = 1 ;
  int sum_float = 0 ;
  for(int i = 0 ; i < strlen(s) ; ++i){
    if(!((s[i] >= '0' && s[i] <= '9') || s[i] == '.')){
      int_float = 0 ;
      break;
    } else if(s[i] == '.'){
      ++sum_float ;
    }

    if(sum_float > 1){
      int_float = 0 ;
      break ;
    }
  }

  if(int_float){
    strcat(ans, "float") ;
    ans_move += strlen("float") ;
    *ans_move = *block ;
    ++ans_move ;
    return 1 ;
  }
  //float


  for(int i = 0 ; i < 11; ++i){
    if(strcmp(s, operator[i]) == 0){
      strcat(ans, "operator") ;
      ans_move += strlen("operator") ;
      *ans_move = *block ;
      ++ans_move ;
      return 1 ;
    }
  }
  //operator

  int int_variable = 1 ;
  if(s[0] >= '0' && s[0] <= '9'){
    int_variable = 0 ;
  }
  if(int_variable) {
    for (int i = 0; i < strlen(s); ++i) {
      if (!((s[i] >= '0' && s[i] <= '9') ||
          (s[i] >= 'A' && s[i] <= 'Z') ||
          (s[i] >= 'a' && s[i] <= 'z') ||
          (s[i] == '_'))){
        int_variable = 0 ;
        break ;
      }

    }
  }
  if(int_variable){
    strcat(ans, "variable") ;
    ans_move += strlen("variable") ;
    *ans_move = *block ;
    ++ans_move ;
    return 1 ;
  }

  return 0 ;
}