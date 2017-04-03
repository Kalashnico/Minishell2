/*
** my_cd.c for my_cd in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 01:59:43 2017 Nicolas
** Last update Sun Apr  2 18:36:55 2017 Nicolas
*/

#include "prototypes.h"

int	my_cd(char *cmd)
{
  char	**tab;

  tab = my_str_to_wordtab(cmd, ' ');
  if (chdir(tab[1]) == -1)
    return (my_putstr("Access denied\n", 2), 84);
  return (0);
}
