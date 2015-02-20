/*
** new_player.c for alum1 in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Mon Feb 16 00:41:34 2015 Hippolyte Barraud
** Last update Thu Feb 19 00:27:45 2015 Hippolyte Barraud
*/

#include "../../../includes/alum1.h"

void	set_players(t_game *game)
{
  game->p1 = new_player(J1);
  game->p2 = new_player(J2);
}

static void	setup_IA(t_player *player)
{
  string	input;

  player->type = COMPUTER;
  input = strdup(prompt_input(PROMPT_DIFICULTY,
			      BLANK));
  if (strcmp(input, "easy") == EQUAL)
    player->difficulty = EASY;
  else if (strcmp(input, "medium") == EQUAL)
    player->difficulty = MEDIUM;
  else if (strcmp(input, "hard") == EQUAL)
    player->difficulty = HARD;
  else if (strcmp(input, "doom") == EQUAL)
    player->difficulty = DOOM;
  else
    {
      print_error(ERROR_DIFICULTY, FALSE);
      setup_IA(player);
    }
  free(input);
}

static void	setup_human(t_player *player)
{
  player->type = HUMAN;
  player->name = strdup(prompt_input(PLAYER_NAME, BLANK));
  player->difficulty = NONE;
  if (strcmp(prompt_input(PROMPT_CHEAT, RED),
	     YES) == EQUAL)
    player->hints = TRUE;
  else
    player->hints = FALSE;
}

static bool	select_player_type(t_player *player)
{
  string	input;

  input = strdup(prompt_input(PLAYER_TYPE, BLANK));
  if (strcmp(input, "Humain") == EQUAL)
    {
      setup_human(player);
      free(input);
      return (TRUE);
    }
  else if (strcmp(input, "IA") == EQUAL)
    {
      setup_IA(player);
      free(input);
      return (TRUE);
    }
  else
    print_error(ERROR_PLAYER_TYPE, FALSE);
  free(input);
  return (FALSE);
}

t_player	*new_player(e_player_order order)
{
  t_player	*player;

  clear_screen(PLAYER_CONFIG);
  printtxt("\n");
  if (order == J1)
    printtxt("Joueur 1 :\n\n" SEPARATOR);
  else
    printtxt("Joueur 2 :\n\n" SEPARATOR);
  player = xmalloc(sizeof(t_player));
  player->order = order;
  player->tot_moves = player->perfect_moves = 0;
  while (TRUE)
    if (select_player_type(player) == TRUE)
      break;
  return (player);
}
