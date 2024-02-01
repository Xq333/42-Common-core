/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:52:29 by xq                #+#    #+#             */
/*   Updated: 2023/09/18 14:52:30 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
 *          CONSTRUCTORS
 * */

AAnimal::AAnimal() : _type("Unknown") {
  cout << GRN "[AAnimal] " W << this->_type << " has apeared!" NC << endl;
}

AAnimal::AAnimal(string const type) : _type(type) {
  cout << GRN "[AAnimal] " W << this->_type << " has apeared!" NC << endl;
}

AAnimal::AAnimal(AAnimal const &origin) {
  *this = origin;
  cout << GRN "[AAnimal] " W << this->_type
       << " has apeared, he looks the same as " << origin._type << NC << endl;
}

/*
 *          DESTRUCTOR
 * */

AAnimal::~AAnimal() {
  cout << RED "[AAnimal] " W << this->_type << " disappears!" NC << endl;
}

/*
 *          COPY OPERATOR
 * */

AAnimal &AAnimal::operator=(AAnimal const &origin) {
  if (this->_type != origin._type)
    this->_type = origin._type;
  return *this;
}

/*
 *          FUNCTIONS
 * */

void AAnimal::makeSound() const {
  cout << W "[AAnimal] " << this->_type << " zzzZZZZ..." NC << endl;
}

string AAnimal::getType() const { return this->_type; }
