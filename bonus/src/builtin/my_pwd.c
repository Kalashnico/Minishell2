/*
** my_pwd.c for my_pwd in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 03:30:42 2017 Nicolas
** Last update Thu Apr  6 14:51:03 2017 Nicolas
*/

#include "prototypes.h"

int	find_pwd(char **env)
{
  int	i;

  i = 0;
  while (env && env[i])
    {
      if (env[i][0] == 'P' && env[i][1] == 'W'
	  && env[i][2] == 'D' && env[i][3] == '=')
	return (i);
      i++;
    }
  return (0);
}

char	*get_old_pwd(char *str)
{
  char	*new_str;
  int	i;
  int	j;

  i = 0;
  j = 10;
  if ((new_str = malloc(sizeof(char) * my_strlen(str) + 11)) == NULL)
    return (NULL);
  my_memset(new_str, '\0', (my_strlen(str) + 11));
  my_strcat(new_str, "setenv OLD");
  while (str && str[i])
    {
      new_str[j] = str[i];
      if (str[i] == '=')
	new_str[j] = ' ';
      i++;
      j++;
    }
  new_str[j] = '\0';
  return (new_str);
}

char	*get_pwd(char *str)
{
  int	i;
  int	j;
  char	*new_str;

  j = 0;
  i = find_pos_equal(str);
  if ((new_str = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str && str[i])
    {
      new_str[j] = str[i];
      i++;
      j++;
    }
  new_str[j] = '\0';
  return (new_str);
}

char	*get_new_pwd(char *str, char *cmd)
{
  char	*old_pwd;
  char	*new_pwd;

  if ((old_pwd = get_old_pwd(str)) == NULL ||
      (new_pwd = malloc(sizeof(char) * my_strlen(str)
			+ my_strlen(cmd) + 3)) == NULL)
    return (NULL);
  my_strcat(new_pwd, old_pwd);
  my_strcat(new_pwd, "/");
  my_strcat(new_pwd, cmd);
  return (new_pwd);
}

char	**change_pwd(char **env, char *cmd)
{
  int	i;

  i = find_pwd(env);
  if ((env[i] = my_realloc(env[i], (my_strlen(cmd) + 2))) == NULL)
    return (NULL);
  my_strcat(env[i], "/");
  my_strcat(env[i], cmd);
  return (env);
}
