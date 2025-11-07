#include "board.h"
#include <stdio.h>

char board[EIGHT][EIGHT];

void ResetBoard()
{
    for(int x = 0; x < EIGHT; x++)
    {
        for(int y = 0; y < EIGHT; y++)
        {
            switch (x)
            {
            case 0:
                board[x][y] = BLACK_BACK_ROW[y];
                break;
            case 1:
                board[x][y] = BLACK_FRONT_ROW[y];
                break;
            case EIGHT-2:
                board[x][y] = WHITE_FRONT_ROW[y];
                break;
            case EIGHT-1:
                board[x][y] = WHITE_BACK_ROW[y];
                break;
            default:
                board[x][y] = BLANK;
                break;
            }
        }
    }
}

void PrintBoard()
{
    printf("%s", LETTERS_ROW);
    printf("%s", LINE_ROW);
    for(int i = 0; i < EIGHT; i++)
    {
        printf("%d |", i+1);
        for(int j = 0; j < EIGHT; j++)
        {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("%s", LINE_ROW);
    }
}

/*

    A   B   C   D   E   F   G   H
  |-------------------------------|
1 | r | n | b | q | k | b | n | r |
  |-------------------------------|
2 | p | p | p | p | p | p | p | p |
  |-------------------------------|
3 |   |   |   |   |   |   |   |   |
  |-------------------------------|
4 |   |   |   |   |   |   |   |   |
  |-------------------------------|
5 |   |   |   |   |   |   |   |   |
  |-------------------------------|
6 |   |   |   |   |   |   |   |   |
  |-------------------------------|
7 | P | P | P | P | P | P | P | P |
  |-------------------------------|
8 | R | N | B | Q | K | B | N | R |
  |-------------------------------|

  Turn: WHITE
  Type your move: 
*/