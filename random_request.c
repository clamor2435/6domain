#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHARA 256 /*一行の最大文字バイト数*/

/*↓ここを変更*/
#define Node 6 //発ノード、着ノードになるのはノード番号1～6まで。
//6-domain.txt の内容を参照。
#define Index 4 //最高要求スロット数*/
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
int random_index(int request){
  int j = 0;
  while(1){
    if(j != request){
      j = j + 1;
      printf("%d %d \n",j,rand()%Index+1);
    }else break;
  }
  return(0);
}
int main(int argc, char *argv[]){
  int request;/*リクエスト数入力*/
  int k = 0;
  FILE *fp; /*FILE型の構造体*/
  char fname[] = "6-domain.txt";/*ファイル名入力*/
  char str[CHARA];
  request = atoi(argv[1]);
  /*scanf("%d",&request);リクエスト数入力*/
  printf("param R :=%d;\n",request);/*リクエスト数出力*/
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
  random_index(request);
  printf(";\n");
  printf("end;");
  return(0);
}
