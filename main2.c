/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:19:13 by user42            #+#    #+#             */
/*   Updated: 2020/10/07 13:43:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_strcpy(void)
{
	char dest[100];

	printf("\n\n\n!------ FT_STRCPY ------!\n");
	printf("\nft_strcpy: ret %s", ft_strcpy(dest, ""));
	printf("\nstrcpy: ret %s\n", strcpy(dest, ""));
	printf("\nft_strcpy: ret %s", ft_strcpy(dest, "toto"));
	printf("\nstrcpy: ret %s\n", strcpy(dest, "toto"));
	printf("\nft_strcpy: ret %s", ft_strcpy(dest, "0123456789"));
	printf("\nstrcpy: ret %s\n", strcpy(dest, "0123456789"));
}

void	test_read(void)
{
	char	buf[32];
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("\n\n\n!------ FT_READ ------!\n");
	printf("\nft_read: ret %zu\n", ft_read(-1, buf, 7));
	printf("ft_read errno %d", errno);
	printf("\nread: ret %zu\n", read(-1, buf, 7));
	printf("read errno %d\n", errno);
	printf("\nft_read: ret %zu\n", ft_read(42, buf, 7));
	printf("ft_read errno %d", errno);
	printf("\nread: ret %zu\n", read(42, buf, 7));
	printf("read errno %d\n", errno);
	printf("\nft_read: ret %zu\n", ft_read(fd, buf, 7));
	printf("ft_read errno %d | buff : %s", errno, buf);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	printf("\nread: ret %zu\n", read(fd, buf, 7));
	printf("read errno %d | buff : %s", errno, buf);
}

void	test_strdup(void)
{
	char *str;

	printf("\n\n\n!------ FT_STRDUP ------!\n");
	str = ft_strdup("hello");
	printf("\n%s\n\n", str);
}
