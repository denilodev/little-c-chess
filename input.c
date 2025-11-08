#include "input.h"

char input[INPUT_SIZE];
static char *none = "";
char *errorInputMessage;
TILE tileFrom;
TILE tileTo;

void GetInput()
{
    ClearString(input, INPUT_SIZE);
    errorInputMessage = none;

    printf("Turn: %s\n", isWhiteTurn ? "WHITE" : "black");
    printf("Last captured piece: '%c'\n", lastCapturedPiece);
    printf("Make your move: ");

    do
    {
        if(errorInputMessage != none)
            printf("%s", errorInputMessage);
        ClearString(input, INPUT_SIZE);
        fgets(input, INPUT_SIZE, stdin);
        if (input[0] == '\n') fgets(input, INPUT_SIZE, stdin);

        ValidateInput();
    } while (errorInputMessage != none);
}

void GameOverInput()
{
    getchar();
    isRunning = false;
}

void ClearString(char *string, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        string[i] = BLANK;
    }

    string[size-1] = '\0';
    
}

void ValidateInput()
{       // check if first char is a letter       // check if second char is a number
    if ((input[0] < 'a' || input[0] > 'h') || (input[1] < '1' || input[1] > '8') ||
        (input[2] < 'a' || input[2] > 'h') || (input[3] < '1' || input[3] > '8'))
    {
        errorInputMessage = "Invalid Input. Try again: ";
        return;
    }
    tileFrom = GetTileAddress(input[0], input[1]);
    if (*tileFrom == BLANK)
    {
        errorInputMessage = "No piece in this file. Try again: ";
        return;
    }
    if ((IsCharUpper(*tileFrom) && !isWhiteTurn) || (!IsCharUpper(*tileFrom) && isWhiteTurn))
    {
        errorInputMessage = "This is not your piece. Try again: ";
        return;
    }
    tileTo = GetTileAddress(input[2], input[3]);
    if ((IsCharUpper(*tileTo) && isWhiteTurn) || (!IsCharUpper(*tileTo) && !isWhiteTurn))
    {
        errorInputMessage = "Can't capture your own pieces. Try again: ";
        return;
    }
    errorInputMessage = none;
}

bool IsCharUpper(char c)
{
    if (c >= 'A' && c <= 'Z') return true;
    else return false;
}