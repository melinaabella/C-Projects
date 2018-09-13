//Melina Abell || C program for tictactoe

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 3
#define FALSE 0
#define TRUE 1
//display function prototypes
void display_table(char board[SIZE][SIZE]);
void clear_table(char board[SIZE][SIZE]);
bool check_table_full(char board[SIZE][SIZE]);
void update_table(char board[SIZE][SIZE], int row, int col, char player1tok);
bool check_legal_option(char board[SIZE][SIZE], int row, int col);
void generate_player2_move(char board[SIZE][SIZE],int row,int col);
char check_three_in_a_row(char board[SIZE][SIZE]);
bool check_end_of_game (char board[SIZE][SIZE]);
void get_player1_move(char board[SIZE][SIZE], int row, int col);
void print_winner(char board[SIZE][SIZE]);

int main ()
{
    //Declare the tic-tac-toe board
    char board[SIZE][SIZE];
    //The row and column of the move for either player 1 or 2
    int row, col;
    //Clear the table
    clear_table(board);
    //Display the table
    display_table(board);
    do
    {
        //Have player 1 enter their move
        get_player1_move(board, row, col);
        //Generate player 2 move
        generate_player2_move(board, row, col);
        //Do this while the game hasn't ended
    }while(check_end_of_game(board) == false);
    //After the game is over, print who won
    print_winner(board);
    return 0;
}

void display_table(char board[SIZE][SIZE])
{
    printf("The current state of the game is: \n");
    printf("%c %c %c\n", board[0][0], board[0][1], board[0][2]);
    printf("%c %c %c\n", board[1][0], board[1][1], board[1][2]);
    printf("%c %c %c\n", board[2][0], board[2][1], board[2][2]);
    
    
    return;
    
}

void clear_table(char board[SIZE][SIZE])
{
    // clear the board by making every box empty
    // nested for loop
    int r, c;
    for (r = 0; r < SIZE; r++)
    {
        for (c = 0; c < SIZE; c++) {
            board[r][c] = '_';
        }
    }
}

bool check_table_full(char board[SIZE][SIZE])
{
    int r, c;
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            if (board[r][c] == '_'){
                return (false); }
        }
    }
    return true;
}

void update_table(char board[SIZE][SIZE], int row, int col, char player1tok)
{
    
    board[row][col]= player1tok;
    
}

bool check_legal_option(char board[SIZE][SIZE], int row, int col)
// check if move is legal or not
// if the player1 enters invalid selection, i have to make them retry
{
    if (board[row][col] == '_' && row < 3 && col < 3)
    {
        return true;
    }
    else {
        return false;
    }
}

void generate_player2_move(char board[SIZE][SIZE],int row,int col)
{
    char player1tok = 'X';
    int r, c;
    time_t t;
    srand(time(&t));
    while(check_end_of_game(board)==false)
    {//generate the random numbers
        r = rand()%3;
        c = rand()%3;
        //later we will add loop when we finish check end of game function
        
        //make sure random numbers are valid, use call of check_legal_function
        
        if ( check_legal_option(board, r, c) == 1){
            printf("\nPlayer 2 has  entered [row. col]: %d,%d\n", r, c);
            update_table(board, r, c, player1tok);
            display_table(board);
            
            break;
            
        }
        //if check legal function is true, then we update and display the table using
        //respective function calls
    }
}

// returns to original player that has three in a row or ZERO if no one has three in a row
char check_three_in_a_row(char board[SIZE][SIZE])
{
    //else if, return 1, return 0 alternates
    if (board[0][0] == 'O' && board[0][1] == 'O' &&
        board[0][2] == 'O')
    {return 1;}
    
    
    
    else if (board[0][0] == 'O' && board[1][0] == 'O' &&
             board[2][0] == 'O')
    {return 1;}
    
    
    
    else if (board[1][0] == 'O' &&
             board[1][1] == 'O' && board[1][2] == 'O')
    {return 1;}
    
    else if (board[0][1] == 'O' &&
             board[1][1] == 'O' && board[2][1] == 'O')
    {return 1;}
    
    
    
    else if (board[2][0] == 'O' &&
             board[2][1] == 'O' && board[2][2] == 'O')
    {return 1;}
    
    
    
    else if (board[0][2] == 'O' &&
             board[1][2] == 'O' && board[2][2] == 'O')
    {return 1;}

    else if (board[0][2] == 'O' &&
             board[1][2] == 'O' && board[2][2] == 'O')
    {return 1;}
    
    
    if (board[0][0] == 'X' && board[0][1] == 'X' &&
        board[0][2] == 'X')
    {return 2;}
    
    
    
    else if (board[0][0] == 'X' && board[1][0] == 'X' &&
             board[2][0] == 'X')
    {return 2;}
    
    
    
    else if (board[1][0] == 'X' &&
             board[1][1] == 'X' && board[1][2] == 'X')
    {return 2;}

    else if (board[0][1] == 'X' &&
             board[1][1] == 'X' && board[2][1] == 'X')
    {return 2;}
    
    
    
    else if (board[2][0] == 'X' &&
             board[2][1] == 'X' && board[2][2] == 'X')
        
    {return 2;}
    
    
    else if (board[0][2] == 'X' &&
             board[1][2] == 'X' && board[2][2] == 'X')
    {return 2;}
    
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
    {return 1;}
    
    else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
    {return 1;}
    
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
    {return 2;}
    
    else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
    {return 2;}

    else
    {
        return 0;
    }
    // diagonal
}
// true or false if game is over or NOT

bool check_end_of_game (char board[SIZE][SIZE])
{
    // check if there's 3 in a row or if table is full
    if( check_three_in_a_row(board) != 0 || check_table_full(board) == 1)
    {
        return 1;
    }
    else {
        return 0;
    }
}
void get_player1_move(char board[SIZE][SIZE], int row, int col)
// decrement row col;
{
    while (check_end_of_game(board)==false)
    {
        int r, c;
        char player1tok = 'O';
        
        printf("\nPlayer 1 enter your selection [row, col]: ");
        scanf("%d,%d", &r, &c);
        
        r--;
        c--;
        if  (check_legal_option(board, r, c)==true)
        {update_table(board, r, c, player1tok);
            display_table(board);
            break;
            
        }
    }
    
}
// function to declare the WINNERR!
void print_winner(char board[SIZE][SIZE])
{
    if (check_three_in_a_row(board) == 1)
    {printf("\nCongratulations, Player 1 wins!\n\n"); }
    
    else if (check_table_full(board) == 1)
    { printf("\nDRAW!!\n"); }
    
    else if (check_three_in_a_row(board) == 2)
    {
        printf("\nCongratulations, you're an idiot!\n\n");
    }
    
    
}

















