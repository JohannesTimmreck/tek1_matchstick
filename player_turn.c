/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** player turn
*/

#include "matchstick.h"
#include <stdio.h>

int read_match_input(input_t *input, int max_matches, int amount_matches)
{
    char *str = NULL;
    size_t len = 0;

    input->line_check = 1;
    write(1, "Matches: ", 9);
    if (getline(&str, &len, stdin) == -1)
        return (-1);
    str[my_strlen(str) - 1] = '\0';
    if (str != NULL && my_strcmp(str, "\0") == 1 &&
        check_for_number(str) != 1) {
        input->matches = my_getnbr(str);
        free(str);
        input->match_check = check_matches(max_matches, amount_matches,
        input->matches);
    } else {
        write(1, "Error: invalid input (positive number expected)\n", 48);
    }
    return (0);
}

int match_input(input_t *input, char **board,
    int max_matches, int amount_matches)
{
    if (input->line_check == 0) {
        amount_matches = get_amount_matches(board[input->line]);
        if (read_match_input(input, max_matches, amount_matches) == -1)
            return (-1);
    }
}

void intermezzo(input_t *input, char **str, int max_line)
{
    if (*str != NULL && my_strcmp(*str, "\0") == 1 &&
        check_for_number(*str) != 1) {
        input->line = my_getnbr(*str);
        free(*str);
        input->line_check = check_line(max_line, input->line);
    } else {
        write(1, "Error: invalid input (positive number expected)\n", 48);
    }
}

int read_line_input(input_t *input, char **board, int max_line, int max_matches)
{
    int amount_matches;
    char *str = NULL;
    size_t len = 0;

    while (input->match_check != 0) {
        write(1, "Line: ", 6);
        if (getline(&str, &len, stdin) == -1)
            return (-1);
        str[my_strlen(str) - 1] = '\0';
        intermezzo(input, &str, max_line);
        if (match_input(input, board, max_matches, amount_matches) == -1)
            return (-1);
    }
    my_printf("Player removed %d match(es) from line %d\n", input->matches,
        input->line);
    return (0);
}

int player_turn(input_t *input, char **board, int size, int max_matches)
{
        input->match_check = 1;
        input->line_check = 1;
        my_printf("\nYour turn:\n");
        if (read_line_input(input, board, size, max_matches) == -1)
            return (-1);
        update_board(board, input->line, input->matches);
        print_board(board);
}