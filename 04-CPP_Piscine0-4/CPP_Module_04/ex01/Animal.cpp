/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:52:29 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 14:52:30 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
 *          CONSTRUCTORS
 * */

Animal::Animal() : _type("Unknown") {
  cout << GRN "[Animal] " W << this->_type << " has apeared!" NC << endl;
}

Animal::Animal(string const type) : _type(type) {
  cout << GRN "[Animal] " W << this->_type << " has apeared!" NC << endl;
}

Animal::Animal(Animal const &origin) {
  *this = origin;
  cout << GRN "[Animal] " W << this->_type
       << " has apeared, he looks the same as " << origin._type << NC << endl;
}

/*
 *          DESTRUCTOR
 * */

Animal::~Animal() {
  cout << RED "[Animal] " W << this->_type << " disappears!" NC << endl;
}

/*
 *          COPY OPERATOR
 * */

Animal &Animal::operator=(Animal const &origin) {
  if (this->_type != origin._type)
    this->_type = origin._type;
  return *this;
}

/*
 *          FUNCTIONS
 * */

void Animal::makeSound() const {
  cout << W "[Animal] " << this->_type << " zzzZZZZ..." NC << endl;
}

string Animal::getType() const { return this->_type; }
