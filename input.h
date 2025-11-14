#ifndef INPUT_H
#define INPUT_H

#include "game.h"

#define INPUT_SIZE      5
#define ERROR_MSG_SIZE  255
extern char input[INPUT_SIZE];
extern char *none;
extern char *errorInputMessage;
extern char *tileFrom;
extern char *tileTo;

void GetInput();
void GameOverInput();
void ClearString();
void ValidateInput();
bool IsCharUpper(char);

#endif