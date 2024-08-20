//
// Created by weslie on 2023/10/28.
//
#include<stdio.h>
#include<stdbool.h>
bool IsLeapYear (int year) ;

int main(){
  int year = 0 ;
  scanf("%d", &year);
//逻辑语句的使用
  bool leap = IsLeapYear(year) ;

  if (leap){
    printf("%d is a leap year" , year) ;
  } else {
    printf("%d is a common year", year);
  }
  return 0 ;
}

bool IsLeapYear (int year) {
  bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ;
  return leap ;
}
