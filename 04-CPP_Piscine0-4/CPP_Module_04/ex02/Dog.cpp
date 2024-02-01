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

Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
  cout << GRN "[Dog] " W << this->_type << " has apeared, Wouuuuuuuuuuf!" NC
       << endl;
}

Dog::Dog(Dog const &origin)
    : AAnimal("Dog"), _brain(new Brain(*origin._brain)) {
  *this = origin;
  cout << GRN "[Dog] " W << this->_type
       << " has apeared, Wouuuuuuuuuuf, he looks the same as " << origin._type
       << "!" NC << endl;
}

/*
 *          DESTRUCTOR
 * */

Dog::~Dog() {
  delete this->_brain;
  cout << RED "[Dog] " W << this->_type << " disappears, Wouuuuuuuuuuf!" NC
       << endl;
}

/*
 *          COPY OPERATOR
 * */

Dog &Dog::operator=(Dog const &origin) {
  if (this != &origin) {
    delete this->_brain;
    this->_brain = new Brain(*origin._brain);
    this->_type = origin._type;
  }
  return *this;
}

/*
 *          FUNCTIONS
 * */

void Dog::makeSound() const {
  cout << W "[Dog] " << this->_type << ": Wouuuf!" NC << endl;
}

Brain *Dog::getBrain() { return this->_brain; }
