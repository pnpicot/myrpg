/*
** EPITECH PROJECT, 2022
** Linked lists functions
** File description:
** Third file
*/

#include "../my.h"

void linked_swap_case1(linked_node **list, int first, \
int second, linked_swap_s swap)
{
    (*list) = swap.second_n;
    swap.second_n->next = swap.after_n_f;
    swap.before_n_f->next = swap.first_n;
    swap.first_n->next = swap.after_n;
}

void linked_swap_default(linked_node **list, int first, \
int second, linked_swap_s swap)
{
    swap.before_n->next = swap.second_n;
    swap.second_n->next = swap.after_n_f;
    swap.before_n_f->next = swap.first_n;
    swap.first_n->next = swap.after_n;
}

void linked_swap_next(linked_node **list, int first, \
int second, linked_swap_s swap)
{
    int count = linked_count(*list);
    if (!first && first + 1 != second) {
        linked_swap_case1(list, first, second, swap);
        return;
    }
    if (!first) {
        (*list) = swap.second_n;
        swap.second_n->next = swap.first_n;
        swap.first_n->next = swap.after_n;
        return;
    }
    if (first + 1 == second) {
        swap.before_n->next = swap.second_n;
        swap.second_n->next = swap.first_n;
        swap.first_n->next = swap.after_n;
        return;
    }
    linked_swap_default(list, first, second, swap);
}

void linked_swap(linked_node **list, int first, int second)
{
    int tmp = first;
    linked_swap_s swap;
    swap.second_n = linked_get(*list, second);
    swap.first_n = linked_get(*list, first);
    int count = linked_count(*list);
    int ite = 0;

    if (second < first) {
        first = second;
        second = tmp;
    }

    if (first > count || second > count || first == second || count <= 1)
        return;

    swap.before_n = linked_get(*list, first - 1);
    swap.after_n = linked_get(*list, second + 1);
    swap.before_n_f = linked_get(*list, second - 1);
    swap.after_n_f = linked_get(*list, first + 1);
    linked_swap_next(list, first, second, swap);
}

void linked_sort(linked_node **list, \
int (*comp_func)(linked_node *first_node, linked_node *second_node))
{
    int ite = 0;
    linked_node *node = *list;
    linked_node *temp = node;

    while (node->next != NULL) {
        if ((*comp_func)(node, node->next)) {
            linked_swap(list, ite, ite + 1);
            linked_sort(list, comp_func);
            break;
        }

        ite++;
        node = node->next;
    }
}
