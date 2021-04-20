/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tripple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:23:34 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_strjoin_tripple(char *s1, char *s2, char *s3)
{
	char *res;
	char *tmp;

	res = ft_strjoin(s1, s2);
	tmp = res;
	res = ft_strjoin(res, s3);
	(tmp) ? free(tmp) : NULL;
	return (res);
}
