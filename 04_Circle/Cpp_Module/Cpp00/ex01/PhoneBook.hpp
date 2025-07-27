/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:20:29 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/07/05 06:26:45 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

class PhoneBook
{
	private	:
		class Contact
		{
			private :
				std::string Name;
				std::string Num;

			public	:
				Contact();
				ADD();
				SEARCH();
				EXIT();
		};

	private	:
		Contact	list;
		int		head;
		int		tail;
		int		size;
	
	public	:
		PhoneBook();
		PhoneBook(const PhoneBook& instance);
};

#endif