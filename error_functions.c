/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** headerfile
*/

#include "matchstick.h"

int check_line(int max_lines, int line)
{
    if (line < 1 || line > max_lines) {
        write(1, "Error: Line out of reach\n", 25);
        return (1);
    }
    return (0);
}

int check_matches(int max_matches, int amount_matches, int match_nb)
{
    if (match_nb > max_matches) {
        my_printf("Error: you cannot remove more than %d matches\n",
            max_matches);
        return (1);
    } else if (match_nb <= 0) {
        write(1, "Error: You need to take at least one match\n", 43);
        return (1);
    }
    if (match_nb > amount_matches) {
        write(1, "Error: Not enough matches on this line\n", 39);
        return (1);
    }
    return (0);
}

int input_errors(int argc, char const **argv)
{
    if (argc != 3)
        return (1);
    if (check_for_input_number(argv[1]) == 1 ||
        check_for_input_number(argv[2]) == 1)
        return (1);
    if (my_getnbr(argv[1]) < 2 || my_getnbr(argv[1]) > 99)
        return (1);
    return (0);
}
