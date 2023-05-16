/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:36:15 by sanan             #+#    #+#             */
/*   Updated: 2023/03/19 15:12:27 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

void Contact::setContact(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNumber,
			std::string darkestSecret,
			int			isAdded
		) {
			_firstName = firstName;
			_lastName = lastName;
			_nickName = nickName;
			_phoneNumber = phoneNumber;
			_darkestSecret = darkestSecret;
			_isAdded = isAdded;
	};

std::string Contact::getFirstName() const {
	return (_firstName);
}

std::string Contact::getLastName() const {
	return (_lastName);
}

std::string Contact::getNickName() const {
	return (_nickName);
}

std::string Contact::getPhoneNumber() const {
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const {
	return (_darkestSecret);
}

int Contact::getIsAdded() const {
	return (_isAdded);
}
