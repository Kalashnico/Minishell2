/*
** my_cd.c for my_cd in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Tue Apr  4 23:39:59 2017 Nicolas
** Last update Wed Apr  5 20:20:08 2017 Nicolas
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
  return (0);
}

char	*cd_oldpwd(char **env)
{
  int	i;
  char	*new_str;
  int	j;
  int	n;
    
  i = find_oldpwd(env);
  j = 0;
  n = (i = 0) ? 3 : 7;
  if (i == 0)
    i = find_pwd(env);
  if ((new_str = malloc(sizeof(char) * my_strlen(env[i]) + 1)) == NULL)
    return (NULL);
  while (env && env[i])
    {
      new_str[j] = env[i][n];
      j++;
      n++;
    }
  new_str[j] = '\0';
  return (new_str);
}

char	**my_cd(char **env, char *cmd)
{
  char	**tab;
  int	i;

  i = find_pwd(env);
  if ((tab = my_str_to_wordtab(cmd, ' ')) == NULL)
    return (NULL);
  if ((my_memcmp(tab[1], "~", 1) == 0))
    {
      if ((cmd = my_cd_home(env)) == NULL)
	return (NULL);
      if ((chdir(cmd)) == -1)
	return (my_putstr("Access denied : ", 2), env);
    }
  else if ((my_memcmp(tab[1], "-", 1) == 0))
    {
      i = find_oldpwd(env);
      if ((chdir(cd_oldpwd(env))) == -1)
	return (my_putstr("Access denied : ", 2), env);
    }
  else if (chdir(tab[1]) == -1)
    return (my_putstr("Access denied !\n", 2), env);
  if ((env = my_setenv(env, get_old_pwd(env[i]))) == NULL ||
      (env = change_pwd(env, tab[1])) == NULL)
    return (NULL);
  return (env);
}
