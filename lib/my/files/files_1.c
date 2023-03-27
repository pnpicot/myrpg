/*
** EPITECH PROJECT, 2022
** Files handling
** File description:
** First file
*/

#include "../my.h"
#include <unistd.h>

char *file_extract(char *filename)
{
    struct stat st;
    stat(filename, &st);
    int fd = open(filename, O_RDONLY);
    size_t count = st.st_size;
    char buff[count];
    char *res = malloc(sizeof(char) * (count + 1));
    ssize_t stream = read(fd, &buff, count);
    if (fd == -1) return (NULL);
    while (stream > 0) {
        stream = read(fd, &buff, count);
    }
    for (int i = 0; i < (int) count; i++) {
        res[i] = buff[i];
    }
    res[count] = '\0';
    return (res);
}

int file_lines(char *content)
{
    int count = 0;

    for (int i = 0; i < my_strlen(content); i++) {
        if (content[i] == '\n') count++;
    }
    return (count);
}

int file_line_size(char *content)
{
    int size = 0;
    int max = 0;

    for (int i = 0; i < my_strlen(content); i++) {
        if (content[i] == '\n') {
            max = size > max ? size : max;
            size = 0;
        }
        size++;
    }
    return (max - 1);
}

char **get_str_2d(char *str)
{
    int count = file_lines(str);
    char **res = malloc(sizeof(char *) * count);
    int append = 0;
    int append_line = 0;
    char *line = malloc(sizeof(char) * file_line_size(str));

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '\n') {
            res[append] = line;
            append++;
            append_line = 0;
            line = malloc(sizeof(char) * file_line_size(str));
            continue;
        }
        line[append_line] = str[i];
        append_line++;
    }
    return (res);
}

int file_lines_equal(char *content)
{
    int res = 1;
    int count = file_line_size(content);
    int current = 0;

    for (int i = 0; i < my_strlen(content); i++) {
        if (content[i] == '\n' && current == count) {
            current = 0;
            continue;
        }
        if (content[i] != '\n') {
            res = 0;
            break;
        }
        current++;
    }

    return (res);
}
