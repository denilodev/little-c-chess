#include "game.h"

bool isRunning = true;
bool isWhiteTurn;
bool isGameOver;
char lastCapturedPiece;
char winner;

void ResetBoard()
{
    for(int x = 0; x < EIGHT; x++)
    {
        for(int y = 0; y < EIGHT; y++)
        {               // the idea here is to populate the tiles based on each
            switch (x)  // character of the "...ROW" strings (those four above) 
            {
            case 0:         // tiles of first row
                board[x][y] = BLACK_BACK_ROW[y];
                break;
            case 1:         // tiles of second row
                board[x][y] = BLACK_FRONT_ROW[y];
                break;
            case EIGHT-2:   // tiles of second to last row
                board[x][y] = WHITE_FRONT_ROW[y];
                break;
            case EIGHT-1:   // tiles of last row
                board[x][y] = WHITE_BACK_ROW[y];
                break;
            default:        // empty tile
                board[x][y] = BLANK;
                break;
            }
        }
    }
}

void MovePiece(TILE from, TILE to)
{
    if (*to != BLANK) lastCapturedPiece = *to;
    *to = *from;
    *from = BLANK;
}

void StartGame()
{
    ResetBoard();
    isWhiteTurn = true;
    isGameOver = false;
    lastCapturedPiece = BLANK;
    winner = BLANK;

}

void MakeMove()
{    
    MovePiece(tileFrom, tileTo);
    ChangeTurn();
}

void CheckGameConditions()
{
    if (lastCapturedPiece == 'K')
    {
        winner = BLACK_PLAYER;
        isGameOver = true;
    }
    else if (lastCapturedPiece == 'k')
    {
        winner = WHITE_PLAYER;
        isGameOver = true;
    }
}

void ChangeTurn()
{
    isWhiteTurn = !isWhiteTurn;
}