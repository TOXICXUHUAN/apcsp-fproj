#include <stdio.h>
#include "battleship.h"

	void display(int board[5][5])
  {
    printf("\n");
    int i, j;
    for(i=0; i<5; i++) {
      for(j=0;j<5;j++) {
        if(board[i][j] != 3){
          printf("* ");
        }
        else{
          printf("%d ", 1);
        }
          if(j==4){
            printf("\n");
        }
      }
    }
  }
  void check(int board[5][5])
  {
    int i, j;
    int n = 0;
    for(i=0; i<5; i++) {
      for(j=0;j<5;j++) {
        if (board[i][j] == 1)
        {
          n = n + 1;          
          
        }
      }
    }
printf("There are %d enemies left on the battlefield\n", n);
if (n == 0)
          {
            printf("GAME OVER");
          }
  }
