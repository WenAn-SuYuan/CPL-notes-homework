//
// Created by weslie on 2023/10/26.
//
#include<stdio.h>
#include <stdlib.h>
int main(){
  int x_A = 0 , y_A = 0 , x_B = 0 , y_B = 0 , x_C = 0 , y_C = 0 ;
  scanf("%d %d %d %d %d %d" ,&x_A , &y_A , &x_B , &y_B , &x_C , &y_C) ;

  int flag = 1 , nag = 0 ;
  int length = abs(x_B - x_A) + abs(y_B - y_A) ;
//输入部分


  if((x_A == x_B && x_A == x_C) || (y_A == y_B && y_A == y_C) ){
    flag = 0 ;
  }
//判定ABC是否共线，0 为共线， 1为不共线

  if(flag){
    if(x_B - x_A > 0 && y_B - y_A > 0){
      nag = 1 ;
    } else if(x_B - x_A < 0 && y_B - y_A > 0){
      nag = 2 ;
    } else if (x_B - x_A < 0 && y_B - y_A < 0){
      nag = 3 ;
    } else if (x_B - x_A > 0 && y_B - y_A < 0){
      nag = 4 ;
    }

    //共线时判定AB相对方位


    printf("%d\n" , length) ;
//此时可直接输出步数

  if(nag == 1) {
    if (x_B != x_C) {
      for (int row = x_A; row < x_B; ++row) {
        printf("R");
      }

      for (int col = y_A; col < y_B; ++col) {
        printf("U");
      }
    } else {
      for (int col = y_A; col < y_B; ++col) {
        printf("U");
      }

      for (int row = x_A; row < x_B; ++row) {
        printf("R");
      }

    }
  }
  //B在A右上方，BC横坐标不同则先往右再往上，否则先往上再往右，防止阻挡 ， 下同

    if(nag == 2) {
      if (x_B != x_C) {
        for (int row = x_A; row > x_B; --row) {
          printf("L");
        }

        for (int col = y_A; col < y_B; ++col) {
          printf("U");
        }
      } else {
        for (int col = y_A; col < y_B; ++col) {
          printf("U");
        }

        for (int row = x_A; row > x_B; --row) {
          printf("L");
        }

      }
    }
    //B在A左上方

    if(nag == 3) {
      if (x_B != x_C) {
        for (int row = x_A; row > x_B; --row) {
          printf("L");
        }

        for (int col = y_A; col > y_B; --col) {
          printf("D");
        }
      } else {
        for (int col = y_A; col > y_B; --col) {
          printf("D");
        }

        for (int row = x_A; row > x_B; --row) {
          printf("L");
        }

      }
    }
    //B在A左下方

    if(nag == 4) {
      if (x_B != x_C) {
        for (int row = x_A; row < x_B; ++row) {
          printf("R");
        }

        for (int col = y_A; col > y_B; --col) {
          printf("D");
        }
      } else {
        for (int col = y_A; col > y_B; --col) {
          printf("D");
        }

        for (int row = x_A; row < x_B; ++row) {
          printf("R");
        }

      }
    }
    //B在A右下方
//下面开始处理共线
  } else {
    if (x_A == x_B && x_A == x_C) {
      if (y_A < y_B && !(y_B - y_C > 0 && y_C - y_A > 0)) {
        printf("%d\n" , length) ;
        for (int col = y_A; y_A < y_B; ++col) {
          printf("U");
        }
      }//在同一竖线上，且C不在AB之间， A在B下方

      if (y_B - y_C > 0 && y_C - y_A > 0) {
        printf("%d\n" , length + 2) ;
        printf("R");
        for (int col = y_A; y_A < y_B; ++col) {
          printf("U");
        }
        printf("L");
      }
       //在同一直线上且C在AB之间，A在B下方，绕开

      if (y_A > y_B && !(y_B - y_C < 0 && y_C - y_A < 0)) {
        printf("d\n" ,length) ;
        for (int col = y_A; y_A > y_B; --col) {
          printf("D");
        }
      }
 //在同一横线上，且C不在AB之间 ，A在B上方

      if (y_B - y_C < 0 && y_C - y_A < 0) {
        printf("%d\n" , length + 2) ;
        printf("R");
        for (int col = y_A; y_A > y_B; --col) {
          printf("D");
        }
        printf("L");
      }
  //A在B上方，且C在AB之间
    }

    if (y_A == y_B && y_A == y_C) {
      if (x_A < x_B && !(x_A < x_C && x_C < x_B)) {
        printf("%d\n" , length) ;
        for (int row = x_A; x_A < x_B; ++row) {
          printf("R");
        }
      }
      //ABC共横线， A在B左 ， C不在AB间

      if (x_A < x_C && x_C < x_B) {
        printf("%d\n" , length + 2) ;
        printf("U");
        for (int row = x_A; x_A < x_B; ++row) {
          printf("R");
        }
        printf("D");
      }
//ABC共横线， A在B左 ， C在AB间

      if (x_A > x_B && !(x_A > x_C && x_C > x_B)) {
        printf("%d\n" , length ) ;
        for (int row = x_A; x_A > x_B; --row) {
          printf("L");
        }
      }
//ABC共横线， A在B右 ， C不在AB间

      if (x_A > x_C && x_C > x_B) {
        printf("%d\n" , length + 2) ;
        printf("U");
        for (int row = x_A; x_A > x_B; --row) {
          printf("L");
        }
        printf("D");
      }

      //ABC共横线 A在B右 ， C在AB间
    }
  }

  return 0 ;
}