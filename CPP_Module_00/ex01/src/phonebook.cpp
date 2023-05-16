/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:28:44 by sanan             #+#    #+#             */
/*   Updated: 2023/03/19 15:32:18 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/phonebook.hpp"

PhoneBook::PhoneBook() {
	
}

PhoneBook::~PhoneBook() {

}

void PhoneBook::setContactByIndex(
		int index,
		std::string firstName,
		std::string lastName,
		std::string nickName,
		std::string phoneNumber,
		std::string darkestSecret,
		int			isAdded
	) {
		_phoneBook[index].setContact(
			firstName,
			lastName,
			nickName,
			phoneNumber,
			darkestSecret,
			isAdded
	);
}

Contact PhoneBook::getContactByIndex(int index) {
	return (_phoneBook[index]);
}

std::string PhoneBook::getFirstNameByIndex(int index) {
	return (_phoneBook[index].getFirstName());
}

std::string PhoneBook::getLastNameByIndex(int index) {
	return (_phoneBook[index].getLastName());
}

std::string PhoneBook::getNickNameByIndex(int index) {
	return (_phoneBook[index].getNickName());
}

std::string PhoneBook::getPhoneNumberByIndex(int index) {
	return (_phoneBook[index].getPhoneNumber());
}

std::string PhoneBook::getDarkestSecretByIndex(int index) {
	return (_phoneBook[index].getDarkestSecret());
}

int PhoneBook::getIsaddedByIndex(int index) {
	return (_phoneBook[index].getIsAdded());
}

void PhoneBook::swapContacts(void) {
	for (int i = NUM_CONTACTS - 1; i > 0; i--) {
		_phoneBook[i].setContact(
			_phoneBook[i - 1].getFirstName(),
			_phoneBook[i - 1].getLastName(),
			_phoneBook[i - 1].getNickName(),
			_phoneBook[i - 1].getPhoneNumber(),
			_phoneBook[i - 1].getDarkestSecret(),
			_phoneBook[i - 1].getIsAdded()
		);
	}
}