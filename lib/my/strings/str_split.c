/*
** EPITECH PROJECT, 2022
** Libmy.a
** File description:
** Str_split function
*/

#include "../my.h"

static char *compress_delimiter(const char *str, char delimiter)
{
    char *new = NULL;;
    int j = 0;

    if (str == NULL)
        return (NULL);
    new = malloc(my_strlen(str) + 1);
    if (new == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter &&
        (str[i + 1] == delimiter || str[i + 1] == '\0' ||
        i == 0))
            continue;
        new[j++] = str[i];
    }
    new[j] = '\0';
    return (new);
}

static int count_word(const char *str, char delimiter)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter && str[i + 1] != '\0')
            count++;
    }
    return (count + 1);
}

static int malloc_subtab(char **tab, char *str, char delimiter)
{
    int j = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != delimiter) {
            k++;
            continue;
        }
        tab[j] = malloc(k + 1);
        if (tab[j] == NULL)
            return (-1);
        j++;
        k = 0;
    }
    tab[j] = malloc(k + 1);
    if (tab[j] == NULL)
        return (-1);
    return (0);
}

static void fill_tab(char **tab, char *str, char delimiter)
{
    int j = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter) {
            tab[j][k] = '\0';
            j++;
            k = 0;
            continue;
        }
        tab[j][k] = str[i];
        k++;
    }
    tab[j][k] = '\0';
}

char **str_split(const char *str, char delimiter)
{
    int nb_word = 0;
    char *new_str = compress_delimiter(str, delimiter);
    char **tab = NULL;

    if (new_str == NULL)
        return (NULL);
    nb_word = count_word(new_str, delimiter);
    if (nb_word == 0)
        return (NULL);
    tab = malloc(sizeof(char *) * (nb_word + 1));
    if (tab == NULL)
        return (NULL);
    if (malloc_subtab(tab, new_str, delimiter) < 0)
        return (NULL);
    tab[nb_word] = NULL;
    fill_tab(tab, new_str, delimiter);
    free(new_str);
    return (tab);
}
