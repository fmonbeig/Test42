/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:38:27 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/11 11:03:39 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *newlist;
    t_list *add;

    newlist = NULL;
    while(lst && f)
    {
        add = ft_lstnew(f(lst->content));
        ft_lstadd_back(&newlist, add);
        lst = lst->next;
    }
    return (newlist);
}