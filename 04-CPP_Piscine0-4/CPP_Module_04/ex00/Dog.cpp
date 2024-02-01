/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:52:34 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 14:52:35 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
 *          CONSTRUCTORS
 * */

Dog::Dog() : Animal("Dog") {
  cout << GRN "[Dog] " W << this->_type << " has apeared, Wouuuuuuuuuuf!" NC
       << endl;
}

Dog::Dog(Dog const &origin) : Animal("Dog") {
  *this = origin;
  cout << GRN "[Dog] " W << this->_type
       << " has apeared, Wouuuuuuuuuuf, he looks the same as " << origin._type
       << "!" NC << endl;
}

/*
 *          DESTRUCTOR
 * */

Dog::~Dog() {
  cout << RED "[Dog] " W << this->_type << " disappears, Wouuuuuuuuuuf!" NC
       << endl;
}

/*
 *          COPY OPERATOR
 * */

Dog &Dog::operator=(Dog const &origin) {
  if (this->_type != origin._type)
    this->_type = origin._type;
  return *this;
}

/*
 *          FUNCTIONS
 * */

void Dog::makeSound() const {
  cout << W "[Dog] " << this->_type << ": Wouuuf!" NC << endl;
}
