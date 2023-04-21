/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Main file
*/

#include "include/main.h"

DEF_IT(update)
DEF_IT(render)
DEF_IT(update_entities)
DEF_IT(total)
DEF_IT(agro)
DEF_IT(what_is_touching)
DEF_IT(is_map_colliding)
DEF_IT(get_way)
DEF_IT(fps)

int main(int argc, char **argv)
{
    s_appdata *adata = malloc(sizeof(s_appdata));

    if (adata == NULL) {
        my_printf("[MyRPG] error: memory allocation failed.\n");
        return (84);
    }

    pre_init(adata);
    create_window(adata);

    int exit_status = adata->integers->exit_status;

    destroy(adata);

    return (exit_status);
}
