#include<stdio.h>
int main(){
  int num = 0 ;
  scanf("%x" , &num) ;
  int *p_num = &num ;
  unsigned int *p_unum = (unsigned int *)&num ;
  float *p_fnum =(float *)&num ;
  printf("%d\n%u\n%.6lf\n%.3e\n" , *p_num , *p_unum, *p_fnum , *p_fnum) ;
  return 0 ;
}