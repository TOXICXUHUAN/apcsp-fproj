#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "battleship.h"

int main(int argc, char* argv[]) {
  srand ( time(NULL) );
  if (argc != 4)
  {
    printf("%s : expected 3 args, please enter 3 integers\n", argv[0]);
    return 1;
  }
  int arg1;
  int found = sscanf(argv[1], "%d", &arg1);
  if (found != 1)
  {
    printf("first arg is not an integer, enter 3 ints\n");
    return 1;
  }
  int arg2;
  found = sscanf(argv[2], "%d", &arg2);
  if (found != 1)
  {
    printf("second arg is not an integer, enter 3 ints\n");
    return 1;
  }
  int arg3;
  found = sscanf(argv[3], "%d", &arg3);
  if (found != 1)
  {
    printf("third arg is not an integer, enter 3 ints\n");
    return 1;
  }

  int board[5][5];
  int i, j;
  FILE *in, *out;
  if(arg3 == 1){ 
    out = fopen("./board.txt","w");
    for(i=0; i<5; i++) {
        for(j=0;j<5;j++) {
           board[i][j] = rand() % 2;
           fprintf(out, "%d\n", board[i][j]);
        }
     }
    fclose(out);
    display(board);
  }
  else{
    in = fopen("./board.txt","r");
    for (i=0;i<5;i++){
      for(j=0;j<5;j++){
        fscanf(in,"%d",&(board[i][j]));
      }
    }
    fclose(in);
    if (board[arg1][arg2] == 1)
    {
      printf("Bullseye, we hit the target");
      board[arg1][arg2] = 3;
      out = fopen("./board.txt","w");
      for(i=0;i<5;i++){
        for(j=0;j<5;j++){
          fprintf(out,"%d\n",board[i][j]);
        }
      }
      fclose(out);
      
    }
    else
    {
      printf("We didn't hit the target.");
    }
    display(board);
    check(board);
  }
  //display(board);
  //check(board);
}

