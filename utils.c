/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Utilities module
*/

#include "include/main.h"

sfBool in_range(float value, float min, float max)
{
    if (value >= min && value <= max) return (sfTrue);

    return (sfFalse);
}

float force_range(float value, float min, float max)
{
    if (value > max) value = max;
    else if (value < min) value = min;

    return (value);
}

sfColor lighten(sfColor old, int value)
{
    old.r = force_range(old.r + value, 0, 255);
    old.g = force_range(old.g + value, 0, 255);
    old.b = force_range(old.b + value, 0, 255);

    return (old);
}

sfColor darken(sfColor old, int value)
{
    old.r = force_range(old.r - value, 0, 255);
    old.g = force_range(old.g - value, 0, 255);
    old.b = force_range(old.b - value, 0, 255);

    return (old);
}

sfColor get_color(int r, int g, int b, int a)
{
    return ((sfColor) { r, g, b, a });
}

sfColor get_grayscale(sfColor color)
{
    int average = (color.r + color.g + color.b) / 3;
    sfColor grayscale;

    grayscale.r = average;
    grayscale.g = average;
    grayscale.b = average;
    grayscale.a = color.a;

    return (grayscale);
}

float get_vec_dist(sfVector2f vec_a, sfVector2f vec_b)
{
    sfVector2f dist_vec;
    dist_vec.x = vec_a.x - vec_b.x;
    dist_vec.y = vec_a.y - vec_b.y;

    float dist = sqrt(pow(dist_vec.x, 2) + pow(dist_vec.y, 2));

    return (dist);
}

sfBool circle_contains(sfVector2f circle_pos, float radius, sfVector2f point)
{
    float dist = get_vec_dist(circle_pos, point);

    return (dist <= radius);
}

sfVector2f ivec_to_f(sfVector2i vec)
{
    return ((sfVector2f) { vec.x, vec.y });
}

sfVector2i fvec_to_i(sfVector2f vec)
{
    return ((sfVector2i) { vec.x, vec.y });
}

int rand_int(int min, int max)
{
    return ((rand() % (max - min + 1)) + min);
}

float rand_float(float min, float max)
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float factor = random * diff;

    return (min + factor);
}

sfVector2f rand_screen_pos(s_appdata *adata)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    sfVector2f pos;

    pos.x = rand_float(0, (float) win_w);
    pos.y = rand_float(0, (float) win_h);

    return (pos);
}

sfColor rand_color(sfUint8 alpha)
{
    sfColor new_color;
    new_color.r = rand_int(0, 255);
    new_color.g = rand_int(0, 255);
    new_color.b = rand_int(0, 255);
    new_color.a = alpha ? rand_int(0, 255) : 255;

    return (new_color);
}

sfBool rect_intersects_circle(sfFloatRect rect, sfVector2f circle_pos, float radius)
{
    sfVector2f top_left_pos;
    top_left_pos.x = rect.left;
    top_left_pos.y = rect.top;

    sfVector2f top_right_pos;
    top_right_pos.x = rect.left + rect.width;
    top_right_pos.y = rect.top;

    sfVector2f bottom_left_pos;
    bottom_left_pos.x = rect.left;
    bottom_left_pos.y = rect.top + rect.height;

    sfVector2f bottom_right_pos;
    bottom_right_pos.x = rect.left + rect.width;
    bottom_right_pos.y = rect.top + rect.height;

    sfBool top_left = circle_contains(circle_pos, radius, top_left_pos);
    sfBool top_right = circle_contains(circle_pos, radius, top_right_pos);
    sfBool bottom_left = circle_contains(circle_pos, radius, bottom_left_pos);
    sfBool bottom_right = circle_contains(circle_pos, radius, bottom_right_pos);

    return (top_left || top_right || bottom_left || bottom_right);
}

sfVector2f get_mouse(s_appdata *adata)
{
    sfVector2i mouse_absolute = sfMouse_getPositionRenderWindow(adata->win);
    const sfView *view = sfRenderWindow_getView(adata->win);
    sfVector2f mouse_relative = sfRenderWindow_mapPixelToCoords(adata->win, mouse_absolute, view);

    return (mouse_relative);
}

float hue_to_rgb(float v1, float v2, float vH)
{
    if (vH < 0) vH++;
    if (vH > 1) vH--;
    if ((6 * vH) < 1) return (v1 + (v2 - v1) * 6 * vH);
    if ((2 * vH) < 1) return (v2);
    if ((3 * vH) < 2) return (v1 + (v2 - v1) * ((2 / 3) - vH) * 6);
}

sfColor sfColor_toRGB(sfVector3f old)
{
    float h = old.x;
    float s = old.y;
    float l = old.z;

    if (s == 0) {
        int r = l * 255.0f;
        int g = l * 255.0f;
        int b = l * 255.0f;

        return (get_color(r, g, b, 255));
    }

    float var_2;

    if (l < 0.5f) {
        var_2 = l * (1 + s);
    } else {
        var_2 = (l + s) - (s * l);
    }

    float var_1 = 2 * l - var_2;
    int r = 255 * hue_to_rgb(var_1, var_2, h + (1 / 3));
    int g = 255 * hue_to_rgb(var_1, var_2, h);
    int b = 255 * hue_to_rgb(var_1, var_2, h - (1 / 3));

    return (get_color(r, g, b, 255));
}

sfVector3f sfColor_toHSL(sfColor old)
{
    float r = (float) old.r / 255;
    float g = (float) old.g / 255;
    float b = (float) old.b / 255;

    float min = r;

    if (g < min) min = g;
    if (b < min) min = b;

    float max = r;

    if (g > max) max = g;
    if (b > max) max = b;

    float del_max = max - min;
    float h;
    float s;
    float l = (max + min) / 2;

    if (del_max == 0) {
        h = 0;
        s = 0;

        return ((sfVector3f) { h, s, l });
    }

    if (l < 0.5f) {
        s = del_max / (max + min);
    } else {
        s = del_max / (2 - max - min);
    }

    float del_r = (((max - r) / 6) + (del_max / 2)) / del_max;
    float del_g = (((max - g) / 6) + (del_max / 2)) / del_max;
    float del_b = (((max - b) / 6) + (del_max / 2)) / del_max;

    if (r == max) h = del_b - del_g;
    else if (g == max) h = (1 / 3) + del_r - del_b;
    else if (b == max) h = (2 / 3) + del_g - del_r;

    if (h < 0) h++;
    if (h > 1) h--;

    return ((sfVector3f) { h, s, l });
}

char *get_random_id(int len)
{
    char *id = malloc(sizeof(char) * (len + 1));
    id[len] = '\0';

    for (int i = 0; i < len; i++) {
        id[i] = (signed char) rand_int(0, 1) ? rand_int(65, 90) : rand_int(97, 122);
    }

    return (id);
}
