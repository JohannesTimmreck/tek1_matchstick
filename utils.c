/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** utils
*/

#include "matchstick.h"

int check_for_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}

int check_for_input_number(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}

int my_strlen(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        len++;
    return (len);
}

int my_strcmp(char *s1, char *s2)
{
    int len = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s2[i] == '\0')
            return (1);
        if (s1[len] != s2[len])
            return (1);
        len++;
    }
    if (s2[len] != '\0')
        return (1);
    return (0);
}