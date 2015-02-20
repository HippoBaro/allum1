/*
** IA.c for alum1 in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Mon Feb 16 00:48:28 2015 Hippolyte Barraud
** Last update Mon Feb 16 00:53:50 2015 Hippolyte Barraud
*/

#include "../../includes/alum1.h"

int		rand_MimMax(int Min, int Max)
{
  double	myRand;
  int		range;
  int		myRand_scaled;

  Max--;
  myRand = rand()/(1.0 + RAND_MAX);
  range = Max - Min + 1;
  myRand_scaled = (myRand * range) + Min;
  return (myRand_scaled);
}

static t_action		select_best_move(t_game *game, t_moves *moves,
					 t_player *player)
{
  t_moves		*tmp;
  t_moves		*best;
  t_action		action;

  tmp = moves->next;
  best = tmp;
  while (tmp != moves && player->difficulty == DOOM)
    {
      if (tmp->count > best->count)
	best = tmp;
      tmp = tmp->next;
    }
  if (!(best->line >= 0 && best->count > 0))
    return (random_action(game));
  action.minus_value = best->count;
  action.target_line = best->line;
  player->perfect_moves++;
  return (action);
}

t_action	random_action(t_game *game)
{
  t_action	action;
  int		line;
  int		count;

  line = -1;
  count = -1;
  while (is_valid_lign(line, game) == FALSE)
    line = rand_MimMax(0, game->map->levelcount);
  while (is_valid_count(line, count, game) == FALSE)
    count = rand_MimMax(1, game->map->levels[line] + 1);
  action.minus_value = count;
  action.target_line = line;
  return (action);
}

bool		do_perfect_move(t_player *player)
{
  int		rand;

  rand = rand_MimMax(0, 101);
  if (player->difficulty == EASY && rand < DIF_EASY)
    return (TRUE);
  else if (player->difficulty == MEDIUM && rand < DIF_MEDIUM)
    return (TRUE);
  else if (player->difficulty == HARD && rand < DIF_HARD)
    return (TRUE);
  else if (player->difficulty == DOOM)
    return (TRUE);
  return (FALSE);
}

t_action	try_perfect_move (t_game *game, t_player *player)
{
  t_action	action;
  t_moves	*moves;

  moves = get_moves_threaded(game->map);
  action = select_best_move(game, moves, player);
  free_list(moves);
  return (action);
}
