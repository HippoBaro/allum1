/*
** new_game.c for alum1 in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Mon Feb 16 00:45:41 2015 Hippolyte Barraud
** Last update Mon Feb 16 02:17:06 2015 Hippolyte Barraud
*/

#include "../../includes/alum1.h"

static void	speedup_battle(t_game *game)
{
  if (game->p1->type == COMPUTER && game->p2->type == COMPUTER
      && game->map->tot_elem >= 5000)
    if (strcmp(prompt_input(SPEEDUP_BATTLE, BLANK), YES) == EQUAL)
      {
	game->map->display_map = FALSE;
	game->wait_ia = 0;
      }
}

static void	sumup_game(t_game *game)
{
  clear_screen(GAME_SUMUP);
  printtxt("\n");
  sumup_map(game->map);
  printtxt("Joueurs :\n" SEPARATOR);
  sumup_player(game->p1);
  sumup_player(game->p2);
  printtxt(SEPARATOR);
}

t_game		*init_game(void)
{
  t_game	*game;

  while (TRUE)
    {
      game = xmalloc(sizeof(t_game));
      game->state = STARTED;
      game->turn = 0;
      game->elem_removed = 0;
      game->winner = NULL;
      game->map = new_map();
      game->wait_ia = 500000;
      set_players(game);
      sumup_game(game);
      if (strcmp(prompt_input("\n" PROMPT_COMFIRM,
			      YELLOW), YES) == EQUAL)
	break;
      else
	free_game(game);
    }
  speedup_battle(game);
  return (game);
}

