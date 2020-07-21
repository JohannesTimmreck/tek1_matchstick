/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** ai functions
*/

#include "matchstick.h"

int choose_ai_line(char **board, int max_lines)
{
    int check = 1;
    int line;

    while (check == 1) {
        line = 1 + random() % max_lines;
        if (get_amount_matches(board[line]) > 0)
            check = 0;
    }
    return (line);
}

int choose_ai_matches(char **board, int line, int max_matches)
{
    int matches;
    int amount_matches = get_amount_matches(board[line]);

    if (amount_matches < max_matches) {
        matches = (random() % amount_matches) + 1;
    } else {
        matches = (random() % max_matches) + 1;
    }
    return (matches);
}

void ai_turn(char **board, int max_lines, int max_matches)
{
    int ai_line;
    int ai_matches;

    my_printf("\nAI's turn...\n");
    ai_line = choose_ai_line(board, max_lines);
    ai_matches = choose_ai_matches(board, ai_line, max_matches);
    update_board(board, ai_line, ai_matches);
    my_printf("AI removed %d match(es) from line %d\n", ai_matches, ai_line);
    print_board(board);
}