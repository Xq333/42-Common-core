/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:31:59 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/13 12:43:32 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
public:
  Contact();
  ~Contact();
  // Setters & getters
  void setFirstName(std::string firstName);
  std::string getFirstName(void);
  void setLastName(std::string lastName);
  std::string getLastName(void);
  void setNickname(std::string nickname);
  std::string getNickname(void);
  void setPhoneNumber(std::string phoneNumber);
  std::string getPhoneNumber(void);
  void setDarkestSecret(std::string darkestSecret);
  std::string getDarkestSecret(void);

private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
};

#endif
