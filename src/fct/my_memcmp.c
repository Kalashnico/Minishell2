/*
** my_memcmp.c for my_memcmp in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Mon Apr  3 12:39:33 2017 Nicolas
** Last update Wed Apr  5 01:42:32 2017 Nicolas
*/

#include "prototypes.h"

int	my_memcmp(void* s1, void* s2, size_t n)
{
  char	*p1;
  char	*p2;

  p1 = s1;
  p2 = s2;
  while (n > 0)
    {
      if (*p1 != *p2)
	return (84);
      p1++;
      p2++;
      n--;
    }
  return (0);
}
