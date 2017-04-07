/*
** my_memset.c for my_memset in /home/nicolas/Epitech/Shell/PSU_2016_minishell2
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 03:16:40 2017 Nicolas
** Last update Wed Apr  5 03:25:08 2017 Nicolas
*/

#include "prototypes.h"

void	my_memset(void *s, int c, int n)
{
  char	*mem;
  int	i;

  i = 0;
  mem = (char *)s;
  while (i < n)
    {
      mem[i] = c;
      i++;
    }
}
