/*
** my_setenv.c for my_setenv in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Mon Apr  3 15:28:46 2017 Nicolas
** Last update Wed Apr  5 23:22:34 2017 Nicolas
*/

#include "prototypes.h"

char	**env_tab(char **env)
{
  int	i;
  char	**tab;

  i = my_strlen_tab(env);
  if ((tab = malloc(sizeof(char *) * (i + 3))) == NULL)
    return (NULL);
  i = 0;
  while (env && env[i])
    {
      if ((tab[i] = my_strdup(env[i])) == NULL)
	return (NULL);
      i++;
    }
  tab[i + 2] = NULL;
  return (tab);
}

int	check_value_exist_env(char **env, char *buff)
{
  int	i;

  i = 0;
  while (env && env[i])
    {
      if ((my_memcmp(buff, env[i], my_strlen(buff))) == 0)
	return (i);
      i++;
    }
  return (0);
}

char	**overwrite_setenv(char **env, char **tab, int i)
{
  my_memset(env[i], '\0', my_strlen(env[i]) + 1);
  if ((env[i] = my_realloc(env[i], my_strlen(tab[1])
			   + my_strlen(tab[2]) + 1)) == NULL)
    return (NULL);
  my_strcpy(env[i], tab[1]);
  my_strcat(env[i], "=");
  my_strcat(env[i], tab[2]);
  return (env);
}

char	**my_setenv(char **env, char *buff)
{
  int	i;
  char	*new_str;
  char	**tab;
  char	**new_tab;

  if ((tab = my_str_to_wordtab(buff, ' ')) == NULL)
    return (NULL);
  if (tab[1] == NULL)
    return (my_env(env), env);
  if ((i = check_value_exist_env(env, tab[1])) != 0)
    return (overwrite_setenv(env, tab, i));
  i = my_strlen_tab(env);
  if ((new_tab = env_tab(env)) == NULL ||
      (new_str =
       malloc(sizeof(char) * (my_strlen(tab[1]) + my_strlen(tab[2]) + 3)))
      == NULL)
    return (NULL);
  my_strcpy(new_str, tab[1]);
  my_strcat(new_str, "=");
  my_strcat(new_str, tab[2]);
  if ((new_tab[i] = my_strdup(new_str)) == NULL)
    return (NULL);
  i++;
  new_tab[i] = NULL;
  return (new_tab);
}
