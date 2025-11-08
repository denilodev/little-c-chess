#include "board.h"

char BLACK_BACK_ROW[EIGHT]  = "rnbqkbnr";   // Forsyth-Edwards Notation
char BLACK_FRONT_ROW[EIGHT] = "pppppppp";
char WHITE_FRONT_ROW[EIGHT] = "PPPPPPPP";
char WHITE_BACK_ROW[EIGHT]  = "RNBQKBNR";
char board[EIGHT][EIGHT];

void DrawBoard()
{
  ClearScreen();
  printf("%s", LETTERS_ROW);  // print the letters above the board
  printf("%s", LINE_ROW);     // print first line
  for(int i = 0; i < EIGHT; i++)
  {
      printf("%d |", EIGHT-i);    // print the numbers aside the board
      for(int j = 0; j < EIGHT; j++) // print every tile on the row "i"
      {
          printf(" %c |", board[i][j]);
      }
      printf("\n");
      printf("%s", LINE_ROW); // print new line
  }
}

void DrawGameOver()
{

}

TILE GetTileAddress(char tileName[3])
{
  char file = tileName[0];
  char rank = tileName[1];
  if (file >= 'A' && file <= 'H') file += 32; // turning into lowercase (32 because is 'a'-'A')
  if (file < 'a' || file > 'h') return NULL;  // valid check
  rank -= '0';                                // turning the numeric char in its respective int
  if (rank < 1 || rank > EIGHT) return NULL;  // valid check

  return &board[EIGHT-rank][file-'a'];
}

void ClearScreen()
{
  system("cls");
}

/*

    A   B   C   D   E   F   G   H           // "LETTERS_ROW"
  |-------------------------------|         // "LINE_ROW"
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

  Turn: WHITE                               // soon
  Type your move:                           // soon
*/