/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:52:55 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 14:52:56 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*
 *          CONSTRUCTORS
 * */

WrongAnimal::WrongAnimal() : _type("Unknown") {
  cout << GRN "[WrongAnimal] " W << this->_type
       << " has apeared, he looks wrong!" NC << endl;
}

WrongAnimal::WrongAnimal(string const type) : _type(type) {
  cout << GRN "[WrongAnimal] " W << this->_type
       << " has apeared, he looks wrong!" NC << endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &origin) {
  *this = origin;
  cout << GRN "[WrongAnimal] " W << this->_type
       << " has apeared, he looks wrong, he looks the same as " << origin._type
       << NC << endl;
}

/*
 *          DESTRUCTOR
 * */

WrongAnimal::~WrongAnimal() {
  cout << RED "[WrongAnimal] " W << this->_type
       << " disappears, he still looks wrong!" NC << endl;
}

/*
 *          COPY OPERATOR
 * */

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &origin) {
  if (this->_type != origin._type)
    this->_type = origin._type;
  return *this;
}

/*
 *          FUNCTIONS
 * */

void WrongAnimal::makeSound() const {
  cout << W "[WrongAnimal] " << this->_type << " zzzZZZZ but wrongly..." NC
       << endl;
}

string WrongAnimal::getType() const { return this->_type; }
