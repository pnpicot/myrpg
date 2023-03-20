/*
** EPITECH PROJECT, 2022
** 'my' header
** File description:
** include all libmy's functions prototypes
*/

#pragma once

#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <SFML/Graphics.h>

#define gf_dirs 0x01
#define gf_roots 0x02
#define gf_hidden 0x04
#define gf_rec 0x08

typedef struct {
    struct dirent ent;
    struct stat info;
} s_file;

typedef struct linked_node_s {
    void *data;
    struct linked_node_s *next;
} linked_node;

typedef struct {
    linked_node *second_n;
    linked_node *first_n;
    linked_node *before_n;
    linked_node *after_n;
    linked_node *after_n_f;
    linked_node *before_n_f;
} linked_swap_s;

typedef struct flag_s {
    int type;
    long long int ln_data;
    double dbl_data;
    char *str_data;
    char spe;
    int need_pre;
    int pre;
    int need_width;
    int width;
    char *mod;
    int rsj;
    int rfs;
    int rzp;
    int rp;
    int rlj;
} flag;

typedef struct {
    int current;
    int print_count;
    int counter;
    int max;
    flag *flags;
} flag_container;

typedef struct {
    char *padding;
    char sign;
    char space;
    char *prefix;
} applied_flags;

typedef struct {
    int *last_flag_index;
    va_list *ptr_list;
} parse_ptr_holder;

typedef struct {
    int wh;
    long long dec;
    int wh_tmp;
    long long dc_tmp;
    int wh_len;
    int dc_l;
    char *w_tmp;
    char *d_tmp;
    char *wh_str;
    char *dc_s;
} hd;

typedef struct {
    int rows;
    int cols;
    int arr_size;
    int *widths;
} s_str_ld;

int my_printf(const char *format, ...);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int file_lines_equal(char *content);
int my_putstr(char const *str, int *counter);
char *cv_d_hex(double nb, int mode, int pre);
int file_line_size(char *content);
int file_lines(char *content);
int get_nbr_len(long long nb);
char *filler(int nb, int mode);
char *file_extract(char *filename);
char *put_0(int nb);
int put_multiply_10(int nb);
int my_put_nbr(int nb, int *counter);
long long my_pow(int nb, int power);
char **str_split(const char *str, char delimiter);
linked_node *linked_new(void);
void my_putchar(char c, int *counter);
char *str_add(const char *s1, const char *s2);
void linked_add(linked_node *node, void *data);
void linked_delete(linked_node **list, int id);
int linked_count(linked_node *node);
linked_node *linked_get(linked_node *node, int id);
void linked_swap_case1(linked_node **list, int first, \
int second, linked_swap_s swap);
void linked_swap_default(linked_node **list, int first, \
int second, linked_swap_s swap);
void linked_swap_next(linked_node **list, int first, \
int second, linked_swap_s swap);
void linked_swap(linked_node **list, int first, int second);
void linked_sort(linked_node **list, \
int *comp_func(linked_node *first_node, linked_node *second_node));
void linked_reverse(linked_node **list);
void linked_fuse(linked_node *list1, linked_node *list2);
char *substr(const char *str, int start, int end);
char *nbr_to_str(long long nb);
void parser(char *format, va_list *ptr_list);
void compute_flag(flag_container *container, flag element, va_list *ptr_list);
void subcomp_int(flag_container *container, flag element);
void subcomp_str(flag_container *container, flag element);
void subcomp_char(flag_container *container, flag element);
void subcomp_double(flag_container *container, flag element);
void apply_flags_int(flag_container *container, flag element);
void apply_flags_str(flag_container *container, flag element);
void apply_flags_char(flag_container *container, flag element);
void apply_flags_double(flag_container *container, flag element);
int get_elem_nbr(char *format);
void init_container(flag_container *container, char *format);
void init_flag(flag *ptr_flag);
int check_for_flags(char *format, int start, flag *ptr_flag);
int check_for_width(char *format, int start, flag *ptr_flag);
int check_for_precision(char *format, int start, flag *ptr_flag);
int check_for_modifier(char *format, int start, flag *ptr_flag);
int check_for_specifier(char *format, int start, flag *ptr_flag);
int in_list(char *value, const char *list[], int end);
void get_files(char *dirname, int flags, linked_node *files);
char *get_value_for_int(flag_container *container, flag element);
char *get_value_for_str(flag_container *container, flag element);
char *get_value_for_double(flag_container *container, flag element);
char *flag_prefix_int(char *res, flag element);
void get_dbl_next(char **res, hd hld);
int put_multiply_10(int nb);
char *put_0(int nb);
char *convert_base(int nb, int base);
void display_pointer(void *ptr);
char *get_pointer(void *ptr);
char *put_printable(const char *str);
char *print_sci(double value, int mode, int pre);
void print_dec(double value, int places);
char *str_truncate(char *str, int nb);
char *nbr_to_str(long long nb);
int pow_2(double nb);
int pow_2_nb(double nb);
int gp_int(int nb, int field_width);
void str_rep(char **str, char *replace);
int gp_str(const char *str, int field_width);
int gp_dec(double value, int field_width, int pre);
int in_list_bounds(char *value, char **list, int index_st, int index_ed);
int my_strlen(const char *str);
char *my_strlowcase(char *str);
int my_str_isprintable(char const *str);
int is_dec(const char *str);
int count_ch(const char *str, char ch);
int count_nil_str(char **arr);
int is_num_ch(char ch);
int is_num(const char *str, int dec);
int is_format(char **arr, const char *format);
char **str_m_split(const char *str, int count, ...);
int *range(int from, int to, int step, int *cn);
int reduce(int *list, int count, int fn(int a, int b));
int min(int *list, int count);
int max(int *list, int count);
int sum(int *list, int count);
char *str_join(char **words, char *delimiter);
char *str_m_add(int count, ...);
char *str_insert(char *str, char *part, int pos);
float my_pow_f(float nb, int power);
int my_abs(int nb);
float str_to_float(char *str);
void str_list_display(char **arr, int cols, int pad, int side);
char **int_map_str(int *list, int count);
char *my_strupcase(const char *str);
char **str_map(char **arr, char *fn(const char *str));
char **str_filter(char **arr, int fn(const char *str));
