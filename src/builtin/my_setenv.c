/*
** my_setenv.c for my_setenv in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Mon Apr  3 15:28:46 2017 Nicolas
** Last update Mon Apr  3 18:35:39 2017 Nicolas
*/

#include "prototypes.h"

int	my_strlen_tab(char **env)
{
  int	i;

  i = 0;
  while (env && env[i])
      i++;
  return (i);
}

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

char	**my_setenv(char **env, char *buff)
{
  int	i;
  char	*new_str;
  char	**tab;
  char	**new_tab;

  if ((tab = my_str_to_wordtab(buff, ' ')) == NULL)
    return (NULL);
  i = my_strlen_tab(env);
  if ((new_tab = env_tab(env)) == NULL ||
      (new_str = malloc(sizeof(char) * (my_strlen(tab[1]) + my_strlen(tab[2]) + 3))) == NULL)
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
