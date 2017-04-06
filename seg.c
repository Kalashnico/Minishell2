#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while(str[i])
    i++;
  return (i);
}

int	main()
{
  int	i;

  i = my_strlen(NULL);
}
