/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** board
*/

#include "matchstick.h"

char get_start_character(int line_nb, int column, int size)
{
    if (column <= (size - line_nb) || column >= (size + line_nb)) {
        return (' ');
    } else {
        return ('|');
    }
}

char *create_line_for_board(int line_nb, int length, int max_lines)
{
    char *line = malloc(sizeof(char) * (length + 2));

    line[length + 1] = '\0';
    if (line_nb == 0 || line_nb == max_lines) {
        for (int i = 0; i <= length  ; i++)
            line[i] = '*';
    } else {
        line[0] = '*';
        for (int i = 1; i < length; i++)
            line[i] = get_start_character(line_nb, i, (max_lines - 1));
        line[length] = '*';
    }
    line[length + 1] = '\0';
    return (line);
}

char **create_game_board(int lines)
{
    char **board = malloc(sizeof(char *) * (lines + 3));

    for (int i = 0; i < lines + 2; i++) {
        board[i] = create_line_for_board(i, (2 * lines), lines + 1);
    }
    board[lines + 2] = NULL;
    return (board);
}

void update_board(char **board, int line, int rem_matchs)
{
    int last_match = get_last_match(board[line]);

    for (; rem_matchs > 0; rem_matchs--) {
        board[line][last_match] = ' ';
        last_match--;
    }
}

void print_board(char **board)
{
    for (int i = 0; board[i] != NULL; i++) {
        write(1, board[i], my_strlen(board[i]));
        write(1, "\n", 1);
    }
}