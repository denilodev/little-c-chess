#include "input.h"

char input[BUFFER_SIZE];

void GetInput()
{
    ClearInputBuffer();
    printf("Turn: %s", isWhiteTurn ? "WHITE" : "black");
    bool isInputInvalid = true;
    do
    {
        printf("\nMake your move: ");
        fgets(input, BUFFER_SIZE, stdin);
        if ((input[0] >= 'a' && input[0] <= 'h') && (input[2] >= 'a' && input[2] <= 'h') &&
            (input[1] >= '1' && input[1] <= '8') && (input[3] >= '1' && input[3] <= '8'))
            isInputInvalid = false;
    } while (isInputInvalid);
}

void GameOverInput()
{

}

void ClearInputBuffer()
{
    snprintf(input, BUFFER_SIZE, "----");
}