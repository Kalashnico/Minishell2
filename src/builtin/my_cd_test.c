/*
** my_cd.c for my_cd in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 01:59:43 2017 Nicolas
** Last update Wed Apr  5 01:22:40 2017 Nicolas
*/

#include "prototypes.h"

int	check_home(char **env)
{
  int	i;

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

int	check_pwd(char **env)
{
  int	i;

  i = 0;
  while (env && env[i])
    {
      if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D'
	  && env[i][3] == '=')
	return (i);
      i++;
    }
  return (84);
}

char	*my_cd_oldpath(char **env)
{
  char	*new_path;
  int	i;

  if ((i = check_pwd(env)) == 84 ||
      (new_path = change_path_cd(env[i])) == NULL)
    return (NULL);
  return (new_path);
}

char	*change_path_cd(char *env)
{
  char  *new_env;
  int   i;
  int   a;

  a = 0;
  i = 4;
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

char	**my_cd(char **env, char *cmd)
{
  char	**tab;
  char	*old_path;
  char	*new_path;
  char	*path;
  char	*temp;
  int	i;

  if ((tab = my_str_to_wordtab(cmd, ' ')) == NULL ||
      (i = check_pwd(env)) == 84 ||
      (path = malloc(sizeof(char) *
		     my_strlen(tab[1]) + my_strlen(env[i]))) == NULL ||
      (old_path = malloc(sizeof(char) * (my_strlen(env[i] + 15)))) == NULL)
    return (NULL);
  temp = change_path_cd(env[i]);
  my_strcat(path, temp);
  my_strcat(path, "/");
  my_strcat(path, tab[1]);
  my_strcat(old_path, "setenv OLDPWD ");
  my_strcat(old_path, my_cd_oldpath(env));
  if ((my_memcmp(tab[1], "~", 1) == 0))
    {
      if ((cmd = my_cd_home(env)) == NULL)
	return (NULL);
      if ((chdir(cmd)) == -1)
	return (my_putstr("Access denied : ", 2), NULL);
    }
  else if (chdir(tab[1]) == -1)
    return (my_putstr("Access denied : ", 2), NULL);
  if ((new_path = malloc(sizeof(char) * (my_strlen(path) + 12))) == NULL ||
      (env = my_unsetenv(env, "OLDPWD")) == NULL)
    return (NULL);
  my_strcat(new_path, "setenv PWD ");
  my_strcat(new_path, path);
  if ((env = my_setenv(env, new_path)) == NULL ||
      (env = my_unsetenv(env, "OLDPWD")) == NULL ||
      (env = my_setenv(env, old_path)) == NULL)
    return (NULL);
  return (env);
}
