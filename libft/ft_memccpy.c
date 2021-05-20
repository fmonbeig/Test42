/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:41:13 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/20 16:55:35 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst1;
	const unsigned char	*src1;

	dst1 = dst;
	src1 = src;
	while (src1 && n > 0)
	{
		if (*src1 == (unsigned char)c)
		{
			*dst1 = *src1;
			return (++dst1);
		}
		*dst1 = *src1;
		dst1++;
		src1++;
		n--;
	}
	return (0);
}
