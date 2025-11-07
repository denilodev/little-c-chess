#include "board.h"
#include <stdio.h>

char BLACK_BACK_ROW[EIGHT]  = "rnbqkbnr";   // Forsyth-Edwards Notation
char BLACK_FRONT_ROW[EIGHT] = "pppppppp";
char WHITE_FRONT_ROW[EIGHT] = "PPPPPPPP";
char WHITE_BACK_ROW[EIGHT]  = "RNBQKBNR";
char board[EIGHT][EIGHT];

void ResetBoard()
{
    for(int x = 0; x < EIGHT; x++)
    {
        for(int y = 0; y < EIGHT; y++)
        {               // the idea here is to populate the tiles based on each
            switch (x)  // character of the "...ROW" strings (those four above) 
            {
            case 0:         // tiles of first row
                board[x][y] = BLACK_BACK_ROW[y];
                break;
            case 1:         // tiles of second row
                board[x][y] = BLACK_FRONT_ROW[y];
                break;
            case EIGHT-2:   // tiles of second to last row
                board[x][y] = WHITE_FRONT_ROW[y];
                break;
            case EIGHT-1:   // tiles of last row
                board[x][y] = WHITE_BACK_ROW[y];
                break;
            default:        // empty tile
                board[x][y] = BLANK;
                break;
            }
        }
    }
}

void PrintBoard()
{
    printf("%s", LETTERS_ROW);  // print the letters above the board
    printf("%s", LINE_ROW);     // print first line
    for(int i = 0; i < EIGHT; i++)
    {
        printf("%d |", i+1);    // print the numbers aside the board
        for(int j = 0; j < EIGHT; j++) // print every tile on the row "i"
        {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("%s", LINE_ROW); // print new line
    }
}

/*

    A   B   C   D   E   F   G   H           // "LETTERS_ROW"
  |-------------------------------|         // "LINE_ROW"
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

  Turn: WHITE                               // soon
  Type your move:                           // soon
*/