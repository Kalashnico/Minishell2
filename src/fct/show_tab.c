/*
** show_tab.cs for show_tab in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src/fct
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 01:39:49 2017 Nicolas
** Last update Wed Apr  5 20:22:25 2017 Nicolas
*/

#include "prototypes.h"

int	show_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (84);
  while (tab[i])
    {
      my_putstr(tab[i++], 1);
      my_putchar('\n', 1);
    }
  return (0);
}
