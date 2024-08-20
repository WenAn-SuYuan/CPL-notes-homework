#include <stdio.h>
#include <string.h>
#define N 20

int n;
char s[N], t[N];
int main(){
  scanf("%d", &n);
  while(n--){
    scanf("%s", s);
    int l = strlen(s);
    int m = 0, nag = 0, flag = 0, cnt = 0;

    if(s[0] == '-') nag = 1;
    for(int i=l-1, j=1;i>=nag;--i, j*=10){
      if(s[i] >= '0' && s[i] <= '9'){
        m += (s[i]-'0')*j;
      }else{
        flag = 1; break;
      }
    }

    if(flag){
      printf("Radix Error\n");
      continue;
    }else if(m == 0){
      printf("0\n");
      continue;
    }

    while(m>0){
      t[++cnt] = m % 3;
      m /= 3;
    }

    for(int i=1;i<cnt;++i){
      // printf("%d", t[i]);
      if(t[i] == 2){
        t[i] = 'Z';
        t[i+1] += 1;
      }else if(t[i] == 3){
        t[i] = 0;
        t[i+1] += 1;
      }
    }
    // printf("\n");
    if(t[cnt] == 2){
      t[cnt] = 'Z';
      t[++cnt] = 1;
    }else if(t[cnt] == 3){
      t[cnt] = 0;
      t[++cnt] = 1;
    }
    // printf("cnt %d\n", cnt);
    for(int i=cnt;i>=1;--i){
      if(t[i] == 'Z'){
        printf("%c", nag?'1':'Z');
      }else if(t[i] == 1){
        printf("%c", nag?'Z':'1');
      }else if(t[i] == 0){
        printf("0");
      }
    }
    printf("\n");
  }
}