/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:25:09 by yfuks             #+#    #+#             */
/*   Updated: 2014/11/17 17:30:46 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		i2;
	char		*result;

	i = start;
	i2 = 0;
	if (s == NULL || len == 0 || s[start] == '\0')
		return (NULL);
	result = ft_strnew(len + 1);
	while (i2 < len && s[i])
	{
		result[i2] = (char)s[i];
		i++;
		i2++;
	}
	result[i2] = '\0';
	return (ft_strdup(result));
}
