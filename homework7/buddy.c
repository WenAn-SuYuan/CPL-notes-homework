#include<stdio.h>
#include<math.h>
#define LEN 10005
int FindMinTwo(int num) ;
void Q(int total , int IDnum[]) ;
int A(int id , int mintwo , int array[] , int IDnum[], int total) ;
void GoBehind(int array[] ,int startpoint , int len );



int main(){
  int n = 0 , q = 0;
  scanf("%d %d" , &n , &q) ;
  int array[LEN] = { 0 };
  array[0] = pow(2 , n) ;
  int IDnum[LEN] = { 0 };
  int total = 1 ;


  while(q--){
    char op[2] ;
    scanf("%s" , op) ;
    //printf("%d\n\n\n" , total) ;
    if(op[0] == 'Q'){
      Q(total , IDnum) ;
    } else if(op[0] == 'A'){
      int id = 0 ;
      int m = 0 ;
      scanf("%d %d" , &id , &m);
      int mintwo = FindMinTwo(m) ;
      int temp = A(id , mintwo , array ,IDnum , total) ;
      total = temp ;

      //debug
     // printf("%d" , temp) ;
      //debug
    }

  }


  return 0 ;
}

int FindMinTwo(int num){
  int mintwo = 0 ;
  for(int i = 0 ; i < 30 ; ++i ){
    if(pow(2 , i) >= num){
      mintwo = pow(2 , i) ;
      return mintwo ;
    }
  }
}

void Q(int total , int IDnum[]){
  printf("%d\n" , total) ;
  for(int i = 0 ; i < total ; ++i){
    printf("%d " , IDnum[i]) ;
  }
  printf("\n") ;
}
/**
 * 一定注意，递归时别把变量递归给换没了！
 * @param id
 * @param mintwo
 * @param array
 * @param IDnum
 * @param total
 * @return
 */

int A(int id , int mintwo , int array[] , int IDnum[] ,int total){
  for(int i = 0 ; i < total ; ++i){
    if(array[i] == mintwo){
      IDnum[i] = id ;
      array[i] = -1 ;
      return total ;
    }
  }

  for(int i = 0 ; i < total ; ++i){
    if(array[i] > mintwo){
      int tem = array[i] ;
      GoBehind(array , i , total) ;
      array[i] = tem / 2 ;
      array[i + 1] = tem / 2 ;
      GoBehind(IDnum , i , total) ;
      IDnum[i] = 0 ;
      IDnum[i + 1] = 0 ;
      ++total ;
      break ;
    }

  }
  int finaltotal = A(id , mintwo , array , IDnum , total) ;
  return finaltotal ;
}

void GoBehind(int array[] ,int startpoint , int len ){
  for(int i = len - 1 ; i > startpoint ; --i){
    array[i + 1] = array[i] ;
  }
  array[startpoint] = 0 ;
  array[startpoint + 1] = 0 ;
}
