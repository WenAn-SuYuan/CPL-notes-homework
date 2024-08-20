//
// Created by weslie on 2023/10/23.
//
#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 6

const int board[SIZE][SIZE] = {
    {0},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0},
    {0}
};

/*const int board[SIZE][SIZE] = {
    [1][1] = 1 , [1][2] = 1,
    [2][1] = 1 , [2][2] = 1,
    [3][3] = 1 , [3][4] = 1,
    [4][3] = 1 , [4][4] = 1,
};*/

int main() {
  //board => new_board
  int old_board[SIZE + 2][SIZE + 2] = {0};

  for (int row = 1; row <= SIZE; row++) {
    for (int col = 1; col <= SIZE; col++) {
      old_board[row][col] = board[row - 1][col - 1];
    }
  }

  for (int row = 01; row <= SIZE; row++) {
    for (int col = 1; col <= SIZE; col++) {
      printf("%c ", old_board[row][col] ? '*' : ' ');
    }
    printf("\n");
  } //print the initial board
  system("clear");

  //old_board => new_board
  int new_board[SIZE + 2][SIZE + 2] = {0};
  for (int i = 0; i < 10; ++i) {
    for (int row = 1; row <= SIZE; row++) {
      for (int col = 1; col <= SIZE; col++) {
        //counting the live cells in the neighbor of old_board
        int neighbors =
            old_board[row - 1][col - 1] +
                old_board[row - 1][col] +
                old_board[row - 1][col + 1] +
                old_board[row][col - 1] +
                old_board[row][col + 1] +
                old_board[row + 1][col - 1] +
                old_board[row + 1][col] +
                old_board[row + 1][col + 1];

        //apply the rule
        if (old_board[row][col]) {
          /*if(neighbors == 2 || neighbors == 3){
            new_board[row][col] = 1 ;
          } else {
            new_board[row][col] = 0 ;
          }*/
          //可有如下简化：利用存活和”真“表达式值均为1
          new_board[row][col] = (neighbors == 2 || neighbors == 3);
        } else {
          new_board[row][col] = (neighbors == 3);
        }

      }
    }

    for (int row = 01; row <= SIZE; row++) {
      for (int col = 1; col <= SIZE; col++) {
        printf("%c ", new_board[row][col] ? '*' : ' ');
      }
      printf("\n");
    } //print the result

    sleep(1);//让程序停一会， （ ）内为秒
    //Windows上，用Sleep，头文件为windows.h ,（ ）内为毫秒

    system("clear");//清空控制台
    //Windows为 system("cls")

    for (int row = 01; row <= SIZE; row++) {
      for (int col = 1; col <= SIZE; col++) {
        old_board[row][col] = new_board[row][col];
      }
    } // 新的赋值为旧
  }

  return 0;
}


