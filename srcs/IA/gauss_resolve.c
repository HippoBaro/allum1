/*
** gauss_resolve.c for alum1 in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Mon Feb 16 00:47:16 2015 Hippolyte Barraud
** Last update Wed Feb 18 21:47:58 2015 Hippolyte Barraud
*/

#include "../../includes/alum1.h"

bool		is_map_safe(t_map *map)
{
  register int	count;
  register int	safe;
  register int	*levels;
  register int	levelcount;

  levels = map->levels;
  count = 1;
  safe = map->levels[0];
  levelcount = map->levelcount;
  while (count < levelcount)
    safe = safe ^ levels[count++];
  if (safe == 0)
    return (TRUE);
  else
    return (FALSE);
}

static void	gauss_resolve_buid(t_ia_data *dt, t_moves_query *req)
{
  register int	sfck;
  register int 	m;
  register int	*levels;
  register int	count;

  m = dt->m;
  sfck = dt->sfck;
  levels = req->map->levels;
  count = req->map->levelcount;
  while (m < count)
    {
      if (m != dt->k)
	{
	  sfck = sfck ^ levels[m];
	  if (levels[m] > 1)
	    dt->cnthgh = dt->cnthgh + 1;
	  if (levels[m] == 1)
	    dt->cntone = dt->cntone + 1;
	}
      m++;
    }
  dt->sfck = sfck;
  dt->m = m;
}

static void	gauss_init(t_ia_data *dt, t_moves_query *req)
{
  dt->cnthgh = dt->cntone = 0;
  dt->sfck = req->map->levels[dt->k] - dt->l;
  if (dt->sfck > 1)
    dt->cnthgh = dt->cnthgh + 1;
  if (dt->sfck == 1)
    dt->cntone = dt->cntone + 1;
  dt->m = 0;
  gauss_resolve_buid(dt, req);
}

static void	gauss_resolve(t_ia_data *dt, t_moves_query *req, t_moves *moves)
{
  gauss_init(dt, req);
  if (dt->cnthgh != 0)
    {
      if (dt->sfck == 0)
	{
	  dt->m = 0;
	  while (dt->m < req->map->levelcount)
	    if (dt->m++ == (req->map->levelcount - 1))
	      add_node(&moves, dt->k, dt->l, req->map);
	}
    }
  else
    if ((float)(dt->cntone / 2) != (int)((int)dt->cntone / 2))
      {
	dt->m = 0;
	while (dt->m < req->map->levelcount)
	  if (dt->m++ == (req->map->levelcount - 1))
	    add_node(&moves, dt->k, dt->l, req->map);
      }
  dt->l++;
}

void		*get_moves(void *req)
{
  t_moves	*moves;
  t_ia_data	dt;
  t_map		*map;

  map = ((t_moves_query *)req)->map;
  dt.cnthgh = 0;
  dt.cntone = 0;
  dt.k = ((t_moves_query *)req)->from_heap;
  dt.l = 0;
  dt.m = 0;
  dt.sfck = 0;
  moves = create_list();
  while (dt.k < ((t_moves_query *)req)->to_heap)
    {
      dt.l = 1;
      while (dt.l <= map->levels[dt.k])
	gauss_resolve(&dt, req, moves);
      dt.k++;
    }
  return (moves);
}
