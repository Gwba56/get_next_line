/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:43:34 by gbarach-          #+#    #+#             */
/*   Updated: 2018/12/12 14:23:02 by gbarach-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char*))
{
	if (s && f)
	{
		while (*s)
			f(s++);
	}
}
