//
// Created by weslie on 2023/10/26.
//
#include<stdio.h>
#include<string.h>
#define LEN 1005
int main(){
  int n = 0 ;
  scanf("%d" , &n);
  char species[LEN] ;
  memset(species , '.' , sizeof(species)) ;
  scanf("%s" , species) ;
  int length = strlen(species) ;

  char new_map[LEN + 8] ;
  memset(new_map , '.' , sizeof(new_map)) ;
  for(int i = 3 ; i < length + 3 ; ++i){
    new_map[i] = species[i - 3] ;
  }

  int countA = 0 , countB = 0 ;
  char new_species[LEN + 8]  ;
  memset(new_species , '.' , sizeof(new_species)) ;

  while(n--){
    for (int i = 3; i < length + 3 ; ++i) {
      countA = 0;
      countB = 0;

      if (new_map[i] == '.') {
        for (int j = i - 3; j <= i + 3; j++) {
          if (new_map[j] == 'A') {
            ++countA;
          }

          if (new_map[j] == 'B') {
            ++countB;
          }

        }

        if (countA >= 2 && countA <= 4 && countB == 0) {
          new_species[i] = 'A';
        }
        if (countB >= 2 && countB <= 4 && countA == 0) {
          new_species[i] = 'B';
        }

      }
//上面为此处为空时
      if (new_map[i] == 'A') {
        for (int j = i - 3; j <= i + 3; ++j) {

          if (new_map[j] == 'A') {
            countA++;
          } else if (new_map[j] == 'B') {
            countB++;
          }

        }
        if (!(countB == 0 && countA - 1 >= 2 && countA - 1 <= 4)) {
          new_species[i] = '.';
        } else {
          new_species[i] = 'A' ;
        }
      }
      //上面处理A时

      if (new_map[i] == 'B') {
        for (int j = i - 3; j <= i + 3; ++j) {

          if (new_map[j] == 'A') {
            countA++;
          } else if (new_map[j] == 'B') {
            countB++;
          }

        }
        if (!(countA == 0 && countB - 1 >= 2 && countB - 1 <= 4)) {
          new_species[i] = '.';
        } else {
          new_species[i] = 'B' ;
        }
      }
      //上面处理B时

    }

    strncpy(new_map , new_species , LEN + 8) ;

    //for(int i = 0 ; i < LEN + 8 ; ++i){
      //new_map[i] = new_species[i] ;
    //}


  }

  for(int i = 3 ; i < length + 3 ; ++i){
    printf("%c" , new_map[i]) ;
  }

  return 0 ;
}