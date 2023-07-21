# define OPENMAX 49152
#  define BUFFER_SIZE 5

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;
	char	*temp;

	i = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == 0)
		return (0);
	temp = res;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	char	*a;
	char	b;
	int		i;

	if (str == 0)
		return (0);
	a = (char *)str;
	b = (char)c;
	i = 0;
	while (a[i] != b)
	{
		if (a[i] == '\0')
			return (0);
		i++;
	}
	return (&a[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_len;
	char		*res;
	size_t		s2_len;

	if (s1 == 0 || s2 == 0)
	{
		res = (char *)malloc(sizeof(char) + 1);
		res[0] = 0;
		return (res);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (res == 0)
		return (0);
	ft_memcpy(res, s1, s1_len);
	ft_memcpy(res + s1_len, s2, s2_len);
	res[s1_len + s2_len] = 0;
	return (res);
}
static char	*ft_free(char **add)
{
	free(*add);
	*add = 0;
	return (0);
}

static char	*ft_save(char *add)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!ft_strchr(add, '\n'))
		return (ft_free(&add));
	if (add[0] == 0)
		return (0);
	while (add[i] != '\0' && add[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (ft_strlen(add) - i) + 1);
	if (s == 0)
		return (ft_free(&add));
	i++;
	while (add[i])
		s[j++] = add[i++];
	s[j] = '\0';
	ft_free(&add);
	return (s);
}

static char	*ft_extract(char *add)
{
	int		i;
	char	*result;

	i = 0;
	while (add[i] != '\n' && add[i] != '\0')
		i++;
	if (add[i] == '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (add[i] != '\0')
	{
		result[i] = add[i];
		if (add[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*ft_add(int fd, char *buff, char *add)
{
	int		byte;
	char	*temp;

	if (add == 0)
		add = ft_strdup("");
	byte = 1;
	while (!ft_strchr(add, '\n') && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (add == 0)
			add = ft_strdup("");
		if ((byte == -1) || (byte == 0 && add[0] == 0))
		{
			ft_free(&add);
			free(buff);
			return (0);
		}
		buff[byte] = '\0';
		temp = add;
		add = ft_strjoin(add, buff);
		free(temp);
	}
	free(buff);
	return (add);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*add[OPENMAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == 0)
	{
		if (add[fd])
			return (ft_free(&add[fd]));
	}
	add[fd] = ft_add(fd, buff, add[fd]);
	if (add[fd] == 0)
		return (0);
	line = ft_extract(add[fd]);
	if (line == 0)
	{
		ft_free(&add[fd]);
		return (0);
	}
	add[fd] = ft_save(add[fd]);
	return (line);
}


#include <stdio.h>

int main() 
{
	char* line;
	int	fd;

	fd = open("test.txt", O_RDONLY);

	line = get_next_line(fd);	
    printf("%s", line);	
 				

	line = get_next_line(fd);	
    printf("%s", line);	

    return (0);
}