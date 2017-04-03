/*
** my_realloc.c for my_realloc in /home/guerin_n/Epitech/CPE/CPE_2016_matchstick/src/fct
** 
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
** 
** Started on  Fri Feb 24 16:51:09 2017 Nicolas Guerin
** Last update Mon Apr  3 17:43:50 2017 Nicolas
*/

#include "prototypes.h"

char	*my_realloc(char *buff, int nb)
{
  char  *buf2;
  int   i;

  i = 0;
  if ((buf2 = malloc(sizeof(char) * (my_strlen(buff) + nb + 1))) == NULL)
    return (NULL);
  if (buff == NULL)
    {
      buf2[0] = '\0';
      return (buf2);
    }
  while (buff[i])
    {
      buf2[i] = buff[i];
      i++;
    }
  buf2[i] = '\0';
  return (buf2);
}
