/*
** map_generator.c for alum1 in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Mon Feb 16 00:35:38 2015 Hippolyte Barraud
** Last update Wed Feb 18 23:47:54 2015 Hippolyte Barraud
*/

#include "../../../includes/alum1.h"

static t_map	*gen_random(const t_map_request *req)
{
  t_map		*map;
  int		i;
  int		count;

  map = xmalloc(sizeof(t_map));
  map->levelcount = req->heap_nb;
  map->levels = xmalloc(sizeof(int) * req->heap_nb);
  map->tot_elem = 0;
  i = 0;
  while (i < req->heap_nb)
    {
      count = rand_MimMax(1, req->max_per_heap + 1);
      map->levels[i] = count;
      map->tot_elem += count;
      i++;
    }
  return (map);
}

static t_map	*gen_pyramid(const t_map_request *req)
{
  t_map		*map;
  int		i;
  int		b;

  map = xmalloc(sizeof(t_map));
  map->levelcount = req->heap_nb;
  map->levels = xmalloc(sizeof(int) * req->heap_nb);
  map->tot_elem = 0;
  i = 0;
  b = 1;
  while (i < req->heap_nb)
    {
      map->levels[i] = i + b;
      map->tot_elem += i + b;
      i++;
      b = b + 1;
    }
  return (map);
}

t_map  	*generate_map(const t_map_request *req)
{
  t_map	*map;

  if (req->type == PYRAMID)
    map = gen_pyramid(req);
  else
    map = gen_random(req);
  map->gaus_pass = map->gauss_resolved = 0;
  map->display_map = TRUE;
  map->concurrent_job = 0;
  map->total_thread = 0;
  return (map);
}
