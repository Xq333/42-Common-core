/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:56:28 by xq                #+#    #+#             */
/*   Updated: 2023/09/20 09:56:29 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*
 *          Constructors
 * */

Cure::Cure() : AMateria("cure") {
  cout << GRN "[Cure] " W << this->_type << " has been found!" NC << endl;
}

Cure::Cure(Cure const &origin) : AMateria(origin) {
  cout << GRN "[Cure] " W << this->_type << " has been copied!" NC << endl;
}

/*
 *          Destructors
 * */

Cure::~Cure() {
  cout << RED "[Cure] " W << this->_type << " has been destroyed!" NC << endl;
}

/*
 *          Overload operators
 * */

Cure &Cure::operator=(Cure const &origin) {
  if (this != &origin)
    this->_type = origin._type;
  return *this;
}

/*
 *          Functions
 * */

void Cure::use(ICharacter &target) {
  cout << BLU I "* heals " << target.getName() << "\'s wounds *" NC << endl;
}

Cure *Cure::clone() const { return new Cure(*this); }
