/*
** player_utils.c for alum1 in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Mon Feb 16 00:52:43 2015 Hippolyte Barraud
** Last update Wed Feb 18 23:50:56 2015 Hippolyte Barraud
*/

#include "../../../includes/alum1.h"

string		get_player_name(t_player *player)
{
  static char	c[BUFF];

  if (player->order == J1)
    sprintf(c, "(J1)");
  else
    sprintf(c, "(J2)");
  if (player->type == HUMAN)
    sprintf(c, "%s%s", c, player->name);
  else
    {
      if (player->difficulty == EASY)
	sprintf(c, "%sIA (Facile)", c);
      else if (player->difficulty == MEDIUM)
	sprintf(c, "%sIA (Normal)", c);
      else if (player->difficulty == HARD)
	sprintf(c, "%sIA (Difficile)", c);
      else if (player->difficulty == DOOM)
	sprintf(c, "%sIA (Doom)", c);
    }
  return (c);
}

string	       	get_player_stat(t_player *player)
{
  static char 	c[BUFF];

  if (player->type == COMPUTER)
    sprintf(c, AI_STATS,
	    get_player_name(player), player->tot_moves,
	    player->perfect_moves,
	    (int)((float)player->perfect_moves /
		  (float)player->tot_moves * 100));
  else
    sprintf(c, PLAYER_STATS,
	    get_player_name(player), player->tot_moves);
  return (c);
}

void	sumup_player(t_player *player)
{
  if (player->type == COMPUTER)
    print_colored(get_player_name(player), YELLOW);
  else if (player->type == HUMAN)
    {
      print_colored(get_player_name(player), YELLOW);
      if (player->hints == TRUE)
	print_colored(CHEATER, RED);
    }
  printtxt("\n");
}
