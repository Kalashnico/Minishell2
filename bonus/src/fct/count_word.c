/*
** count_word.c for count_word in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 00:06:07 2017 Nicolas
** Last update Wed Apr  5 01:21:17 2017 Nicolas
*/

#include "prototypes.h"

int	count_word(char *str)
{
  int   i;
  int   res;

  if (str)
    return (0);
  i = 0;
  res = 1;
  while (str[i])
    {
      if (str[i] == 32)
	res++;
      i++;
    }
  return (res);
}
