#include <stdio.h>

void playerName();
void printBoard();
void playerMove();
void computerMove();
int checkFreeSpaces();

char checkWinner();
void printWinner(char);
void resetBoard();

//2D array of characters
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

int main()
{
    char winner = ' ';
    resetBoard();
    playerName();
    
    //no winner and available spaces
    while(winner == ' ' && checkFreeSpaces() != 0) 
    {
        printBoard();
        playerMove();
        
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }
    printBoard();
    printWinner(winner);
    
    return 0;
}

void playerName()
{
    char name[20];
    printf(" ************************************ \n");
    printf(" Tic Tac Toe \n COMP 2131 -Summer 2023 \n You will be playing against the computer \n");
    printf(" ************************************ \n");
    printf("\n What is your name? \n");
    scanf("%s", name );
    printf(" Hello %s ... Let's have fun !!! You = X | Computer = O \n", name);
    
    return 0;
}

void resetBoard()
{
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            //set each element in array to empty 
            board[i][j] = ' ';
        }
    }
}

void printBoard() 
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces() {
    //check if each spot on board is empty
    int freeSpaces = 9;
    
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove()
{
    int x;
    int y;
    
    do
    {
        printf("Enter X,Y coordinates for your move: ");
        scanf("%d, %d", &x, &y);
        //since arrays index from 0 to 2
        x = x-1;
        y = y-1;
    
        if(board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }  
    } while (board[x][y] != ' ');
}

void computerMove()
{
    srand(time(0));
    int x;
    int y;
    
    if(checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}

char checkWinner()
{
    //check rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //check columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    //check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    //currently no winner
    return ' ';
}

void printWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf(" You have won! ");
    }
    else if(winner == COMPUTER)
    {
        printf(" You have lost! ");
    }
    else
    {
        printf(" It's a draw! ");
    }
}
