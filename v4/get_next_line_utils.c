#include "get_next_line.h"

static int	ft_max_min_neg_check(int *nb, int *count)
{
	if (*nb == 2147483647)
		return ((*count = write(1, "2147483647", 10)));
	if (*nb == -2147483648)
		return ((*count = write(1, "-2147483648", 11)));
	if (*nb < 0)
	{
		*count = write(1, "-", 1);
		if (*count == -1)
			return (-1);
		*nb *= -1;
	}
	return (1);
}

static int	ft_show_nbr(int *count, int *i, char *digit_buffer)
{
	int	result;

	while (digit_buffer[*i] != '\0')
	{
		result = write(1, &digit_buffer[(*i)--], 1);
		if (result == -1)
			return (-1);
		*count += result;
	}
	return (*count);
}

int	ft_putnbr(int nb)
{
	int		i;
	int		count;
	char	digit_buffer[12];

	count = 0;
	if ((ft_max_min_neg_check(&nb, &count)) != 1)
		return (count);
	digit_buffer[0] = '\0';
	i = 1;
	while (nb > 9)
	{
		digit_buffer[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	digit_buffer[i] = nb + '0';
	if (ft_show_nbr(&count, &i, digit_buffer) == -1)
		return (-1);
	return (count);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char	*ft_strdup(char *src)
{
	int		length;
	char	*copy;
	int		i;

	i = 0;
	length = ft_strlen(src);
	copy = malloc((length + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	copy[length] = '\0';
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
    return (copy);
}

void	*ft_memchr(const void *str, int number, size_t size)
{
	unsigned char	*ptr_str;
	size_t			i;

	ptr_str = (unsigned char *)str;
	i = 0;
	while (i < size)
	{
		if (ptr_str[i] == (unsigned char)number)
			return (&ptr_str[i]);
		i++;
	}
	return (NULL);
}
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if (i <= start || len == 0)
		return (ft_strdup(""));
	if (len > (i - start))
		len = i - start;
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	i = 0;
	while (str[start] && i < len)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	return (result);
}


