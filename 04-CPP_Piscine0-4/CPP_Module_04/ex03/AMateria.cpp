/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:27:22 by xq                #+#    #+#             */
/*   Updated: 2023/09/20 09:27:23 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
 *          Constructors
 * */

AMateria::AMateria() : _type("Unknown") {
  cout << GRN "[AMateria] " W << this->_type << " has been found!" NC << endl;
}

AMateria::AMateria(string const &type) : _type(type) {
  cout << GRN "[AMateria] " W << this->_type << " has been found!" NC << endl;
}

AMateria::AMateria(AMateria const &origin) : _type(origin._type) {
  cout << GRN "[AMateria] " W << this->_type << " has been copied!" NC << endl;
}

/*
 *          Destructors
 * */

AMateria::~AMateria() {
  cout << RED "[AMateria] " W << this->_type << " has been destroyed!" NC
       << endl;
}

/*
 *          Overload operators
 * */

AMateria &AMateria::operator=(AMateria const &origin) {
  if (this != &origin)
    this->_type = origin._type;
  return *this;
}

/*
 *          Getters/setters
 * */

string const &AMateria::getType() const { return this->_type; }

/*
 *          Functions
 * */

void AMateria::use(ICharacter &target) {
  cout << BLU I "* maybe will do something to " << target.getName() << " *" NC
       << endl;
}
