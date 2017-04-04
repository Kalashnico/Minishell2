/*
** my_strdup.c for my_strdup in /home/guerin_n/Epitech/Shell/PSU_2016_minishell1/src/fct
** 
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
** 
** Started on  Mon Jan  9 16:09:01 2017 Nicolas Guerin
** Last update Wed Apr  5 01:20:55 2017 Nicolas
*/

#include "prototypes.h"

char	*my_strdup(char *src)
{
  int   i;
  char  *str;

  str = malloc(sizeof(char) * (my_strlen(src) + 1));
  i = 0;
  while (i < my_strlen(src))
    {
      str[i] = src[i];
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}
