/*
** my_putstr.c for my_putstr in /home/guerin_n/Epitech/Shell/PSU_2016_minishell1/src/fct
** 
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
** 
** Started on  Mon Jan  9 15:49:24 2017 Nicolas Guerin
** Last update Sun Apr  2 04:04:31 2017 Nicolas
*/

#include "prototypes.h"

void	my_putstr(char *str, int fd)
{
  int	n;

  n = 0;
  while (str && str[n])
    my_putchar(str[n++], fd);
}
