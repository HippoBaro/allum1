/*
** main.c for alum1 in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Mon Feb 16 00:32:10 2015 Hippolyte Barraud
** Last update Mon Feb 16 17:11:34 2015 Hippolyte Barraud
*/

#include "../includes/alum1.h"

int		main(void)
{
  t_game	*game;

  srand(time(NULL));
  display_welcomescreen();
  game = init_game();
  time(&game->start_time);
  play(game);
  free_game(game);
  return (EXIT_SUCCESS);
}
