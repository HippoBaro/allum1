/*
** strinput.c for alum1 in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Mon Feb 16 00:50:30 2015 Hippolyte Barraud
** Last update Mon Feb 16 00:51:02 2015 Hippolyte Barraud
*/

#include "../../includes/alum1.h"

static void	init_buff(string str)
{
  int		i;

  i = -1;
  while ( ++i <= BUFF)
    str[i] = '\0';
}

string		prompt_input(const string prompt, const string color)
{
  static char	buff[BUFF + 1];
  int		len;

  len = 0;
  init_buff(&buff[0]);
  print_colored(prompt, color);
  while ((len = read(0, buff, BUFF)) > 0)
    {
      if (len == BUFF)
	print_error(ERROR_INPUT, TRUE);
      buff[len != 0 ? len - 1 : len] = '\0';
      break;
    }
  return (&buff[0]);
}

