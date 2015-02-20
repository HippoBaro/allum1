/*
** gameplay.c for alum1 in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Mon Feb 16 00:32:31 2015 Hippolyte Barraud
** Last update Wed Feb 18 23:46:50 2015 Hippolyte Barraud
*/

#include "../../../includes/alum1.h"

void	init_action(t_action *action)
{
  action->minus_value = -1;
  action->target_line = -1;
}

static t_action		IA_action(t_game *game, t_player *player)
{
  print_colored(THINKING, YELLOW);
  usleep(game->wait_ia);
  player->tot_moves++;
  if (is_map_safe(game->map) == FALSE && do_perfect_move(player) == TRUE)
    return (try_perfect_move(game, player));
  else
    return (random_action(game));
}

static		t_action human_action(t_game *game)
{
  int		lign;
  int		count;
  t_action	action;

  init_action(&action);
  while (TRUE)
    {
      lign = atoi(prompt_input(MOVE_LINE, YELLOW)) - 1;
      if (!is_valid_lign(lign, game))
	{
	  print_error(ERROR_INVALID_LINE, FALSE);
	  continue;
	}
      count = atoi(prompt_input(MOVE_COUNT, YELLOW));
      if (!is_valid_count(lign, count, game))
	{
	  print_error(ERROR_INVALID_COUNT, FALSE);
	  continue;
	}
      break;
    }
  action.target_line = lign;
  action.minus_value = count;
  return (action);
}

static void	player_act(t_game *game, t_player *player)
{
  t_action	action;

  init_action(&action);
  if (player->type == HUMAN)
    {
      if (player->hints == TRUE)
	display_list(get_moves_threaded(game->map));
      player->tot_moves++;
      action = human_action(game);
    }
  else if (player->type == COMPUTER)
    action = IA_action(game, player);
  if (action.minus_value > 0 && action.target_line >= 0)
    {
      game->elem_removed += action.minus_value;
      game->map->levels[action.target_line] -= action.minus_value;
      sprintf(game->last_move, LAST_MOVE, game->turn,
	      get_player_name(player), action.minus_value,
	      action.target_line + 1);
    }
  else
    print_error(ERROR_FATAL, TRUE);
}

void		play(t_game *game)
{
  char		c[BUFF];
  t_player	*current_player;

  while (game->state == STARTED)
    {
      game->turn++;
      current_player = (game->turn % 2 == 0) ?
	game->p2 : game->p1;
      sprintf(c, TURN_PROMPT, game->turn, get_player_name(current_player));
      clear_screen(c);
      if (game->turn > 1)
	print_colored(game->last_move, GREEN);
      display_map(game->map, TRUE);
      player_act(game, current_player);
      if (test_game_winner(game))
	break;
    }
}
