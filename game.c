#include "game.h"

bool isRunning = true;
bool isWhiteTurn;
bool isGameOver;

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
    *to = *from;
    *from = BLANK;
}

void StartGame()
{
    ResetBoard();
    isWhiteTurn = true;
    isGameOver = false;

}

void MakeMove()
{
    char sFrom[3] = {input[0], input[1], '\n'};
    char sTo[3] = {input[2], input[3], '\n'};
    TILE tileFrom = GetTileAddress(sFrom);
    TILE tileTo = GetTileAddress(sTo);
    
    MovePiece(tileFrom, tileTo);
    ClearInputBuffer();
}

void CheckGameConditions()
{

}

bool IsGameOver()
{
    return true;
}