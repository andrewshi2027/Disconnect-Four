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
scanf(" %c", &choice); //this command will erase whitespace in the token selection
*/


int main() {

    char piece;
    int row, column;

    //Print Board
    for (int i = 0; i < 5; i++) {
        printf("\n");
        for (int j = 0; j < 5; j++) 
        {
            printf("%c ", board[i][j]);
        }
    }
    printf("\n");


    //User Input for Piece
    while (1) {
        printf("Choose a piece (x or o) or q to quit: ");
        scanf("%c", &piece);
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

    //If invalid input
    return 0;
}

