#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "board.h"

int main()
{
    ResetBoard();

    bool isRunning = true;
    while(isRunning)
    {
        DrawBoard();
        // wait for input
        // check if input is valid
            // if not, say it and ask again
        // check if move is valid
            // if not, say it and ask again
        // make the move
        // if check mate
            //print endgame
            //ask if want to replay or close the game
            //if close
            //
            isRunning = false;
    }
    return 0;
}