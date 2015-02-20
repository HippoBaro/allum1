/*
** rules.c for alum1 in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Mon Feb 16 00:34:56 2015 Hippolyte Barraud
** Last update Mon Feb 16 00:35:22 2015 Hippolyte Barraud
*/

#include "../../../includes/alum1.h"

bool	is_valid_lign(int lign, t_game *game)
{
  if (lign < 0)
    return (FALSE);
  else if (lign > game->map->levelcount)
    return (FALSE);
  else if (game->map->levels[lign] < 1)
    return (FALSE);
  return (TRUE);
}

bool	is_valid_count(int lign, int count, t_game *game)
{
  if (count < 1)
    return (FALSE);
  else if (game->map->levels[lign] - count < 0)
    return (FALSE);
  return (TRUE);
}

bool	test_game_winner(t_game *game)
{
  int	i;

  i = 0;
  while (i < game->map->levelcount)
    if (game->map->levels[i++] > 0)
      return (FALSE);
  game->state = FINISHED;
  if (game->turn % 2 == 0)
    game->winner = game->p1;
  else
    game->winner = game->p2;
  display_endscreen(game);
  return (TRUE);
}
