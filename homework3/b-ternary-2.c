//
// Created by weslie on 2023/10/17.
//
#include<stdio.h>
#include <string.h>
int main(){
  int n = 0 ;
  scanf("%d" , &n );
  getchar() ;
  char str[20] ;

  while( n-- ) {

    for(int i = 0 ; i < 20 ; i++){
      str[i] = '\0' ;
    }
    //初始化str，避免str在循环中值存留

    scanf("%s", str);
    int size = strlen(str);
//输入str，并计算字符长度

    int f = 0 ;
    for (int i = 0  ; i < size; ++i) {
      if (str[i] == 'Z') {
        printf("Radix Error\n");
        f = 1;
        break;
      }
    }
    //这个小的for循环，用于检查有无Z

    if (f) {
      continue;
    }
    //如果有Z，终止此循环，进入下一次

    int  k = 0 ;
    if (str[0] == '-') {
      k = 1;
      for (int i = 0; i < size ; ++i) {
        str[i] = str[i + 1];
      }
      --size;
    }
    //若为负数，做个标记 ， 并去掉负号

    int ten_num = 0;
    unsigned long int ten_it = 1;
    for (int i = size - 1; i >= 0; --i, ten_it *= 10) {
      ten_num = (str[i] - 48) * ten_it + ten_num;
    }
//拼成十进制

    if (ten_num == 0){
      printf("0\n") ;
      continue ;
    }

    unsigned long int three_num = 0;
    int three_it = 3;
    int count = 0;

    for ( ten_it = 1, count = 0 ; ten_num > 0; ten_it *= 10) {

      three_num = (ten_num % three_it) * ten_it + three_num;
      ten_num = ten_num / three_it;
      count++;
    }
    // 十进制转化为三进制,并计算三进制位数
    int numbers[10005] = {0};
    for (int i = count - 1; i >= 0; i--) {
      numbers[i] = three_num % 10;
      three_num = three_num / 10;
    }
    //三进制位数拆开，变为数组
    char numbers_swap[20];
    for(int i = 0 ; i < 20 ; i++){
      numbers_swap[i] = '\0' ;
    }

    for (int i = count - 1; i >= 0; i--) {
      switch (numbers[i]) {
        case 0 : numbers_swap[i + 1] = '0';
          break;
        case 1 : numbers_swap[i + 1] = '1';
          break;
        case 2 : numbers_swap[i + 1] = 'Z';
          if (i != 0) {
            numbers[i - 1] = numbers[i - 1] + 1 ;
          } else {
            numbers_swap[0] = '1' ;
          }
          break ;
        case 3 : numbers_swap[i + 1] = '0' ;
          if (i != 0 ){
            numbers[i - 1] = numbers[i - 1] + 1 ;
          } else {
            numbers_swap[0] = '1' ;
          }
          break ;
      }
    }//转换为平衡三进制，i= 0 待定
    if(numbers_swap[0] == '\0'){
      for(int i = 0 ; i <= count ; i++) {
        numbers_swap[i] = numbers_swap[i + 1];
      }
    }
    // 处理i= 0

    if(k){
      for (int m = 0 ; m <= count ; m++){
        if(numbers_swap[m] == '1'){
          numbers_swap[m] = 'Z' ;
        } else if(numbers_swap[m] == 'Z'){
          numbers_swap[m] = '1' ;
        }
      }
    }

    printf("%s\n" , numbers_swap) ;

  }

  return 0 ;
}