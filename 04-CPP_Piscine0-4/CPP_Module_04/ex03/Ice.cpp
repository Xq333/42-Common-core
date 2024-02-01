/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:56:24 by xq                #+#    #+#             */
/*   Updated: 2023/09/20 09:56:25 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
 *          Constructors
 * */

Ice::Ice() : AMateria("ice") {
  cout << GRN "[Ice] " W << this->_type << " has been found!" NC << endl;
}

Ice::Ice(Ice const &origin) : AMateria(origin) {
  cout << GRN "[Ice] " W << this->_type << " has been copied!" NC << endl;
}

/*
 *          Destructors
 * */

Ice::~Ice() {
  cout << RED "[Ice] " W << this->_type << " has been destroyed!" NC << endl;
}

/*
 *          Overload operators
 * */

Ice &Ice::operator=(Ice const &origin) {
  if (this != &origin)
    this->_type = origin._type;
  return *this;
}

/*
 *          Functions
 * */

void Ice::use(ICharacter &target) {
  cout << BLU I "* shoots an ice bolt at " << target.getName() << " *" NC
       << endl;
}

Ice *Ice::clone() const { return new Ice(*this); }
