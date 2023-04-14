/*
** EPITECH PROJECT, 2022
** Libmy.a
** File description:
** Str_m_split function (split multiple times)
*/

#include "../my.h"

linked_node *str_m_flat(linked_node *subdiv)
{
    linked_node *tmp = subdiv;
    linked_node *res = linked_new();

    while (tmp != NULL && tmp->data != NULL) {
        char **cur = (char **) tmp->data;
        int ite = 0;

        while (cur[ite] != NULL) {
            linked_add(res, cur[ite]);
            ite++;
        }

        free(cur);

        tmp = tmp->next;
    }

    return (res);
}

void str_m_split_fuse(char **last, linked_node *subdiv, char div)
{
    int ite = 0;

    while (last[ite] != NULL) {
        char **sub = str_split(last[ite], div);
        linked_add(subdiv, sub);
        free(last[ite]);
        ite++;
    }
    free(last);
}

void linked_free(linked_node *node)
{
    while (node != NULL) {
        linked_node *save = node;
        node = node->next;
        free(save);
    }
}

char **str_m_split(const char *str, int count, ...)
{
    va_list args;
    va_start(args, count);
    char **last = str_split(str, (unsigned char) va_arg(args, int));
    for (int i = 0; i < count - 1; i++) {
        linked_node *subdiv = linked_new();
        char div = (unsigned char) va_arg(args, int);
        str_m_split_fuse(last, subdiv, div);
        linked_node *flattened = str_m_flat(subdiv);
        linked_free(subdiv);
        last = malloc(sizeof(char *) * (linked_count(flattened) + 1));
        int ite = 0;
        while (flattened != NULL && flattened->data != NULL) {
            char *cur = (char *) flattened->data;
            last[ite] = cur;
            ite++;
            linked_node *save = flattened;
            flattened = flattened->next;
            free(save);
        }
        last[ite] = NULL;
    }
    va_end(args);
    return (last);
}
