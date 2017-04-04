/*
** my_cd.c for my_cd in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Tue Apr  4 23:39:59 2017 Nicolas
** Last update Tue Apr  4 23:55:44 2017 Nicolas
*/

#include "prototypes.h"

int     check_home(char **env)
{
  int   i;

  i = 0;
  while (env && env[i])
    {
      if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M'
	  && env[i][3] == 'E' && env[i][4] == '=')
	return (i);
      i++;
    }
  return (84);
}

char	*my_cd_home(char **env)
{
  char  *new_path;
  int   i;

  if ((i = check_home(env)) == 84 ||
      (new_path = change_path(env[i])) == NULL)
    return (NULL);
  return (new_path);
}

char	**my_cd(char **env, char *cmd)
{
  char	**tab;

  if ((tab = my_str_to_wordtab(cmd, ' ')) == NULL)
    return (NULL);
  if ((my_memcmp(tab[1], "~", 1) == 0))
    {
      if ((cmd = my_cd_home(env)) == NULL)
	return (NULL);
      if ((chdir(cmd)) == -1)
	return (my_putstr("Access denied : ", 2), NULL);
    }  
  else if (chdir(tab[1]) == -1)
    return (my_putstr("Access defied : ", 2), NULL);
  return (env);
}
