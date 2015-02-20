/*
** list.c for alum1 in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Mon Feb 16 00:43:46 2015 Hippolyte Barraud
** Last update Wed Feb 18 23:43:48 2015 Hippolyte Barraud
*/

#include "../../includes/alum1.h"

void		free_list(t_moves *list)
{
  t_moves	*tmp;
  t_moves	*next;

  tmp = list->next;
  while (tmp != list)
    {
      next = tmp->next;
      free(tmp);
      tmp = next;
    }
  free(list);
}

void		add_node(t_moves **list, int line, int count, t_map *map)
{
  t_moves	*new;

  map->gauss_resolved++;
  if ((new = malloc(sizeof(t_moves))) == NULL)
    exit(1);
  new->count = count;
  new->line = line;
  new->prec = (*list)->prec;
  new->next = (*list);
  (*list)->prec->next = new;
  (*list)->prec = new;
}

t_moves		*create_list(void)
{
  t_moves	*root;

  if ((root = malloc(sizeof(t_moves))) == NULL)
    exit(1);
  root->count = -1;
  root->line = -1;
  root->next = root;
  root->prec = root;
  return (root);
}

void		display_list(t_moves *lst)
{
  t_moves	*tmp;
  bool		least;
  char		c[BUFF];

  least = FALSE;
  tmp = lst->next;
  print_colored("Triche : \n", RED);
  while (tmp != lst)
    {
      least = TRUE;
      sprintf(c, MOVE_OPTION,
	      tmp->line + 1, tmp->count);
      print_colored(c, RED);
      tmp = tmp->next;
    }
  if (least == FALSE)
    print_colored(NO_MOVE, RED);
  free_list(lst);
  printtxt("\n");
}

t_moves		*merge_list(t_moves **lst, int lstcount)
{
  t_moves	*tmp;
  t_map		map;
  int		i;

  map.gauss_resolved = 0;
  tmp = (lst[0])->next;
  while (tmp != lst[0])
    tmp = tmp->next;
  i = 1;
  while (i < lstcount)
    {
      tmp = lst[i]->next;
      while (tmp != lst[i])
	{
	  add_node(&lst[0], tmp->line, tmp->count, &map);
	  tmp = tmp->next;
	}
      free_list(lst[i]);
      i++;
    }
  return (lst[0]);
}
