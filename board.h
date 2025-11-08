/*

    A   B   C   D   E   F   G   H
  |-------------------------------|
8 | r | n | b | q | k | b | n | r |
  |-------------------------------|
7 | p | p | p | p | p | p | p | p |
  |-------------------------------|
6 |   |   |   |   |   |   |   |   |
  |-------------------------------|
5 |   |   |   |   |   |   |   |   |
  |-------------------------------|
4 |   |   |   |   |   |   |   |   |
  |-------------------------------|
3 |   |   |   |   |   |   |   |   |
  |-------------------------------|
2 | P | P | P | P | P | P | P | P |
  |-------------------------------|
1 | R | N | B | Q | K | B | N | R |
  |-------------------------------|

  Turn: WHITE
  Type your move: 
*/
#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

#ifndef TILE
#define TILE            char*
#endif
#define EIGHT           8   // no magic numbers (what if I want to
                            // change the size of the board one day?)
#define LETTERS_ROW     "    A   B   C   D   E   F   G   H\n"
#define LINE_ROW        "  |-------------------------------|\n"
#define BLANK           ' '

extern char BLACK_BACK_ROW[EIGHT];   // Forsyth-Edwards Notation
extern char BLACK_FRONT_ROW[EIGHT];
extern char WHITE_FRONT_ROW[EIGHT];
extern char WHITE_BACK_ROW[EIGHT];
extern char board[EIGHT][EIGHT];

void DrawBoard();
void DrawGame();
void DrawGameOver();
TILE GetTileAddress(char [3]);
void ClearScreen();

#endif