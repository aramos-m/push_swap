/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:04:25 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/13 13:35:51 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	toupper_even1(unsigned int i, char c)
{
	if (i % 2 == 0)
		return(ft_toupper(c));
	return (c);
}

void	toupper_even2(unsigned int i, char *s)
{
	if (i % 2 == 0)
		*s = ft_toupper(*s);
	return ;
}

int main(void)
{
	/*MANDATORY PART*/
	printf("Esta es la función ISALPHA:\n");
	printf("%d\n", ft_isalpha(' '));
	printf("%d\n", isalpha(' '));
	printf("\n");

	printf("Esta es la función ISDIGITA:\n");
	printf("%d\n", ft_isdigit('8'));
	printf("%d\n", isdigit('8'));
	printf("\n");

	printf("Esta es la función ISALNUM:\n");
	printf("%d\n", ft_isalnum(128));
	printf("%d\n", isalnum(128));
	printf("\n");

	printf("Esta es la función ISASCII:\n");
	printf("%d\n", ft_isascii(128));
	printf("%d\n", isascii(128));
	printf("\n");
	
	printf("Esta es la función ISPRINT:\n");
	printf("%d\n", ft_isprint('\t'));
	printf("%d\n", isprint('\t'));
	printf("\n");

	printf("Esta es la función STRLEN:\n");
	char	s[] = " ";
	printf("%d\n", ft_strlen(s));
	printf("%lu\n", strlen(s));
	printf("\n");

	printf("Esta es la función MEMSET:\n");
	char	str[10] = "Hola Ana";
	int		c = ' ';
	size_t	n = 2;
	printf("%s\n", ft_memset(str, c, n));
	printf("%s\n", memset(str, c, n));
	printf("\n");

	printf("Esta es la función BZERO:\n");
	char	s[8] = "Hola Ana";
	size_t	n = 1;
	bzero(s, n);
	printf("%s\n", s);
	ft_bzero(s,n);
	printf("%s\n", s);
	printf("\n");

	printf("Esta es la función MEMCPY:\n");
	char	src[] = "123456789";
	char	dest[] = "Hola Ana";
	int		n = 4;
	printf("%s\n", ft_memcpy(dest, src, n));
	printf("%s\n", memcpy(dest, src, n));
	printf("\n");

	printf("Esta es la función MEMMOVE:\n");
	char	dest[] = "Hola Ana";
	char	src[] = "123456789";
	int		n = 4;
	printf("%s\n", ft_memmove(dest, src, n));
	printf("%s\n", memmove(dest, src, n));
	printf("\n");i

	printf("Esta es la función STRLCPY:\n");
	char	dst1[] = "Hola";
	char	src1[] = "Algo";
	char	dst2[] = "Hola";
	char	src2 [] = "Algo";
	printf("%lu\n", ft_strlcpy(dst1, src1, 5));
	printf("%lu\n", strlcpy(dst2, src2, 5));
	printf("\n");

	printf("Esta es la función STRLCAT:\n");
	char	dst1[20] = "Hola";
	char	src1[] = "Algo";
	char	dst2[20] = "Hola";
	char	src2[] = "Algo";
	printf("%lu %s\n", ft_strlcat(dst1, src1, 8), dst1);
	printf("%lu %s\n", strlcat(dst2, src2, 8), dst2);
	printf("\n");

	printf("Esta es la función TOUPPER:\n");
	printf("%d\n", toupper('a'));
	printf("%d\n", ft_toupper('a'));
	printf("\n");

	printf("Esta es la función TOLOWER:\n");
	printf("%d\n", tolower('A'));
	printf("%d\n", ft_tolower('A'));
	printf("\n");

	printf("Esta es la función STRCHR:\n");
	char	str[] = "Hello, World!";
	int		c = 'I';
	printf("%s\n", strchr(str, c));
	printf("%s\n", ft_strchr(str, c));
	printf("\n");

	printf("Esta es la función STRRCHR:\n");
	char	str[] = "Hello, World!";
	int		c = 'e';
	printf("%s\n", strrchr(str, c));
	printf("%s\n", ft_strrchr(str, c));
	printf("\n");

	printf("Esta es la función STRNCMP:\n");
	const char	str1[] = "}ello, World!";
	const char	str2[] = "Hello, World!";
	size_t		n = 5;
	printf("%d\n", strncmp(str1, str2, n));
	printf("%d\n", ft_strncmp(str1, str2, n));
	printf("\n");

	printf("Esta es la función MEMCHR:\n");
	const char	s[] = "Hello, World!";
	int			c = 'o';
	size_t		n = 5;
	printf("%s\n", ft_memchr(s, c, n));
	printf("%s\n", memchr(s, c, n));
	printf("\n");

	printf("Esta es la función MEMCMP:\n");
	const char	str1[] = "H42lo, World!";
	const char	str2[] = "Hello, World!";
	size_t		n = 5;
	printf("%d\n", memcmp(str1, str2, n));
	printf("%d\n", ft_memcmp(str1, str2, n));
	printf("\n");

	printf("Esta es la función STRNSTR:\n");
	const char	*haystack = "Hola, ¿que tal?";
	const char	*needle = "que";
	int			len = 8;
	printf("%s\n", strnstr(haystack, needle, len));
	printf("%s\n", ft_strnstr(haystack, needle, len));
	printf("\n");

	printf("Esta es la función ATOI:\n");
	char	str[] = "-1234a";
	printf("%d\n", atoi(str));
	printf("%d", ft_atoi(str));
	printf("\n");

	printf("Esta es la función CALLOC:\n");
	size_t	count = 5;
	size_t	size = 2;
	printf("%s\n", calloc(count, size));
	printf("%s\n", ft_calloc(count, size));
	printf("\n");

	printf("Esta es la función STRDUP:\n");
	char 	DD[] = "Hola";
	char	*EE;
	char	*FF;
	EE = ft_strdup(DD);
	FF = strdup(DD);
	printf("%s\n", EE);
	printf("%s\n", FF);
	free(EE);
	free(FF);
	printf("\n");

	printf("Esta es la función SUBSTR:\n");
	char const		*s = "Hola, ¿que tal?";
	unsigned int	start = 20;
	size_t			len = 5;
	printf("%s\n", ft_substr(s, start, len));
	printf("\n");

	printf("Esta es la función STRJOIN:\n");
	char const	*s1 = "Supercalifragilistico";
	char const	*s2 = "expialidoso";
	printf("%s\n", ft_strjoin(s1, s2));
	printf("\n");

	printf("Esta es la función SPLIT:\n");
	char	s[] = "Hola me llamo Ana";
	char	c = ' ';
	char	**result = ft_split(s, c);

	int		i = 0;
	while (result[i])
	{
		printf("Fila %d: %s\n", i + 1, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	printf("\n");

	printf("Esta es la función ITOA:\n");
	int	n = -12345;
	printf("%s\n", ft_itoa(n));
	printf("\n");

	printf("Esta es la función STRMAPI:\n");
	char	*s = "hola soy ana";
	char	*result;
	result = ft_strmapi(s, &toupper_even1);
	printf("%s\n", result);
	printf("\n");

	printf("Esta es la función STRITERI:\n");
	char	*s = "hola soy ana";
	printf("%s\n", ft_striteri(s, &toupper_even2));
	printf("\n");

	printf("Esta es la función PUTCHAR_FD:\n");
	ft_putstr_fd('A', 1);
	printf("\n\n");

	printf("Esta es la función PUTSTR_FD:\n");
	int	fd;
	fd = open("putstr_test.txt", O_WRONLY | O_CREAT, 0600);
	ft_putstr_fd("Hola, soy Ana", fd);
	close(fd);
	printf("\n\n");

	printf("Esta es la función PUTENDL_FD:\n");
	ft_putendl_fd("Hola, soy Ana", 1);
	printf("\n\n");

	printf("Esta es la función PUTNBR_FD:\n");
	ft_putnbr_fd(-456, 1);
	printf("\n\n");
}
