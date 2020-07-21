/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** headerfile
*/

#ifndef HEADER
#define HEADER

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "lib/my_printf/headerfile_printf.h"

struct input_s
{
    int line;
    int matches;
    int line_check;
    int match_check;
};
typedef struct input_s input_t;

int my_getnbr(char const *str);

//board.c
char get_start_character(int line_nb, int column, int size);
char *create_line_for_board(int line_nb, int length, int max_lines);
char **create_game_board(int lines);
void update_board(char **board, int line, int rem_matchs);
void print_board(char **board);

//ai_functions.c
int choose_ai_line(char **board, int max_lines);
int choose_ai_matches(char **board, int line, int max_matches);
void ai_turn(char **board, int max_lines, int max_matches);

//player_turn.c
int read_match_input(input_t *input, int max_matches, int amount_matches);
int read_line_input(input_t *input, char **board, int max_lines,
    int max_matches);
int player_turn(input_t *input, char **board, int size, int max_matches);

//utils.c
int check_for_number(char *str);
int check_for_input_number(char const *str);
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);

//error_functions.c
int check_line(int max_lines, int line);
int check_matches(int max_matches, int amount_matches, int match_nb);
int input_errors(int argc, char const **argv);

//matches.c
int get_last_match(char *line);
int get_amount_matches(char *line);

#endif

