/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:03:18 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/17 16:50:45 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordnumber(char const *s, char c)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			y++;
		i++;
	}
	return (y);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		y;
	int		z;
	int		words;

	if (!s)
		return (0);
	words = wordnumber(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	y = 0;
	while (s[i] && y < words)
	{
		while (s[i] == c && s[i])
			i++;
		z = i;
		while (s[i] != c && s[i])
			i++;
		str[y++] = ft_substr(s, z, i - z);
	}
	str[y] = NULL;
	return (str);
}

// char	**str;
// 	int		i;
// 	int		y;
// 	int		z;
// 	int		counter;

// 	str = wordnumber(s, c);
// 	i = -1;
// 	y = 0;
// 	z = 0;
// 	counter = 0;
// 	if (!s)
// 		return (0);
// 	while (s[++i])
// 	{
// 		if (s[i] != c)
// 		{
// 			counter++;
// 			if (s[i + 1] == c || s[i + 1] == '\0')
// 			{
// 				str[y] = malloc(counter + 1);
// 				if (!str)
// 					return (0);
// 				i -= (counter - 1);
// 				counter += i;
// 				while (i < counter)
// 					str[y][z++] = s[i++];
// 				str[y++][z] = '\0';
// 				z = 0;
// 				counter = 0;
// 				i--;
// 			}
// 		}
// 	}
// 	str[y] = NULL;
// 	return (str);
// }