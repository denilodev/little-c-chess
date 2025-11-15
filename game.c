#include "game.h"

bool isRunning = true;
bool isWhiteTurn;
bool isGameOver;
char lastCapturedPiece;
char winner;
TILE whiteCanEnPassantHere;
TILE blackCanEnPassantHere;

void ResetBoard()
{
    for(int x = 0; x < EIGHT; x++)
    {
        for(int y = 0; y < EIGHT; y++)
        {               // the idea here is to populate the tiles based on each
            switch (x)  // character of the "-ROW" strings
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

bool CheckMoveLegality()
{
    int fileFrom = IsCharUpper(input[0]) ? input[0] + ('a'-'A') : input[0]; // letter
    int rankFrom = input[1];    // number
    int fileTo   = IsCharUpper(input[2]) ? input[2] + ('a'-'A') : input[2]; // letter
    int rankTo   = input[3];    // number
    bool isDoubleMovement = false;                              // for first pawn move
    switch (*tileFrom)
    {
    case 'p':
        if (rankFrom == '7' && rankTo == '5')
        {
            if (*GetTileAddress(fileTo, rankTo+1) != BLANK) return false;   // can't jump, darling
            isDoubleMovement = true;
        }
        else if ((rankFrom - 1) != rankTo) return false;        // just one step bro

        if ((fileFrom != fileTo))                               // check file
        {
            if (fileFrom > fileTo)
            {
                if((fileFrom - 1) != fileTo) return false;      // too much to the left
            }
            else
            {
                if((fileTo - 1) != fileFrom) return false;      // too much to the right
            }
            if (*tileTo == BLANK)
            {
                if (tileTo == blackCanEnPassantHere)
                {
                    TILE deadPawn = GetTileAddress(input[2], input[3]+1);
                    *tileTo = *deadPawn;
                    *deadPawn = BLANK;
                }
                else return false;                              // can't capture the nothingness
            }
        }
        else if (*tileTo != BLANK) return false;                // can't capture forward
        // PAWN PROMOTION
        if (rankTo == '1')
        {
            char promotionPiece = BLANK;
            bool canPromote = false;
            errorInputMessage = none;
            do
            {
                if(errorInputMessage != none)
                    printf("%s", errorInputMessage);
                else printf("Which piece will your pawn promote to? (q, r, b, n): ");
                promotionPiece = getchar();
                if (promotionPiece == '\n') promotionPiece = getchar();

                if (IsCharUpper(promotionPiece)) promotionPiece += ('a'-'A');   // turning into lowercase
                switch (promotionPiece)
                {
                case 'q':
                    *tileFrom = 'q';
                    canPromote = true;
                    break;
                case 'r':
                    *tileFrom = 'r';
                    canPromote = true;
                    break;
                case 'b':
                    *tileFrom = 'b';
                    canPromote = true;
                    break;
                case 'n':
                    *tileFrom = 'n';
                    canPromote = true;
                    break;
                default:
                    break;
                }
            } while (!canPromote);
        }

        if (isDoubleMovement)   whiteCanEnPassantHere = GetTileAddress(input[2], input[3]+1);
        else                    whiteCanEnPassantHere = NULL;
        return true;
    case 'P':
        if (rankFrom == '2' && rankTo == '4')
        {
            if (*GetTileAddress(fileTo, rankTo-1) != BLANK) return false;
            isDoubleMovement = true;
        }
        else if ((rankFrom + 1) != rankTo) return false;

        if (fileFrom != fileTo)                                 // check file
        {
            if (fileFrom > fileTo)
            {
                if((fileFrom - 1) != fileTo) return false;      // too much to the left
            }
            else
            {
                if((fileTo - 1) != fileFrom) return false;      // too much to the right
            }
            if (*tileTo == BLANK)
            {
                if (tileTo == whiteCanEnPassantHere)
                {
                    TILE deadPawn = GetTileAddress(input[2], input[3]-1);
                    *tileTo = *deadPawn;
                    *deadPawn = BLANK;
                }
                else return false;                              // can't capture the nothingness
            }
        }
        else if (*tileTo != BLANK) return false;                // can't capture forward
        // PAWN PROMOTION
        if (rankTo == '8')
        {
            char promotionPiece = BLANK;
            bool canPromote = false;
            errorInputMessage = none;
            do
            {
                if(errorInputMessage != none)
                    printf("%s", errorInputMessage);
                else printf("Which piece will your pawn promote to? (q, r, b, n): ");
                promotionPiece = getchar();
                if (promotionPiece == '\n') promotionPiece = getchar();

                if (IsCharUpper(promotionPiece)) promotionPiece += ('a'-'A');   // turning into lowercase
                switch (promotionPiece)
                {
                case 'q':
                    *tileFrom = 'Q';
                    canPromote = true;
                    break;
                case 'r':
                    *tileFrom = 'R';
                    canPromote = true;
                    break;
                case 'b':
                    *tileFrom = 'B';
                    canPromote = true;
                    break;
                case 'n':
                    *tileFrom = 'N';
                    canPromote = true;
                    break;
                default:
                    break;
                }
            } while (!canPromote);
        }

        if (isDoubleMovement)   blackCanEnPassantHere = GetTileAddress(input[2], input[3]-1);
        else                    blackCanEnPassantHere = NULL;
        return true;
    case 'r':
    case 'R':
        if (fileFrom != fileTo)
        {
            if (rankFrom != rankTo) return false;       // no diagonal movement
            if (fileFrom > fileTo)
            {
                for (int i = 1; i <= (fileFrom - fileTo - 1); i++)      // check each tile in the way
                {
                    if (*GetTileAddress(fileFrom-i, rankTo) != BLANK) return false;
                }
            }
            else    // fileTo > fileFrom
            {
                for (int i = 1; i <= (fileTo - fileFrom - 1); i++)      // check each tile in the way
                {
                    if (*GetTileAddress(fileTo-i, rankTo) != BLANK) return false;
                }
            }
        }
        else    // rankFrom != rankTo
        {
            if (rankFrom > rankTo)
            {
                for (int i = 1; i <= (rankFrom - rankTo - 1); i++)      // check each tile in the way
                {
                    if (*GetTileAddress(fileTo, rankFrom-i) != BLANK) return false;
                }
            }
            else    // rankTo > rankFrom
            {
                for (int i = 1; i <= (rankTo - rankFrom - 1); i++)      // check each tile in the way
                {
                    if (*GetTileAddress(fileTo, rankTo-i) != BLANK) return false;
                }
            }
        }
        return true;
    case 'n':
    case 'N':
        // easier to just pick the few legal moves and return false if isn't any of those
        if (rankFrom+2 == rankTo)
        {
            if ((fileFrom+1 == fileTo) || (fileFrom-1 == fileTo))
            {
                return true;
            }
        }
        else if (rankFrom+1 == rankTo)
        {
            if ((fileFrom+2 == fileTo) || (fileFrom-2 == fileTo))
            {
                return true;
            }
        }
        else if (rankFrom-1 == rankTo)
        {
            if ((fileFrom+2 == fileTo) || (fileFrom-2 == fileTo))
            {
                return true;
            }
        }
        else if (rankFrom-2 == rankTo)
        {
            if ((fileFrom+1 == fileTo) || (fileFrom-1 == fileTo))
            {
                return true;
            }
        }
        return false;
    case 'b':
    case 'B':
        int tileCount;
        if (rankTo > rankFrom) // up
        {
            tileCount = rankTo - rankFrom;
            if      ((fileTo > fileFrom) && (tileCount == fileTo - fileFrom))
            {
                // up-right
                for (int i = 1; i <= tileCount-1; i++)
                {
                    if (*GetTileAddress(fileTo-i, rankTo-i) != BLANK) return false;
                }
                
            }
            else if ((fileTo < fileFrom) && (tileCount == fileFrom - fileTo))
            {
                // up-left
                for (int i = 1; i <= tileCount-1; i++)
                {
                    if (*GetTileAddress(fileTo+i, rankTo-i) != BLANK) return false;
                }
            }
            else
            {
                return false;
            }
        }
        else    // down
        {
            tileCount = rankFrom - rankTo;
            if      ((fileTo > fileFrom) && (tileCount == fileTo - fileFrom))
            {
                // down-right
                for (int i = 1; i <= tileCount-1; i++)
                {
                    if (*GetTileAddress(fileTo-i, rankTo+i) != BLANK) return false;
                }
            }
            else if ((fileTo < fileFrom) && (tileCount == fileFrom - fileTo))
            {
                // down-left
                for (int i = 1; i <= tileCount-1; i++)
                {
                    if (*GetTileAddress(fileTo+i, rankTo+i) != BLANK) return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    case 'q':
    case 'Q':
        // Check if is a legal queen move
        return true;
    case 'k':
    case 'K':
        // Check if is a legal king move
        return true;
    default:
        return false;
    }
}