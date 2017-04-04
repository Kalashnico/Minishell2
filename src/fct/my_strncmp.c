/*
** my_strncmp.c for my_strncmp in /home/nicolas/Epitech/Shell/PSU_2016_minishell2
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Mon Apr  3 20:57:15 2017 Nicolas
** Last update Mon Apr  3 21:09:34 2017 Nicolas
*/

#include "prototypes.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (s1[i] != s2[i])
	return (84);
      i++;
    }
  return (0);
}
