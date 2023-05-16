/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:13 by sanan             #+#    #+#             */
/*   Updated: 2023/04/09 19:01:27 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "contact.hpp"
# define NUM_CONTACTS 8

class PhoneBook {
	private:
		Contact _phoneBook[NUM_CONTACTS];

	public:
		PhoneBook();
		~PhoneBook();
		void setContactByIndex(
			int index,
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNumber,
			std::string darkestSecret,
			int			isAdded
		);
		Contact 	getContactByIndex(int index);
		std::string getFirstNameByIndex(int index);
		std::string getLastNameByIndex(int index);
		std::string getNickNameByIndex(int index);
		std::string getPhoneNumberByIndex(int index);
		std::string getDarkestSecretByIndex(int index);
		int 		getIsaddedByIndex(int index);
		void		swapContacts(void);
};

#endif