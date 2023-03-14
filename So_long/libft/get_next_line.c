#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

char	*ft_read(int fd, char *s)
{
	char	*str;
	int		size;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	size = 1;
	while (!ft_strchr1(s, '\n') && size != 0)
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size == -1)
		{
			free(str);
			return (NULL);
		}
		str[size] = '\0';
		s = ft_strjoin(s, str);
	}
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*get;
	static char	*str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	get = ft_line(str[fd]);
	str[fd] = ft_new(str[fd]);
	return (get);
}

/*int	main(void)
{
	char	*str;
    char    *str1;
    char    *str2;
	int		i;
	int		file1;
	int		file2;
	int		file3;

	file1 = open("teste.txt", O_RDONLY);
	file2 = open("teste2.txt", O_RDONLY);
	file3 = open("teste3.txt", O_RDONLY);

	i = 1;
	while (i < 7)
	{
		printf("round ---------------------%d-----------------------------------------------------\n\n\n", i);
		str = get_next_line(file1);
		printf("line [%02d]: %s\n", i, str);
		free(str);
		str1 = get_next_line(file2);
		printf("line [%02d]: %s\n", i, str1);
		free(str1);
		str2 = get_next_line(file3);
		printf("line [%02d]: %s\n", i, str2);
		free(str2);
		i++;
	}
	close(file1);
	close(file2);
	close(file3);
	return (0);
}*/