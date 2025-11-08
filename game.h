#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "board.h"
#include "input.h"

#ifndef TILE
#define TILE            char*
#endif

extern bool isRunning;
extern bool isWhiteTurn;
extern bool isGameOver;

void ResetBoard();
void StartGame();
void MakeMove();
void CheckGameConditions();
void MovePiece(TILE, TILE);

#endif