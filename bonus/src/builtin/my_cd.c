/*
** my_cd.c for my_cd in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Tue Apr  4 23:39:59 2017 Nicolas
** Last update Sun Apr  9 02:50:02 2017 Nicolas
*/

#include "prototypes.h"

int	check_home(char **env)
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

int	find_oldpwd(char **env)
{
  int	i;

  i = 0;
  while (env && env[i])
    {
      if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D'
	  && env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D'
	  && env[i][6] == '=')
	return (i);
      i++;
    }
  return (842);
}

char	*cd_oldpwd(char **env)
{
  int	i;
  char	*new_str;
  int	j;
  int	n;

  j = 0;
  if ((i = find_oldpwd(env)) == 842 ||
      (new_str = malloc(sizeof(char) * my_strlen(env[i]) + 1)) == NULL)
    return (NULL);
  n = find_pos_equal(env[i]);
    while (env && env[i] && env[i][n])
    {
      new_str[j] = env[i][n];
      j++;
      n++;
    }
  new_str[j] = '\0';
  return (new_str);
}

char	**my_cd(char **env, char **tab, char *cmd, t_point *st_rt)
{
  int	i;
  int	j;

  i = find_pwd(env);
  j = my_strlen_tab(env);
  if ((my_memcmp(tab[1], "~", 1) == 0))
    {
      if ((env = cd_home_exec(cmd, env)) == NULL)
	return (NULL);
    }
  else if ((my_memcmp(tab[1], "-", 1) == 0))
    {
      if ((cmd = cd_oldpwd(env)) == NULL)
	return (my_putstr("Not a directory.\n", 2, RED), env);
      if ((chdir(cmd)) == -1)
	return (my_putstr("Access denied :\n", 2, RED), env);
    }
  else if (chdir(tab[1]) == -1 && (st_rt->ret = 1) == 1)
    return (my_putstr(tab[1], 2, YELLOW),
	    my_putstr(": Not a directory.\n", 2, RED), env);
  if ((env = my_setenv(env, get_old_pwd(env[i]), j)) == NULL ||
      (env = change_pwd(env, tab[1])) == NULL)
    return (NULL);
  return (env);
}
