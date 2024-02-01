/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:31:36 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/13 12:34:40 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "utilities.hpp"

class Phonebook {
public:
  Phonebook(void);
  ~Phonebook(void);
  int exit(std::string str);
  bool add(void);
  bool search(void);

private:
  int index;
  Contact contact[8];
};

std::string upperstr(std::string str);

#endif
