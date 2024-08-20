#include<stdio.h>
#include<string.h>
#include <math.h>
#include<stdbool.h>
int main(){
  int n = 0 ;
  scanf("%d", &n) ;
  getchar() ;
  char word[1000][20] ;
  for (int i = 0 ; i < n ; ++i){
    scanf("%s" ,word[i]) ;
    getchar() ;
  }  //input

  for(int i = 0 ; i < n ; ++i){
    int size1 = strlen(word[i]);
    for (int j = 0 ; j < size1 ; ++j){
      bool is_num = true ;
      for( j = 0 ; j < size1 ; ++j ){
        if(!(word[i][j] == '0' || word[i][j] == '1' || word[i][j] == 'Z')){
          is_num = false ;
          break ;
        }
      }
      //decide Radix Error
      if (is_num == false){
        printf ("Radix Error\n");
        break ;
      } else {
        int size = strlen(word[i]);
        int number[20] = { 0 };
        for( j = 0 ; j < size ; j++){
          if(word[i][j] == 'Z'){
            number[j] = -1 ;
          } else if (word[i][j] == '1'){
            number[j] = 1;
          } else {
            number[j] = 0;
          }
        }//change char into int
          int result = 0 ;
        for( j = 0 ; j < size ; j++){
            result =  result + number[j] * pow(3 , size - 1 - j) ;
          }
        printf("%d\n", result) ;
        break ;
      }
    }
  }

  return 0 ;
}