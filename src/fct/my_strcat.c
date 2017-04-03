/*
** my_strcat.c for my_strcat in /home/guerin_n/Epitech/CPE/CPE_2016_matchstick/src/fct
** 
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
** 
** Started on  Fri Feb 24 16:29:08 2017 Nicolas Guerin
** Last update Mon Apr  3 15:37:14 2017 Nicolas
*/

#include "prototypes.h"

void	my_strcat(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = -1;
  while (s1 && s1[i])
    i++;
  while (s2 && s2[++j] && s2[j] != '\n')
    s1[i++] = s2[j];
  s1[i] = 0;
}
