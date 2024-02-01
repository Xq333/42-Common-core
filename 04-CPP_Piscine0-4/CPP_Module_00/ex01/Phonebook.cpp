/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:31:26 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/13 12:33:10 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cstring>
#include <sstream>

std::string upperstr(std::string str) {
  for (int i = 0; i < (int)str.length(); i++)
    str[i] = toupper(str[i]);
  return (str);
}

int Phonebook::exit(std::string str) {
  if (upperstr(str) == "EXIT")
    return 1;
  return 0;
}

Phonebook::Phonebook(void) {
  index = 0;
  std::cout << "Welcome to your phonebook" << std::endl;
}

Phonebook::~Phonebook(void) { std::cout << "Phonebook closed!" << std::endl; }

bool Phonebook::add(void) {
  Utilities _utilities;
  Contact _tmpContact;

  _tmpContact.setFirstName(_utilities.getString("First name: "));
  while (_tmpContact.getFirstName().empty())
    _tmpContact.setFirstName(_utilities.getString(
        "Error: first name cannot be empty\nFirst name: "));
  _tmpContact.setLastName(_utilities.getString("Last name: "));
  while (_tmpContact.getLastName().empty())
    _tmpContact.setLastName(
        _utilities.getString("Error: last name cannot be empty\nLast name: "));
  _tmpContact.setNickname(_utilities.getString("Nickname: "));
  while (_tmpContact.getNickname().empty())
    _tmpContact.setNickname(
        _utilities.getString("Error: nickname cannot be empty\nNickname: "));
  _tmpContact.setPhoneNumber(_utilities.getString("Phone number: "));
  while (_tmpContact.getPhoneNumber().empty())
    _tmpContact.setPhoneNumber(_utilities.getString(
        "Error: phone number cannot be empty\nPhone number: "));
  _tmpContact.setDarkestSecret(_utilities.getString("Darkest secret: "));
  while (_tmpContact.getDarkestSecret().empty())
    _tmpContact.setDarkestSecret(_utilities.getString(
        "Error: darkest secret cannot be empty\nDarkest secret: "));
  contact[index % 8] = _tmpContact;
  this->index++;
  return true;
}

bool Phonebook::search(void) {
  Utilities _utilities;
  std::string _buff;
  std::stringstream _stream;
  int _i = 0;
  int _tmpindex;
  if (this->index == 0)
    goto noContact;
  _utilities.printsearch(2);
  _utilities.printsearch(1);
  _utilities.printsearch(2);
  for (_i = 0; _i < this->index && _i < 8; _i++) {
    std::string tmp;
    std::cout << "|         " << _i + 1 << "|";
    _utilities.printvalues(this->contact[_i].getFirstName());
    _utilities.printvalues(this->contact[_i].getLastName());
    _utilities.printvalues(this->contact[_i].getNickname());
    std::cout << std::endl;
    _utilities.printsearch(2);
  }
  std::cout << "Write the index of the contact you want to know more "
               "about: ";
  if (!std::getline(std::cin, _buff))
    return false;
  _stream << _buff;
  _stream >> _tmpindex;
  if (_tmpindex < 1 || _tmpindex >= _i + 1)
    std::cout << "Contact does not exit" << std::endl;
  else {
    _utilities.printsearchedvalues("First name: ",
                                   this->contact[_tmpindex - 1].getFirstName());
    _utilities.printsearchedvalues("Last name: ",
                                   this->contact[_tmpindex - 1].getLastName());
    _utilities.printsearchedvalues("Nickname: ",
                                   this->contact[_tmpindex - 1].getNickname());
    _utilities.printsearchedvalues(
        "Phone number: ", this->contact[_tmpindex - 1].getPhoneNumber());
    _utilities.printsearchedvalues(
        "Darkest secret: ", this->contact[_tmpindex - 1].getDarkestSecret());
  }
  return true;
noContact:
  std::cout << "No contacts in the contact list ):" << std::endl;
  return true;
}
