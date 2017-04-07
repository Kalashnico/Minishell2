/*
** my_strlen.c for my_strlen in /home/guerin_n/Epitech/Shell/PSU_2016_minishell1/src/fct
** 
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
** 
** Started on  Mon Jan  9 15:50:12 2017 Nicolas Guerin
** Last update Wed Apr  5 01:21:39 2017 Nicolas
*/

#include "prototypes.h"

int	my_strlen(char *str)
{
  int	n;

  n = 0;
  while (str && str[n])
    n++;
  return (n);
}
