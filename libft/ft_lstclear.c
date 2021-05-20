/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:52:06 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/10 12:33:42 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_lstdelone.c"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;

    if (!lst)
        return;

    if (del)
    {
        while (*lst)
        {
            temp = (*lst)->next;
            ft_lstdelone(*lst, del);
            *lst = temp;
        }
    }
}