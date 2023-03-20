/*
** EPITECH PROJECT, 2022
** Files handling
** File description:
** Second file
*/

#include "../my.h"

void get_files(char *dirname, int flags, linked_node *files)
{
    struct dirent *ent;
    DIR *dfd = opendir(dirname);
    if (dfd == NULL) return;
    while ((ent = readdir(dfd)) != NULL) {
        struct stat info;
        struct dirent copy = *ent;
        char *path = str_add(dirname, str_add("/", ent->d_name));
        stat(path, &info);
        int is_root = !my_strcmp(ent->d_name, ".")
            || !my_strcmp(ent->d_name, "..");
        if (ent->d_name[0] == '.' && !(flags & gf_hidden) && !is_root) continue;
        if (S_ISDIR(info.st_mode) && (flags & gf_rec) && !is_root)
            get_files(path, flags, files);
        if (S_ISDIR(info.st_mode) && !(flags & gf_dirs)) continue;
        if (is_root && !(flags & gf_roots)) continue;
        s_file *new_file = malloc(sizeof(s_file));
        new_file->ent = copy;
        new_file->info = info;
        linked_add(files, new_file);
    }
}
