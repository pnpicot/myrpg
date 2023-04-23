/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** Save module
*/

#include "main.h"

void modify_game_syringe(s_appdata *adata, linked_node *syringe, \
char **lines, int i)
{
    char **syr_stat = str_split(lines[i], '~');
    while (syringe != NULL && syringe->data != NULL) {
        s_syringe *syr_cur = (s_syringe *) syringe->data;
        if (!my_strcmp(syr_cur->name, syr_stat[0])) {
            syr_cur->count = my_getnbr(syr_stat[1]);
            break;
        }
        syringe = syringe->next;
    }
}

void modify_game_quests(s_appdata *adata, linked_node *quests, \
char **lines, int i)
{
    char **quest_stat = str_split(lines[i], '~');
    while (quests != NULL && quests->data != NULL) {
        s_quest *quest_cur = (s_quest *) quests->data;
        if (!my_strcmp(quest_cur->title, quest_stat[0])) {
            quest_cur->completed = my_getnbr(quest_stat[1]);
            break;
        }
        quests = quests->next;
    }
}

void modify_game_skill_trees(s_appdata *adata, linked_node *trees, \
char **lines, int i)
{
    char **trees_stat = str_split(lines[i], '~');
    while (trees != NULL && trees->data != NULL) {
        s_skill_tree *trees_cur = (s_skill_tree *) trees->data;
        if (!my_strcmp(trees_cur->id, trees_stat[0])) {
            trees_cur->y_end = my_getnbr(trees_stat[2]);
            break;
        }
        trees = trees->next;
    }
}

void modify_game_entities(s_appdata *adata, linked_node *models, \
char **lines, int i)
{
    char **model_stat = str_split(lines[i], '~');
    
    while (models != NULL && models->data != NULL) {
        s_entity *model = (s_entity *) models->data;
        s_faction *faction = model->faction;
        if (!my_strcmp(faction->id, model_stat[0])) {
            sfClock_restart(model->clock);
            s_entity *new_entity = copy_entity_model(adata, model);
            sfVector2f pos = {str_to_float(model_stat[1]), str_to_float(model_stat[2])};
            new_entity->pos = pos;
            faction->entity_count++;

            if (new_entity->emiter != NULL) {
                int win_w = get_int(adata, "win_w");
                int win_h = get_int(adata, "win_h");
                (*new_entity->emiter)(adata, new_entity);
                char *emiter_id = str_add(new_entity->id, "@[:emiter]");
                pos.x -= adata->game_data->view_pos.x;
                pos.y -= adata->game_data->view_pos.y;
                translate_emiter(adata, emiter_id, pos);
            }

            linked_add(adata->game_data->entities, new_entity);
        }
        models = models->next;
    }
}

void modify_game(s_appdata *adata, char *content)
{
    char **lines = str_split(content, '#');
    int j = 0;
    while (lines[j] != NULL) {
        printf("%s\n",lines[j]);
        j++;
    }

    s_player *player = adata->player;
    player->attack = str_to_float(lines[0]);
    player->defense = str_to_float(lines[1]);
    player->health_rate = str_to_float(lines[2]);
    player->health.x = str_to_float(lines[3]);
    player->health.y = str_to_float(lines[4]);
    player->moula = str_to_float(lines[5]);
    player->transference_rate = str_to_float(lines[6]);
    player->transference.x = str_to_float(lines[7]);
    player->transference.y = str_to_float(lines[8]);
    player->transference_level = my_getnbr(lines[9]);
    int i = 11;
    while (my_strcmp(lines[i], "$array")) {
        linked_node *syringe = adata->game_data->syringes;
        modify_game_syringe(adata, syringe, lines, i);
        i++;
    }
    i += 2;

    while (my_strcmp(lines[i], "$array")) {
        linked_node *quests = adata->game_data->quests;
        modify_game_quests(adata, quests, lines, i);
        i++;
    }
    i++;

    adata->game_data->view_pos.x = str_to_float(lines[i]);
    adata->game_data->view_pos.y = str_to_float(lines[i + 1]);
    adata->game_data->velocity = str_to_float(lines[i + 2]);
    adata->game_data->speed_max = str_to_float(lines[i + 3]);
    adata->game_data->speed.x = str_to_float(lines[i + 4]);
    adata->game_data->speed.y = str_to_float(lines[i + 5]);
    i += 7;

    while (my_strcmp(lines[i], "$array")) {
        linked_node *trees = adata->game_data->skill_trees;
        modify_game_skill_trees(adata, trees, lines, i);
        i++;
    }
    i += 2;

    free_ll_and_data(&adata->game_data->entities);
    adata->game_data->entities = linked_new();


    linked_node *factions = adata->game_data->factions;
    while (factions != NULL && factions->data != NULL) {
        s_faction *faction = (s_faction *) factions->data;
        faction->entity_count = 0;
        factions = factions->next;
    }

    while (my_strcmp(lines[i], "$array")) {
        linked_node *models = adata->game_data->entity_models;
        modify_game_entities(adata, models, lines, i);
        i++;
    }
}

void load_game(s_appdata *adata)
{
    char *input_load = get_str(adata, "input_load");
    const char *input_text = get_input_str(adata, input_load);
    char *path = str_add("bonus/saves/", input_text);
    char *content = file_extract(path);
    modify_game(adata, content);
}

void init_load_input(s_appdata *adata, char *container, char *rtex)
{
    int win_w = get_int(adata, "win_w");
    int win_h = get_int(adata, "win_h");
    char *input_load = get_str(adata, "input_load");
    add_input(adata, input_load, 7);
    set_input_font(adata, input_load, get_font(adata, "lobster"));
    set_input_rtex(adata, input_load, rtex);
    set_input_maxlength(adata, input_load, 40);
    set_input_placeholder(adata, input_load, "Enter path...");
    set_input_align(adata, input_load, "center");
    add_to_container(adata, container, (s_ref) {
    get_input(adata, input_load), TYPE_INPUT});
    resize_input(adata, input_load, (sfVector2f) { 400, 60 });
    sfVector2f pos = { win_w / 2 - 200, win_h / 2 - 30};
    move_input(adata, input_load, pos);
}

void init_load_btn(s_appdata *adata, char *container, char *rtex)
{
    char *back_btn = get_str(adata, "btn_load");
    int win_h = get_int(adata, "win_h");
    add_button(adata, back_btn, TYPE_RECT, 1);
    edit_button(adata, back_btn, "Load");
    set_button_font(adata, back_btn, get_font(adata, "lobster"));
    color_button_fg(adata, back_btn, sfWhite);
    color_button_bg(adata, back_btn, get_color(255, 255, 255, 10));
    set_button_rtex(adata, back_btn, rtex);
    add_to_container(adata, container, (s_ref) {
    get_button(adata, back_btn), TYPE_BUTTON });
    resize_button(adata, back_btn, (sfVector2f) { 280, 60 });
    sfVector2f pos = { get_int(adata, "win_w") / 2 - 140, win_h / 2 + 100};
    move_button(adata, back_btn, pos);
    set_button_out(adata, back_btn, sfWhite, 2.0f);
    char *obj = str_add(back_btn, "@[:object]");
    s_ref ref = { get_button(adata, back_btn), TYPE_BUTTON };
    add_object(adata, obj, ref);
    set_object_hover_bg(adata, obj, get_color(255, 255, 255, 30));
    set_object_pressed_bg(adata, obj, get_color(255, 255, 255, 50));
    set_object_onclick(adata, obj, &load_game);
}