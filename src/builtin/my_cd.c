/*
** my_cd.c for my_cd in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 01:59:43 2017 Nicolas
** Last update Tue Apr  4 04:45:26 2017 Nicolas
*/

#include "prototypes.h"

int	my_cd(char *cmd)
{
  char	**tab;

  if ((tab = my_str_to_wordtab(cmd, ' ')) == NULL)
    return (84);
  if (chdir(tab[1]) == -1)
    return (my_putstr("Access denied : ", 2), 84);
  return (0);
}
