/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:31:53 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/13 12:42:51 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void Contact::setFirstName(std::string firstName) {
  this->firstName = firstName;
}

std::string Contact::getFirstName(void) { return (this->firstName); }

void Contact::setLastName(std::string lastName) { this->lastName = lastName; }

std::string Contact::getLastName(void) { return (this->lastName); }

void Contact::setNickname(std::string nickname) { this->nickname = nickname; }

std::string Contact::getNickname(void) { return (this->nickname); }

void Contact::setPhoneNumber(std::string phoneNumber) {
  this->phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber(void) { return (this->phoneNumber); }

void Contact::setDarkestSecret(std::string darkestSecret) {
  this->darkestSecret = darkestSecret;
}

std::string Contact::getDarkestSecret(void) { return (this->darkestSecret); }
