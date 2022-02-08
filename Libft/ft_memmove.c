/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:09:47 by keokim            #+#    #+#             */
/*   Updated: 2021/05/10 12:12:56 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;

	if (dst == src || !len)
		return (dst);
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	if (dst < src)
		while (len--)
			*uc_dst++ = *uc_src++;
	else
		while (len--)
			*(uc_dst + len) = *(uc_src + len);
	return (dst);
}
