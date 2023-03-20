/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Event module
*/

#include "include/main.h"

void register_event(s_appdata *adata, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        close_window(adata);
        return;
    }

    if (event.type == sfEvtKeyReleased) {
        register_keyrelease(adata, event.key.code);
        return;
    }

    if (event.type == sfEvtKeyPressed) {
        register_keypress(adata, event.key.code);
        return;
    }

    if (event.type == sfEvtMouseMoved) {
        register_mousemove(adata, event.mouseMove);
        return;
    }

    if (event.type == sfEvtMouseButtonPressed) {
        register_mousepressed(adata, event.mouseButton);
        return;
    }

    if (event.type == sfEvtMouseButtonReleased) {
        register_mouserelease(adata, event.mouseButton);
        return;
    }

    if (event.type == sfEvtResized) {
        register_windowresize(adata, event.size);
        return;
    }
}
