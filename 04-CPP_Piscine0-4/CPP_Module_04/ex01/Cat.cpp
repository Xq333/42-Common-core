/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:30:13 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 15:30:14 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
 *          CONSTRUCTORS
 * */

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
  cout << GRN "[Cat] " W << this->_type << " has apeared, Meowwwwwwww!" NC
       << endl;
}

Cat::Cat(Cat const &origin) : Animal("Cat"), _brain(new Brain(*origin._brain)) {
  *this = origin;
  cout << GRN "[Cat] " W << this->_type
       << " has apeared, Meowwwwwwww, he looks the same as " << origin._type
       << "!" NC << endl;
}

/*
 *          DESTRUCTOR
 * */

Cat::~Cat() {
  delete this->_brain;
  cout << RED "[Cat] " W << this->_type << " disappears, Meowwwwwwww!" NC
       << endl;
}

/*
 *          COPY OPERATOR
 * */

Cat &Cat::operator=(Cat const &origin) {
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

void Cat::makeSound() const {
  cout << W "[Cat] " << this->_type << ": Meowwwww!" NC << endl;
}

Brain *Cat::getBrain() { return this->_brain; }
