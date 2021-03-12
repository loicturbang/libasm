/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 08:56:00 by lturbang          #+#    #+#             */
/*   Updated: 2020/10/07 13:30:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_write_file(void)
{
	int fd;

	fd = open("test.txt", O_WRONLY);
	ft_write(fd, "hello", 5);
}

void	test_write(void)
{
	printf("!------ FT_WRITE ------!\n");
	printf("\nft_write: ret %zu\n", ft_write(1, "", 0));
	printf("\nwrite: ret %zu\n\n", write(1, "bon", 0));
	printf("\nft_write: ret %zu\n", ft_write(1, "bon", 3));
	printf("\nwrite: ret %zu\n\n", write(1, "bon", 3));
	printf("\nft_write: ret %zu\n", ft_write(1, "#c#s#p#x#X#e#f#g", 16));
	printf("\nwrite: ret %zu\n\n", write(1, "#c#s#p#x#X#e#f#g", 16));
	printf("\nft_write: ret %zu\n", ft_write(1, "the\0hidden", 10));
	printf("\nwrite: ret %zu\n\n", write(1, "the\0hidden", 10));
	printf("\nft_write: ret %zu\n", ft_write(-1, "bonjour", 7));
	printf("\nwrite: ret %zu\n\n", write(-1, "bonjour", 7));
	printf("\nft_write: ret %zu\n", ft_write(-1, "NULL", 4));
	printf("ft_write errno %d", errno);
	printf("\nwrite: ret %zu\n", write(-1, "NULL", 4));
	printf("write errno %d", errno);
	test_write_file();
}

void	test_strlen(void)
{
	printf("\n\n\n!------ FT_STRLEN ------!\n");
	printf("\nft_strlen: ret %zu", ft_strlen(""));
	printf("\nstrlen: ret %zu\n", strlen(""));
	printf("\nft_strlen: ret %zu", ft_strlen("bon"));
	printf("\nstrlen: ret %zu\n", strlen("bon"));
	printf("\nft_strlen: ret %zu", ft_strlen("asdfasdf''///##!!@"));
	printf("\nstrlen: ret %zu\n", strlen("asdfasdf''///##!!@"));
	printf("\nft_strlen: ret %zu", ft_strlen("the\0hidden"));
	printf("\nstrlen: ret %zu\n", strlen("the\0hidden"));
	printf("\nft_strlen: ret %zu", ft_strlen("Lorem ipsum dolor sit \
	amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam \
	a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor \
	mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae \
rutrum nisi felis sed purus."));
	printf("\nstrlen: ret %zu\n", strlen("Lorem ipsum dolor sit \
	amet, consectetur adipiscing elit. Sed in malesuada purus. Etiam \
	a scelerisque massa. Ut non euismod elit. Aliquam bibendum dolor \
	mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae \
rutrum nisi felis sed purus."));
}

void	test_strcmp(void)
{
	printf("\n\n\n!------ FT_STRCMP ------!\n");
	printf("\nft_strcmp: ret %d", ft_strcmp("bon", ""));
	printf("\nstrcmp: ret %d\n", strcmp("bon", ""));
	printf("\nft_strcmp: ret %d", ft_strcmp("", "asdf"));
	printf("\nstrcmp: ret %d\n", strcmp("", "asdf"));
	printf("\nft_strcmp: ret %d", ft_strcmp("bon", "bo"));
	printf("\nstrcmp: ret %d\n", strcmp("bon", "bo"));
	printf("\nft_strcmp: ret %d", ft_strcmp("bonjour", "onjour"));
	printf("\nstrcmp: ret %d\n", strcmp("bonjour", "onjour"));
	printf("\nft_strcmp: ret %d", ft_strcmp("bon", "bon"));
	printf("\nstrcmp: ret %d\n", strcmp("bon", "bon"));
}

int		main(void)
{
	test_write();
	test_strlen();
	test_strcmp();
	test_strcpy();
	test_read();
	test_strdup();
	return (0);
}
