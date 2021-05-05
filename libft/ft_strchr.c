/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:15:10 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/02 17:56:02 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
  char *str;

  str = (char *)s;
  while (*str)
  {
    if (*str == (char)c)
      return (str);
    str++;
  }
  if (*str == (char)c)
    return (str);
  return (NULL);
}
