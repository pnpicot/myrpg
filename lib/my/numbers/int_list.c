/*
** EPITECH PROJECT, 2022
** Integer list handling
** File description:
** First file
*/

#include "../my.h"

int *range(int from, int to, int step, int *cn)
{
    if ((from < to && step < 0) || (from > to && step > 0)) {
        (*cn) = 0;
        return (NULL);
    }

    int count = (to - from) / step;
    (*cn) = count;
    int *res = malloc(sizeof(int) * count);
    int ite = 0;

    for (int i = from; i < to; i += step) {
        res[ite] = i;
        ite++;
    }

    return (res);
}

int sum(int *list, int count)
{
    int res = 0;

    for (int i = 0; i < count; i++) {
        res += list[i];
    }

    return (res);
}

int max(int *list, int count)
{
    int max = list[0];

    for (int i = 1; i < count; i++) {
        if (list[i] > max) max = list[i];
    }

    return (max);
}

int min(int *list, int count)
{
    int min = list[0];

    for (int i = 1; i < count; i++) {
        if (list[i] < min) min = list[i];
    }

    return (min);
}

int reduce(int *list, int count, int fn(int a, int b))
{
    int res = list[0];

    for (int i = 1; i < count; i++) {
        res = (*fn)(res, list[i]);
    }

    return (res);
}
