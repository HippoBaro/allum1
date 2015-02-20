/*
** map_prompt.c for alum1 in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Mon Feb 16 00:36:49 2015 Hippolyte Barraud
** Last update Mon Feb 16 02:26:22 2015 Hippolyte Barraud
*/

#include "../../../includes/alum1.h"

static void	config_random_map(t_map_request *req)
{
  req->type = RANDOM;
  while (TRUE)
    {
      if ((req->max_per_heap = atoi(prompt_input(HEAP_LIMIT,
						 BLANK))) < 5)
	{
	  print_error(ERROR_HEAP_LIMIT, FALSE);
	  continue;
	}
      break;
    }
}

static void	prompt_map_type(t_map_request *req)
{
  string	input;

  printtxt("\n");
  while (TRUE)
    {
      if ((req->heap_nb = atoi(prompt_input(HEAP_COUNT, BLANK))) < 3)
	{
	  print_error(ERROR_HEAP_COUNT, FALSE);
	  continue;
	}
      input = strdup(prompt_input(MAP_TYPE, BLANK));
      if (strcmp(input, "Pyramidal") == EQUAL)
	req->type = PYRAMID;
      else if (strcmp(input, "Aléatoire") == EQUAL)
	config_random_map(req);
      else
	{
	  print_error(ERROR_MAP_TYPE, FALSE);
	  continue;
	}
      free(input);
      break;
    }
}

t_map		*new_map(void)
{
  t_map		*map;
  t_map_request req;
  char		c[BUFF];

  while (TRUE)
    {
      clear_screen(GAME_CONFIG);
      prompt_map_type(&req);
      printtxt("\n");
      display_map(map = generate_map(&req), FALSE);
      sprintf(c, "Ce plateau contient %d allumettes.\n", map->tot_elem);
      printtxt(c);
      if (strcmp(prompt_input(PROMPT_COMFIRM, YELLOW),
		 YES) == EQUAL)
	break;
      else
	free_map(map);
    }
  map->request = req;
  return (map);
}
