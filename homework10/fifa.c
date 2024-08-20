//
// Created by weslie on 2023/12/23.
//
#include<stdio.h>
#include <stdlib.h>
#define NAME_NUM 25
#define PLAYER_NUM 11
#define TEAM_NUM 1005

int CompareAttack(const void *m1, const void *m2) ;
int CompareDefend(const void *m1, const void *m2) ;
int CompareMethod(const void *m1, const void *m2) ;

typedef struct player{
  char name[NAME_NUM] ;
  int attack_score ;
  int defend_score ;
  int method_score ;
}Player;

typedef struct team{
  char team_name[NAME_NUM] ;
  Player player1 ;
  Player player2 ;
  Player player3;
  Player player4 ;
  Player player5 ;
  Player player6 ;
  Player player7 ;
  Player player8 ;
  Player player9 ;
  Player player10 ;
  Player player11 ;
}Team;
Team teams[TEAM_NUM] ;

int main(){
  int n = 0 ;
  scanf("%d", &n) ;
  for(int i = 0 ; i < n ; ++i){
    scanf("%s", teams[i].team_name) ;

    scanf("%s %d %d %d",teams[i].player1.name,&teams[i]. player1.attack_score,
    &teams[i].player1.defend_score, &teams[i].player1.method_score) ;
    scanf("%s %d %d %d", teams[i].player2.name,&teams[i]. player2.attack_score,
          &teams[i].player2.defend_score, &teams[i].player2.method_score) ;
    scanf("%s %d %d %d", teams[i].player3.name,&teams[i]. player3.attack_score,
          &teams[i].player3.defend_score, &teams[i].player3.method_score) ;
    scanf("%s %d %d %d", teams[i].player4.name,&teams[i]. player4.attack_score,
          &teams[i].player4.defend_score, &teams[i].player4.method_score) ;
    scanf("%s %d %d %d", teams[i].player5.name,&teams[i]. player5.attack_score,
          &teams[i].player5.defend_score, &teams[i].player5.method_score) ;
    scanf("%s %d %d %d", teams[i].player6.name,&teams[i]. player6.attack_score,
          &teams[i].player6.defend_score, &teams[i].player6.method_score) ;
    scanf("%s %d %d %d", teams[i].player7.name,&teams[i]. player7.attack_score,
          &teams[i].player7.defend_score, &teams[i].player7.method_score) ;
    scanf("%s %d %d %d", teams[i].player8.name,&teams[i]. player8.attack_score,
          &teams[i].player8.defend_score, &teams[i].player8.method_score) ;
    scanf("%s %d %d %d", teams[i].player9.name,&teams[i]. player9.attack_score,
          &teams[i].player9.defend_score, &teams[i].player9.method_score) ;
    scanf("%s %d %d %d", teams[i].player10.name,&teams[i]. player10.attack_score,
          &teams[i].player10.defend_score, &teams[i].player10.method_score) ;
    scanf("%s %d %d %d", teams[i].player11.name,&teams[i]. player11.attack_score,
          &teams[i].player11.defend_score, &teams[i].player11.method_score) ;
  }

  qsort(teams, n, sizeof *teams, CompareAttack) ;
  for(int i = n - 1 ; i >= 0 ; --i) printf("%s ", teams[i].team_name) ;
  printf("\n") ;

  qsort(teams, n , sizeof *teams, CompareDefend) ;
  for(int i = n - 1 ; i >= 0 ; --i) printf("%s ", teams[i].team_name) ;
  printf("\n") ;

  qsort(teams, n , sizeof *teams, CompareMethod) ;
  for(int i = n - 1 ; i >= 0 ; --i) printf("%s ", teams[i].team_name) ;
  printf("\n") ;



  return 0 ;
}
int CompareAttack(const void *m1, const void *m2){
  const Team *left_t = m1 ;
  const Team *right_t = m2 ;
  double left_attack = (left_t->player1.attack_score + left_t->player2.attack_score +
      left_t->player3.attack_score +left_t->player4.attack_score +left_t->player5.attack_score +
      left_t->player6.attack_score +left_t->player7.attack_score +left_t->player8.attack_score +
      left_t->player9.attack_score +left_t->player10.attack_score +left_t->player11.attack_score) / 11.0 ;

  double right_attack = (right_t->player1.attack_score + right_t->player2.attack_score +
      right_t->player3.attack_score +right_t->player4.attack_score +right_t->player5.attack_score +
      right_t->player6.attack_score +right_t->player7.attack_score +right_t->player8.attack_score +
      right_t->player9.attack_score +right_t->player10.attack_score +right_t->player11.attack_score) / 11.0 ;

  if(left_attack < right_attack) return -1 ;
  else if(left_attack > right_attack) return 1 ;
  else return 0 ;
}
int CompareDefend(const void *m1, const void *m2){
  const Team *left_t = m1 ;
  const Team *right_t = m2 ;
  double left_defend = (left_t->player1.defend_score + left_t->player2.defend_score +
      left_t->player3.defend_score +left_t->player4.defend_score +left_t->player5.defend_score +
      left_t->player6.defend_score +left_t->player7.defend_score +left_t->player8.defend_score +
      left_t->player9.defend_score +left_t->player10.defend_score +left_t->player11.defend_score) / 11.0 ;

  double right_defend = (right_t->player1.defend_score + right_t->player2.defend_score +
      right_t->player3.defend_score +right_t->player4.defend_score +right_t->player5.defend_score +
      right_t->player6.defend_score +right_t->player7.defend_score +right_t->player8.defend_score +
      right_t->player9.defend_score +right_t->player10.defend_score +right_t->player11.defend_score) / 11.0 ;

  if(left_defend < right_defend) return -1 ;
  else if(left_defend > right_defend) return 1 ;
  else return 0 ;
}
int CompareMethod(const void *m1, const void *m2){
  const Team *left_t = m1 ;
  const Team *right_t = m2 ;
  double left_method = (left_t->player1.method_score + left_t->player2.method_score +
      left_t->player3.method_score +left_t->player4.method_score +left_t->player5.method_score +
      left_t->player6.method_score +left_t->player7.method_score +left_t->player8.method_score +
      left_t->player9.method_score +left_t->player10.method_score +left_t->player11.method_score) / 11.0 ;

  double right_method = (right_t->player1.method_score + right_t->player2.method_score +
      right_t->player3.method_score +right_t->player4.method_score +right_t->player5.method_score +
      right_t->player6.method_score +right_t->player7.method_score +right_t->player8.method_score +
      right_t->player9.method_score +right_t->player10.method_score +right_t->player11.method_score) / 11.0 ;

  if(left_method < right_method) return -1 ;
  else if(left_method > right_method) return 1 ;
  else return 0 ;
}
