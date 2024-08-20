//
// Created by weslie on 2023/11/27.
//
#include<stdio.h>
int main(){
  const double PI = 3.14 ;

  int radius1 = 100;
  printf("radius1 = %d\n" , radius1) ;
  printf("&radius1 = %p\n" , &radius1) ; //&: address-of operator

  radius1 = 200 ;  //左值 表示一个地址
  double circumference = 2 * PI * radius1 ; //右值 表示数
  printf("circumference = %lf\n" , circumference) ;
  int *ptr_radius1 = &radius1 ;  //建议就让*跟在变量前面
  //type : int *     value : &radius1

  printf("&ptr_radius = %p\n" , &ptr_radius1) ; //&取了这个指针变量的地址




  //* 间接运算符（定义时是类型名的一部分）
  // *ptr_radius1 behaves the same as radius1
  *ptr_radius1 = 200 ;
  printf("radius1 = %d\n" , radius1) ; //成功用*ptr 修改了radius1
  circumference = 2 * PI * (*ptr_radius1) ;

  int radius_1 = 1000;
  int *ptr_radius_1 = &radius_1 ;
  ptr_radius1 = ptr_radius_1 ; //现在两个指针指向同一变量

  *ptr_radius_1 = 2000 ;
  printf("radius_1 = %d\n" , *ptr_radius1) ;

  int v = 100 ;
  int *pv = &v ;

  int arr[] = {1,2,3} ;



  return 0 ;
}