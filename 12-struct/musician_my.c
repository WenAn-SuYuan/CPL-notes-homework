#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

typedef enum gender{
  MALE,
  FEMALE,
}Gender;

typedef struct score {
  int c_score ; // 4
  int java_score ; // 4
  int python_score ; // 4
}Score;


// musician :不是类型名，严格说是tag(标记）
typedef struct musician { //这个结构体类型名是struct musician,不仅仅是musician
  //member : 成员 or field : 域
  char *name ; // 字节： 8
  //char gender ;  // 1   此处gender只有两种可能，适用枚举类型
  Gender gender ;
  char *album ; // 8

  Score score;
} Musician; //Musician 成为类型名



/**
 * 对齐过程：
 * 首先，找出最大字节，为8
 * 则它在安放时安放在地址为8倍数的位置
 *
 */

void Print(const Musician *m) ;
int CompareMusician(const void *m1, const void *m2);


int main(){
  printf("sizeof Musician = %zu\n", sizeof(Musician) ) ;
  //算出字节数为40，不一致
  //alignment ：对齐


  struct musician luo = {  //初始化，未初始化的会隐式初始化为0
      .name ="Luo Dayou",
      .gender = MALE,
      .album = "ZhiHuZheYe",
      .score = {
          .c_score = 0 ,
          .java_score = 10 ,
          .python_score = 20 ,
      }
  };

  struct musician cui = {
      .name ="Cui Jian",
      .gender = MALE,
      .album = "XinChangZhengLuShangDeYaoGun",
      .score = {
          .c_score = 0 ,
          .java_score = 10 ,
          .python_score = 20 ,
      }
  };

  char album[] = "YiKeBuKenMeiSuDeXin" ;
  Musician zhang = {
      .name ="Zhang Chu", //.name 是一个char *指针
      .gender = MALE,
      .album = album,
      .score = {
          .c_score = 0 ,
          .java_score = 10 ,
          .python_score = 20 ,
      }
  };

  Musician guo = zhang ; //结构体相互赋值
  guo.name = "Guo" ; //虽然是指针，但不会导致张楚被改，因为这里其实是修改了guo.name 指针指向"Guo"
  strcpy(guo.album , "YiKeMeiSuDeXin") ; //此时，张楚的专辑信息也被改掉
/**
 * 结构体有指针时，要小心！
 */

  //Print(&zhang) ;
  //Print(&guo) ;

  Musician musicians[] = {luo, cui, zhang}; //结构体数组
  int len = sizeof musicians / sizeof *musicians ;
  for(int i = 0 ; i < len ; ++i){
    Print(&musicians[i]) ;
  }

  printf("\n\n") ;
  qsort(musicians, len, sizeof *musicians, CompareMusician) ;

  for(int i = 0 ; i < len ; ++i){
    Print(&musicians[i]) ;
  }




  return 0 ;
}
void Print(const Musician *m){
  printf("%s\t%c\t%s\t%d\t%d\t%d\t",
         (*m).name ,
         (*m).gender,
         m->album,
         m->score.c_score,
         m->score.java_score,
         m->score.python_score) ; //-> : 当m为指针时，表示解引用
// . :成员访问运算符
// :结构体中结构体 连续访问
}

int CompareMusician(const void *m1, const void *m2) {
  const Musician *m_left = m1;
  const Musician *m_right = m2;

  return strcmp(m_left->name, m_right->name);
}
//由于结构体第一个成员是char *，则可以把结构体指针转为char **（指向第一个成员的指针）  但不推荐这样
