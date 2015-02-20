/*
** map_utils.c for alum1 in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Mon Feb 16 00:38:19 2015 Hippolyte Barraud
** Last update Mon Feb 16 18:01:17 2015 Hippolyte Barraud
*/

#include "../../../includes/alum1.h"

void	sumup_map(t_map *map)
{
  char	c[BUFF];

  printtxt("Nombre de piles du plateau : ");
  sprintf(c, "%d.\n", map->levelcount);
  print_colored(c, YELLOW);
  printtxt("Type de plateau : ");
  if (map->request.type == PYRAMID)
    print_colored("Pyramide.\n", YELLOW);
  else
    {
      print_colored("Aléatoire.\n", YELLOW);
      printtxt("Limite par pile : ");
      sprintf(c, "%d.\n", map->request.max_per_heap);
      print_colored(c, YELLOW);
    }
}

static void	display_map_line(const int columns, const int max)
{
  int		i;
  int		b;

  i = b = 0;
  printtxt(BLUE);
  while (b < (max - columns) / 2)
    {
      printtxt(" ");
      b++;
    }
  while (i < columns)
    {
      printtxt("|");
      i++;
    }
  printtxt(BLANK);
}

static void	display_index(const int i, const bool line_count,
			      const t_map *map)
{
  char		c[20];

  if (line_count)
    {
      sprintf(c, "%3d. ", i + 1);
      printtxt(c);
      sprintf(c, "(%03d)  ", map->levels[i]);
      print_colored(c, YELLOW);
    }
}

void	display_map(const t_map *map, const bool line_count)
{
  int	i;
  int	max;

  if (map->display_map == FALSE)
    return;
  i = max = 0;
  while (i < map->levelcount)
    {
      if (max < *(map->levels + i))
	max = map->levels[i];
      i++;
    }
  i = 0;
  while (i < map->levelcount)
    {
      display_index(i, line_count, map);
      display_map_line(map->levels[i], max);
      printtxt("\n");
      i++;
    }
  printtxt("\n");
}
