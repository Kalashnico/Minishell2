/*
** prototypes.h for prototypes in /home/guerin_n/Epitech/Shell/PSU_2016_minishell1
** 
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
** 
** Started on  Mon Jan  9 15:46:26 2017 Nicolas Guerin
** Last update Mon Apr  3 14:20:17 2017 Nicolas
*/

#ifndef PROTOTYPES_H_
# define PROTOTYPES_H_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void	my_putchar(char c, int fd);
void	my_putstr(char *str, int fd);
void	my_strcat(char *s1, char *s2);
int	my_strlen(char *str);
int	check_path(char **av);
int	my_env(char **env);
int	my_cd(char *path);
int	show_tab(char **tab);
int	check_n(char *str);
int	my_execve(char **av, char **env);
int	check_if_built_exist(char *buff);
int	builtin(char *buff, char **env);
int	my_memcmp(void *s1, void *s2, size_t n);
char	*my_exit(char *str);
char	*my_realloc(char *buff, int nb);
char	*boucle_gnl(char *line, char *buff, int ret, int i);
char	*boucle_else_gnl(char *line, char *buff, int ret, int fd);
char	*get_next_line(const int fd);
char	*my_strdup_gnl(char *src);
char	*my_strdup(char *src);
char	*my_strcpy(char *dest, char *src);
char	*change_path(char *env);
char	**find_env(char **env, char *buff);
char	**get_new_path(char **env, char *buff);
char	**my_str_to_wordtab(char *str, char c);

#endif /* !PROTOTYPES_H_ */
