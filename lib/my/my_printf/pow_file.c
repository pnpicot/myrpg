/*
** EPITECH PROJECT, 2022
** convert
** File description:
** convert
*/

#include "../my.h"

int pow_2(double nb)
{
    if (!nb) return (0);
    int res = 0;
    int a = 2;
    if (nb >= 1.0) {
        if ((int) nb == 1) return (res);
        while (a * 2 <= nb) {
            a *= 2;
            res++;
        }
        return (res + 1);
    }
    if (nb < 1.0) {
        double temp = nb;
        int compteur = 0;
        while (temp < 1.0) {
            compteur++;
            temp *= 10;
        }
        return (compteur == 1 ? 2 : (!compteur ? compteur * 3 : 0));
    }
}

int pow_2_nb(double nb)
{
    if (nb >= 1) {
        if ((int) nb == 1) return (1);
        int res = 0;
        int a = 2;
        while (a * 2 <= nb) {
            a *= 2;
        }
        return (a);
    }
    if (nb < 0) {
        double temp = nb;
        int compteur = 0;
        while (temp < 1.0) {
            compteur++;
            temp *= 10;
        }
        if (compteur == 1) return (2);
        if (compteur != 0) return (compteur *3);
    }
}
