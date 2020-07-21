/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** main
*/

#include "matchstick.h"

int end_game(char **board)
{
    int amount_matches = 0;

    for (int i = 0; board[i] != NULL; i++)
        amount_matches += get_amount_matches(board[i]);
    if (amount_matches == 0) {
        return (1);
    } else {
        return (0);
    }
}

void free_board(char **board)
{
    int end = 0;

    for (int i = 0; board[i] != NULL; i++) {
        free(board[i]);
        end++;
    }
    free(board[end]);
    free(board);
}

int game_loop(int size, int max_matches)
{
    char **board = create_game_board(size);
    input_t *input = malloc(sizeof(input_t));
    int end = -1;

    print_board(board);
    while (end == -1) {
        if (player_turn(input, board, size, max_matches) == -1)
            return (0);
        if (end_game(board) == 1)
            end = 2;
        if (end != 2)
            ai_turn(board, size, max_matches);
        if (end_game(board) == 1 && end != 2)
            end = 1;
    }
    free(input);
    free_board(board);
    return (end);
}

int main(int argc, char const *argv[])
{
    int size;
    int max_matches;
    int end;

    srandom(time(0));
    if (input_errors(argc, argv) != 0) {
        write(2, "Please enter board size between 2 and 99 ", 41);
        write(2, "and an amount of matches to be maximal taken\n", 45);
        return (84);
    }
    size = my_getnbr(argv[1]);
    max_matches = my_getnbr(argv[2]);
    end = game_loop(size, max_matches);
    if (end == 2)
        write(1, "You lost, too bad...\n", 21);
    if (end == 1)
        write(1,  "I lost... snif... but I'll get you next time!!\n", 47);
    return (end);
}
