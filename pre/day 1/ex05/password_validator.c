/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:19:20 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 16:50:27 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

bool	check_chars(const char *passwd)
{
	int		i;
	bool	checks[3] = {false, false, false};

	i = 0;
	while (passwd[i] != '\0')
	{
		if (passwd[i] >= 'A' && passwd[i] <= 'Z')
			checks[0] = true;
		else if (passwd[i] >= 'a' && passwd[i] <= 'z')
			checks[1] = true;
		else if (passwd[i] >= '0' && passwd[i] <= '9')
			checks[2] = true;
		i++;
	}
	if (checks[0] && checks[1] && checks[2])
		return (true);
	return(false);
}

bool	check_special_chars(const char *passwd)
{
	int			i;
	int			j;
	const char	specials[7] = {'@', '#', '$', '%', '^', '&', '*'};

	i = 0;
	while (passwd[i] != '\0')
	{
		j = 0;
		while (specials[j])
		{
			if (passwd[i] == specials[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

PwStatus	validate_password(const char *new_pw, const char *curr_pw)
{
	if (!new_pw || !curr_pw)
		return (INVALID);
	if (ft_strcmp(new_pw, curr_pw) == 0)
		return (INVALID);
	if (ft_strlen(new_pw) < 8)
		return (INVALID);
	if (!check_chars(new_pw))
		return (INVALID);
	if (!check_special_chars(new_pw))
		return (INVALID);
	return (VALID);
}
