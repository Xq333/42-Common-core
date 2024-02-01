/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:26:04 by xq                #+#    #+#             */
/*   Updated: 2023/09/20 13:26:05 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
 *            Constructors
 * */

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    this->_inventory[i] = NULL;
  cout << GRN "[MateriaSource] " W "A MateriaSource  has been created!" NC
       << endl;
}

MateriaSource::MateriaSource(MateriaSource const &origin) {
  for (int i = 0; i < 4; i++)
    delete this->_inventory[i];
  *this = origin;
  cout << GRN "[MateriaSource] " W "A MateriaSource  has been copied!" NC
       << endl;
}

/*
 *            Destructor
 * */

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++)
    delete this->_inventory[i];
  cout << RED "[MateriaSource] " W "A MateriaSource has been destroyed!" NC
       << endl;
}

/*
 *            Overload operator
 * */

MateriaSource &MateriaSource::operator=(MateriaSource const &origin) {
  for (int i = 0; i < 4; i++)
    delete this->_inventory[i];
  for (int i = 0; i < 4; i++)
    this->_inventory[i] = origin._inventory[i]->clone();
  return *this;
}

/*
 *            Functions
 * */

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] == NULL) {
      cout << MAG "[MateriaSource] A MateriaSource learned " << m->getType()
           << "!" NC << endl;
      this->_inventory[i] = m;
      return;
    }
  }
  cout << YEL "[MateriaSource] Inventory is full!" NC << endl;
  delete m;
}

AMateria *MateriaSource::createMateria(string const &type) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type) {
      return this->_inventory[i]->clone();
    }
  }
  cout << YEL "[MateriaSource] Materia " << type << " not found!" NC << endl;
  return 0;
}
