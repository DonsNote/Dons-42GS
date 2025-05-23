/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:00:09 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/05/19 16:44:55 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; ++i)
	{
		std::string str = av[i];
		for (int j = 0; j < str.length(); ++j)
			std::cout << static_cast<char>(std::toupper(str[j]));
	}
	std::cout << std::endl;
}
