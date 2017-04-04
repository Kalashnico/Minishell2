/*
** free_tab.c for free_tab in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/fct
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 00:10:13 2017 Nicolas
** Last update Wed Apr  5 01:21:12 2017 Nicolas
*/

#include "prototypes.h"

void	free_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab && tab[i])
    free(tab[i++]);
  free(tab[i]);
}
