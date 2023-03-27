/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Keymap module
*/

#include "main.h"

s_keymap *get_keymap(s_appdata *adata, int keycode)
{
    linked_node *keymaps = adata->lists->keymaps;

    while (keymaps != NULL && keymaps->data != NULL) {
        s_keymap *cur = (s_keymap *) keymaps->data;

        if (cur->keycode == keycode) return (cur);

        keymaps = keymaps->next;
    }

    return (NULL);
}

void add_keymap(s_appdata *adata, int keycode, char ch)
{
    s_keymap *keymap = get_keymap(adata, keycode);

    if (keymap != NULL) {
        my_printf(get_error(adata, "already_exists"));
        return;
    }

    s_keymap *new_keymap = malloc(sizeof(s_keymap));

    if (new_keymap == NULL) {
        my_printf(get_error(adata, "mem_alloc"));
        return;
    }

    new_keymap->ch = ch;
    new_keymap->keycode = keycode;

    linked_add(adata->lists->keymaps, new_keymap);
}

void load_keymaps(s_appdata *adata)
{
    char *file_content = file_extract("bonus/keymap.myrpg");
    char **entries = str_split(file_content, '\n');
    int ite = 0;

    while (entries[ite] != NULL) {
        if (entries[ite][0] == '#') {
            ite++;
            continue;
        }

        char **entry_data = str_split(entries[ite], '=');
        char *keycode = entry_data[0];
        char ch = entry_data[1][0];

        add_keymap(adata, my_getnbr(keycode), ch);

        ite++;
    }
}
