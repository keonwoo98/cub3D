/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:47:37 by keokim            #+#    #+#             */
/*   Updated: 2021/05/04 16:09:13 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc_src;
	unsigned char	stop;

	uc_src = (unsigned char *)src;
	stop = (char)c;
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = uc_src[i];
		if (uc_src[i] == stop)
			return (dst + (i + 1));
		i++;
	}
	return (0);
}
