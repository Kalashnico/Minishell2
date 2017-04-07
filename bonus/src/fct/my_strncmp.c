/*
** my_strncmp.c for strncmp in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/fct
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Thu Apr  6 16:29:33 2017 Nicolas
** Last update Thu Apr  6 23:49:13 2017 Nicolas
*/

#include "prototypes.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  if (s1 == NULL || s2 == NULL || n == 0)
    return (84);
  while (i < n)
    {
      if (s1[i] != s2[i])
	return (84);
      i++;
    }
  return (0);
}
