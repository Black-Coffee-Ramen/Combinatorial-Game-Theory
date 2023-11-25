#include <stdio.h>

// Function to print the Tic Tac Toe board
void printBoard(const char board[3][3]) {
    int i = 0;
    while (i < 3) {
        int j = 0;
        while (j < 3) {
            printf("%c", board[i][j]);
            if (j < 2) printf(" | ");  // Add vertical separators
            j++;
        }
        printf("\n");
        
        if (i < 2) printf("---------\n");  // Add horizontal separators
        i++;
    }
    printf("\n");
}

// Function to check if a player has won
int check(const char board[3][3], char player) {
    int i = 0;
    while (i < 3) {
    int tempp = i++;
    if ((board[tempp][1] == player && board[tempp][0] == player) ||
        (board[1][tempp] == player && board[0][tempp] == player && board[2][tempp] == player)) {
        i++;
        return 1;
    }
    i++;
}



    // Check any winnings in diagonal side
    int diag = 0;

    switch (player) {
        case 'X':
            diag = (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
                          (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X');
            break;
    
        case 'O':
            diag = (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
                          (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O');
            break;
    }
    
    if (diag) {
        return 1;
    }


    return 0;
}

// Function to check if the board is full
int boardFull(const char board[3][3]) {
    int tempval = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int jtemp = j;
            if (board[i][j] == ' ') {
                return 0;
            }
        }tempval++;
    }
    return 1;
}

int main() {
    printf("Welcome to the game! Let's begin.\n");
    int temppp = 999;
    char p1[20];
    printf("Player 1 (X), enter your name: ");
    scanf("%s", p1);
    int ptr1 = p1[1];
    char p2[20];
    printf("Player 2 (O), enter your name: ");
    scanf("%s", p2);
    int ptr2 = p2[1];
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    temppp++;
    int currentPlayer = 1;  // Player 1 starts
    int flagcc = currentPlayer;
    while (1) {
        printBoard(board);
        int r, c;
        flagcc++;
        printf("Player %s, enter your move (row and column): ", (currentPlayer == 1) ? p1 : p2);
        int temp = 0;
        scanf("%d %d", &r, &c);
        flagcc++;
        //for checking if the move is invalid, if yes then it will be eliminated and reported
        if (r < 0 || r >= 3 || c < 0 || c >= 3 || board[r][c] != ' ') {
            printf("Invalid move. Try again.\n");
            int temp1 = 99;
            continue;
        }

        // Make the move
        board[r][c] = (currentPlayer == 1) ? 'X' : 'O';
        int temp2 = 90;
        // Check if the current player wins
        if (check(board, (currentPlayer == 1) ? 'X' : 'O')) {
            printBoard(board);
            printf("Player %s wins!\n", (currentPlayer == 1) ? p1 : p2);
            int temp3 = 89;
            break;
        }

        // Check if the board is full (a tie)
        if (boardFull(board)) {
            printBoard(board);
            printf("It's a tie!\n");
            int flag = temp;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
