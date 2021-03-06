/*
** my_exec.c for my_execv in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 17:05:58 2017 Nicolas
** Last update Sat Apr  8 22:58:01 2017 Nicolas
*/

#include "prototypes.h"

int	check_path(char **env)
{
  int   i;

  i = 0;
  while (env && env[i] != NULL)
    {
      if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
	  && env[i][3] == 'H' && env[i][4] == '=')
	return (i);
      i++;
    }
  return (84);
}

char	*change_path(char *env)
{
  char  *new_env;
  int   i;
  int   a;

  a = 0;
  i = 5;
  if ((new_env = malloc(sizeof(char) * (my_strlen(env) - 4))) == NULL)
    return (NULL);
  while (env && env[i] != '\0')
    {
      new_env[a] = env[i];
      a++;
      i++;
    }
  new_env[a] = '\0';
  return (new_env);
}

char	**get_new_path(char **env, char *buff)
{
  char	*env_rt;
  char	**tab;
  int	i;
  int	x;

  x = 0;
  if ((i = check_path(env)) == 84 ||
      (env_rt = change_path(env[i])) == NULL ||
      (tab = my_str_to_wordtab(env_rt, ':')) == NULL)
    return (NULL);
  while (tab && tab[x])
    {
      if ((tab[x] = my_realloc(tab[x], my_strlen(buff) + 2)) == NULL)
	return (NULL);
      my_strcat(tab[x], "/");
      my_strcat(tab[x], buff);
      x++;
    }
  return (tab);
}

char	*find_good_cmd(char **path)
{
  char	*cmd;
  int	i;

  i = 0;
  while (path && path[i])
    {
      if ((cmd = my_strdup(path[i])) == NULL)
	return (NULL);
      if ((access(cmd, F_OK)) != -1)
	return (cmd);
      i++;
    }
  return (NULL);
}

int	my_execve(char **av, char **env, t_point *st_rt)
{
  char	**tab;
  char	*cmd;

  if ((tab = get_new_path(env, av[0])) == NULL ||
      (av[0] == NULL))
    return (84);
  if ((cmd = find_good_cmd(tab)) == NULL)
    {
      if (my_strncmp("./", av[0], 2) != 0)
	return (84);
      else
	if ((find_if_exist((cmd = my_strdup(av[0])))) == 84)
	  return (84);
    }
  if ((st_rt->pid = fork()) == -1)
    return (84);
  if (wait_pid_exec(cmd, av, env, st_rt) == 84)
      return (84);
  return (0);
}
