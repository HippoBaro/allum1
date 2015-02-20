/*
** errors.c for alum1 in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Mon Feb 16 00:42:47 2015 Hippolyte Barraud
** Last update Mon Feb 16 00:43:33 2015 Hippolyte Barraud
*/

#include "../../includes/alum1.h"

void	free_map(t_map *map)
{
  free(map->levels);
  free(map);
}

void	free_player(t_player *player)
{
  if (player->type == HUMAN)
    free(player->name);
  free(player);
}

void	free_game(t_game *game)
{
  free_map(game->map);
  free_player(game->p1);
  free_player(game->p2);
  free(game);
}

void	print_error(const string error, const bool isCritical)
{
  print_colored(error, RED);
  if (isCritical)
    exit(EXIT_FAILURE);
}

void	*xmalloc(const size_t size)
{
  void	*p;

  p = malloc(size);
  if (p == NULL)
    print_error(ERROR_MALLOC, TRUE);
  return p;
}
