#include <stdio.h> //preprocessor directive

//Constants
#define ROWS 5
#define COLS 5

char board[ROWS][COLS] = {
    {'x', 'x', 'x', '-', 'o'}, 
    {'o', 'x', 'x', 'o', 'o'}, 
    {'o', 'x', '-', 'x', 'x'}, 
    {'o', '-', 'x', 'x', '-'}, 
    {'x', 'o', 'x', 'o', 'o'}};

/* Hint:
scanf(" %c", &choice); //this command will erase whitespace in the token selection, solves the double error
*/

//FUNCTIONS
//Checks if board is a winning board
int win(char arr[ROWS][COLS]) {
    int condition = 0; //win
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == '-') {
                condition = 1; //not win
                break;
            }
        }
    }
    return condition;
}

//Checks if invalid piece choice
int valid(char arr[ROWS][COLS], int row, int column) {
    int output = 0; //valid
    if (arr[row][column] != '-') { //arr[row][column] == 'o' || arr[row][column] == 'x'
        output = -1; //invalid
    }

    return output;
}




int main() {
    char piece;
    int row, column;

    while (1) {
        //Print Board
        for (int i = 0; i < 5; i++) {
            printf("\n");
            for (int j = 0; j < 5; j++) 
            {
                printf("%c", board[i][j]);
                if (j < COLS - 1) {
                    printf(" ");
                }
            }
        }
        printf("\n");

        //User Input for Piece
        while (1) {
            printf("Choose a piece (x or o) or q to quit: ");
            scanf(" %c", &piece); //need space before %c
            if (piece == 'x' || piece == 'o' || piece == 'q') {
                break;
            }
            else {
                printf("Invalid choice. ");
            }
        }
        // If user chose "q" (quit)
        if (piece == 'q') {
            printf("Quitting the game.");
            return 0;
        }
        //User Input for Row
        while (1) {
            printf("Choose a row (0-4): ");
            scanf("%d", &row);
            if (row >= 0 && row < ROWS) {
                break;
            }
            else {
                printf("Invalid choice. ");
            }
        }
        //User Input for Column
        while (1) {
            printf("Choose a column (0-4): ");
            scanf("%d", &column);

            if (column >= 0 && column < COLS) {
                break;
            }
            else {
                printf("Invalid choice. ");
            }
        }
        break;

        //If Cell is Occupied
        if (valid(board, row, column) == -1) {
            printf("Invalid choice. That space is already occupied.\n");
        }
        else {
           board[row][column] = piece;
           break; 
        }

        if (win(board) == 0) {
        //Victory
        printf("Congratulations, you have filled the board!");
        //Print Winning Board
        for (int i = 0; i < 5; i++) {
            printf("\n");
            for (int j = 0; j < 5; j++) 
            {
                printf("%c", board[i][j]);
                if (j < COLS - 1) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    }

    


    
    
    //If invalid input
    return 0;
}



