#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "board.h"
#include "input.h"

#ifndef TILE
#define TILE            char*
#endif
#define WHITE_PLAYER    'W'
#define BLACK_PLAYER    'b'

extern bool isRunning;
extern bool isWhiteTurn;
extern bool isGameOver;
extern char lastCapturedPiece;
extern char winner;
extern TILE whiteCanEnPassantHere;
extern TILE blackCanEnPassantHere;

void ResetBoard();
void StartGame();
void MakeMove();
void CheckGameConditions();
void MovePiece(TILE, TILE);
void ChangeTurn();
bool CheckMoveLegality();

#endif