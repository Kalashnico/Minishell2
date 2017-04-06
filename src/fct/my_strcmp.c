/*
** my_strcmp.c for strcmp in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/fct
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Thu Apr  6 16:20:42 2017 Nicolas
** Last update Thu Apr  6 16:23:06 2017 Nicolas
*/

#include "prototypes.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (84);
  while (s1 && s1[i] && s2 && s2[i])
    {
      if (s1[i] != s2[i])
	return (84);
      i++;
    }
  return (0);
}
