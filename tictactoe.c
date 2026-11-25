#include <stdio.h>

char board[3][3];

void initialize_board(void)
{
    int row, column;

    for (row = 0; row < 3; row++) {
        for (column = 0; column < 3; column++) {
            board[row][column] = '1' + (row * 3 + column);
        }
    }
}

void display_board(void)
{
    int row;

    printf("\n");
    for (row = 0; row < 3; row++) {
        printf(" %c | %c | %c \n", board[row][0], board[row][1], board[row][2]);
        if (row < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

char check_winner(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}

int is_board_full(void)
{
    int row, column;

    for (row = 0; row < 3; row++) {
        for (column = 0; column < 3; column++) {
            if (board[row][column] >= '1' && board[row][column] <= '9') {
                return 0;
            }
        }
    }

    return 1;
}

int main(void)
{
    char current_player = 'X';
    int move, row, column;
    char winner;

    initialize_board();

    while (1) {
        display_board();
        printf("Player %c, enter position (1-9): ", current_player);

        if (scanf("%d", &move) != 1) {
            printf("Please enter a number.\n");
            while (getchar() != '\n') {
            }
            continue;
        }

        if (move < 1 || move > 9) {
            printf("Invalid position. Choose 1 to 9.\n");
            continue;
        }

        row = (move - 1) / 3;
        column = (move - 1) % 3;

        if (board[row][column] == 'X' || board[row][column] == 'O') {
            printf("That position is already taken.\n");
            continue;
        }

        board[row][column] = current_player;

        winner = check_winner();
        if (winner == 'X' || winner == 'O') {
            display_board();
            printf("Player %c wins!\n", winner);
            break;
        }

        if (is_board_full()) {
            display_board();
            printf("It's a draw!\n");
            break;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    return 0;
}