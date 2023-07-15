/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:31:45 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/03/23 17:00:40 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*res;
	void	*temp;

	if (f == 0 || del == 0)
		return (0);
	newlst = 0;
	while (lst)
	{
		temp = (*f)(lst->content);
		res = ft_lstnew(temp);
		if (res == 0)
		{
			ft_lstclear(&newlst, del);
			free(temp);
			return (0);
		}
		ft_lstadd_back(&newlst, res);
		lst = lst->next;
	}
	return (newlst);
}
