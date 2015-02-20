/*
** stroutput.c for alum1 in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Mon Feb 16 00:51:14 2015 Hippolyte Barraud
** Last update Wed Feb 18 23:56:06 2015 Hippolyte Barraud
*/

#include "../../includes/alum1.h"

void	print_colored(const string str, const string color)
{
  printtxt(color);
  printtxt(str);
  printtxt(BLANK);
}

void	printtxt(const string str)
{
  if (write(1, str, strlen(str)) == -1)
    print_error(ERROR_SYSTEM_CALL, TRUE);
}
