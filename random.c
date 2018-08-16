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
  char fname[] = "6-node_data.txt";/*ファイル名入力*/
  char str[CHARA];
  request = atoi(argv[1]);
  /*scanf("%d",&request);リクエスト数入力*/
  printf("param R := %d;\n",request);/*リクエスト数出力*/
  fp = fopen(fname,"r");

  while(fgets(str,CHARA,fp) != NULL){/*6-node_data.txt内容を出力*/
    printf("%s",str);
  }
  fclose(fp);
  srand((unsigned int)time(NULL));


  printf("param :s :=\n");/*ソースノード*/
  randomize(request);
  printf(";\n");
  printf("param :d :=\n");/*デスティネーションノード*/
  randomize(request);
  printf(";\n");
  printf("param :r :=\n");/*スロット数*/
  while(1){
    if(k != request){
      k = k + 1;
      printf("%d 2 \n",k);/*要求スロット数は2で固定*/
    }else break;
  }
  printf(";\n");
  printf("end;");
  return(0);
}
