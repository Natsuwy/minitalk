/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:15:49 by michen            #+#    #+#             */
/*   Updated: 2024/07/27 17:53:52 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_string(char const c)
{
	char	*str;

	str = malloc(2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

char	*ft_strjoin_bis(char *s1, char const s2)
{
	int		len;
	int		i;
	char	*str;

	if (s1 == NULL)
		return (ft_string(s2));
	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = s2;
	str[i] = '\0';
	free(s1);
	return (str);
}
