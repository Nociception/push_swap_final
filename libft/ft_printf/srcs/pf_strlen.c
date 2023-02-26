/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:46:57 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:47:07 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	pf_strlen(char *str)
{
	long int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}