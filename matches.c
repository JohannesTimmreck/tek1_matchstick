/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matches
*/

#include "matchstick.h"

int get_last_match(char *line)
{
    int pos = 1;

    for (int i = 1; line[i] != '*'; i++)
        pos++;
    while (line[pos - 1] != '|' && line[pos - 1] != '*')
        pos--;
    pos--;
    return (pos);
}

int get_amount_matches(char *line)
{
    int amount_matches = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '|')
            amount_matches++;
    }
    return (amount_matches);
}
