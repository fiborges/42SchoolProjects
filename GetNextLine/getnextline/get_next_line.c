#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
# include <limits.h>

char	*ft_read(int fd, char *s)
{
	char	*str;
	int		size;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	size = 1;
	while (!ft_strchr(s, '\n') && size != 0)
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
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	get = ft_line(str);
	str = ft_new(str);
	return (get);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		file;
	int		file2;
	int		file3;
	file = open("teste.txt", O_RDONLY);
	file2 = open("teste2.txt", O_RDONLY);
	file3 = open("teste3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		printf("round ---------------------%d-----------------------------------------------------\n\n\n", i);
		line = get_next_line(file);
		printf("line [%02d]: %s \n", i, line);
		free(line);
		line = get_next_line(file2);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		line = get_next_line(file3);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(file);
	close(file2);
	close(file3);
	return (0);
}*/