/*
** menu.c for alum1 in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Mon Feb 16 00:45:07 2015 Hippolyte Barraud
** Last update Thu Feb 19 17:22:21 2015 Hippolyte Barraud
*/

#include "../../includes/alum1.h"

void	clear_screen(const string title)
{
  if (system("clear") == -1)
    print_error(ERROR_SYSTEM_CALL, TRUE);
  print_colored(HEADER_SEP, BLUE);
  print_colored(title, BLUE);
  print_colored("\n" HEADER_SEP,
		BLUE);
}

static void	display_gameresult(const t_game *game)
{
  char		c[BUFF];
  int		dif;
  time_t	timeend;

  time(&timeend);
  clear_screen(END_GAME);
  sprintf(c, GAME_WON, get_player_name(game->winner));
  print_colored(c, GREEN);
  dif = difftime(timeend, game->start_time);
  sprintf (c, GAME_TIME , dif);
  printtxt(c);
}

static void	display_stats(const t_game *game)
{
  char		c[BUFF];

  printtxt(GAME_STATS_TITLE);
  sprintf(c, GAME_STATS, game->turn, game->elem_removed, game->last_move);
  printtxt(c);
  printtxt(get_player_stat(game->p1));
  printtxt(get_player_stat(game->p2));
  if (game->map->gauss_resolved > 0)
    {
      sprintf(c, STATS_IA,
	      game->map->gaus_pass, game->map->gauss_resolved,
	      (int)((float)game->map->gauss_resolved /
		    (float)game->map->gaus_pass + 0.5f));
      if (game->p1->difficulty != DOOM && game->p2->difficulty != DOOM)
	strcat(c, NOTE_DOOM);
    }
  else
    strcpy(c, NO_STATS_IA);
  printtxt(c);
}

void	display_endscreen(const t_game *game)
{
  char	c[BUFF];

  display_gameresult(game);
  display_stats(game);
  if (ENABLE_THREADING == TRUE)
    {
      sprintf(c, THREAD_STATS, game->map->concurrent_job,
	      game->map->total_thread);
      printtxt(c);
    }
  prompt_input(PROMPT_QUIT, YELLOW);
}

void	display_welcomescreen(void)
{
  if (system("clear") == -1)
    print_error(ERROR_SYSTEM_CALL, TRUE);
  print_colored(WELCOME_TITLE, BLUE);
  printtxt(WELCOME_MESSAGE);
  prompt_input(PROMPT_BEGIN, YELLOW);
}
