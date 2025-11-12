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
  DrawBoard();
  printf("Winner is %s Player!", winner==WHITE_PLAYER?"White":"Black");
}

TILE GetTileAddress(char file, char rank)
{
  if (IsCharUpper(file)) file += ('a'-'A');   // turning into lowercase
  if (file < 'a' || file > 'h') return NULL;  // valid check
  rank -= '0';                                // turning the numeric char in its respective int
  if (rank < 1 || rank > EIGHT) return NULL;  // valid check

  return &board[EIGHT-rank][file-'a'];
}

void ClearScreen()
{
  system("cls");
}