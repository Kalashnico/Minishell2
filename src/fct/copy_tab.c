/*
** copy_tab.c for copy_tab in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  9 01:06:18 2017 Nicolas
** Last update Sun Apr  9 01:09:03 2017 Nicolas
*/

#include "prototypes.h"

char	**copy_tab(char **tab)
{
  char	**new_tab;
  int	i;

  i = 0;
  if ((new_tab = malloc(sizeof(char *) * 1024)) == NULL)
    return (NULL);
  while (tab && tab[i])
    {
      if ((new_tab[i] = my_strdup(tab[i])) == NULL)
	return (NULL);
      i++;
    }
  new_tab[i] = NULL;
  return (new_tab);
}
