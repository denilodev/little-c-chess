#ifndef INPUT_H
#define INPUT_H

#include "game.h"

#define BUFFER_SIZE 5
extern char input[BUFFER_SIZE];

void GetInput();
void GameOverInput();
void ClearInputBuffer();

#endif