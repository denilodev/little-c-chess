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
#ifndef BOARD_H
#define BOARD_H

#define EIGHT           8

#define LETTERS_ROW     "    A   B   C   D   E   F   G   H\n"
#define LINE_ROW        "  |-------------------------------|\n"
#define BLANK           ' '
#define BLACK_BACK_ROW  "rnbqkbnr"
#define BLACK_FRONT_ROW "pppppppp"
#define WHITE_FRONT_ROW "PPPPPPPP"
#define WHITE_BACK_ROW  "RNBQKBNR"

void ResetBoard();
void PrintBoard();

#endif