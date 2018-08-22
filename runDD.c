/*ramdom.c*/
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHARA 256 /*一行の最大文字バイト数*/

/*↓ここを変更*/
#define Node 42 /*全ノード数*/
/*↑ここを変更*/

int randomize(int request){
  int j = 0;
  while(1){
    if(j != request){
      j = j + 1;
      printf("%d %d \n",j,rand()%Node+1);
    }else break;
  }
  return(0);
}

int main(int argc, char *argv[]){
  int request;/*リクエスト数入力*/
  int k = 0;
  FILE *fp; /*FILE型の構造体*/
  char fname[] = "runDD1.txt";/*ファイル名入力*/
  char str[CHARA];
  request = atoi(argv[1]);/*リクエスト数の整数化*/
  fp = fopen(fname,"r");/*ファイル名の代入*/

  while(fgets(str,CHARA,fp) != NULL){/*runDD.txt内容を出力*/
    printf("%s",str);
  }
  fclose(fp);
  printf("data %d.dat;\n",request);
  printf("solve;\n");
  printf("option omit_zero_rows 1, display_1col 1000;\n");
  printf("display Index, _solve_time, xp, xb, r >> DD%d.txt ;\n",request);
  return(0);
}
