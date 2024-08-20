//
// Created by weslie on 2023/12/5.
//
#include<stdio.h>
#include <stdlib.h>
#define LEN 155
#define BIG 1050
#include<string.h>
int main(){
  char *rule = malloc(LEN * sizeof (char)) ;
  scanf("%s" , rule) ;

  char *name = malloc(BIG * sizeof (char)) ;
  scanf("%s", name) ;
  printf("%s" , name) ;

  char *ans = malloc(BIG * sizeof (char)) ;
  char *ans_move = ans ;

  char *string = malloc(BIG * sizeof (char)) ;
  int nag = 1 ;
  while(scanf("%s" , string) != EOF){
    int flag = 0 ;
    //flag refers to whether it is a invalid parse

    if(*string == '-'){
      char *rule_move = rule ;
      for( ; rule_move < rule + strlen(rule) ; ++rule_move){
        if(*rule_move == *(string + 1)){
          flag = 1 ;
          break ;
        }
      } //judge invalid(flag = 0) or not(flag = 1)

      if(!flag){ // invalid
        nag = 0 ;
        printf(": invalid option -- '%c'" ,  *(string + 1)) ;
        break ;  //invalid error and break
      } else { //valid
        if(*(rule_move + 1) == ':'){ // need a parse after it
          char *after_parse = malloc(BIG * sizeof (char)) ;
          if(scanf("%s" , after_parse) == EOF){
            nag = 0 ;
            printf(": option requires an argument -- '%c'", *(string + 1)) ;
            break;
          } else {
            *ans_move = '\n' ;
            ++ans_move ;
            *ans_move = *(string + 1) ;
            ++ans_move ;
            *ans_move = '=' ;
            ++ans_move ;
            for(char *after_parse_end = after_parse + strlen(after_parse) ;
                after_parse < after_parse_end ; ++after_parse, ++ans_move){
              *ans_move = *after_parse ;
            }
            continue ;
          }


        } else {
          *ans_move = '\n' ;
          ++ans_move ;
          *ans_move = *(string + 1) ;
          ++ans_move ;
          continue ;
        }

      }

    }
  }

  if(nag) {
    printf("%s", ans);
  }
  free(rule) ;
  free(string) ;
  free(name) ;

  return 0 ;
}