#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next != 0)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
