#include <stdio.h>
#include <stdint.h>
#include "board.h"
#include "game.h"
#include "input.h"

void Debug()
{
    TILE fromThis = GetTileAddress('e','2');
    TILE toThis = GetTileAddress('e','4');
    MovePiece(fromThis, toThis);
    DrawBoard();
}

int main()
{
    StartGame();
    
    while(isRunning)
    {
        DrawBoard();
        GetInput();
        MakeMove();
        CheckGameConditions();
        if (isGameOver)
        {
            DrawGameOver();
            GameOverInput();
        }
        //Debug();
    }
    return 0;
}