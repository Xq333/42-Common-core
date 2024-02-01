/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:57:13 by xq                #+#    #+#             */
/*   Updated: 2023/09/20 12:57:14 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
 *            Constructors
 * */

Character::Character() : _name("Unnamed") {
  for (int i = 0; i < 4; i++)
    this->_inventory[i] = NULL;
  cout << GRN "[Character] " W << " has appeared!" NC << endl;
}

Character::Character(string const &name) : _name(name) {
  for (int i = 0; i < 4; i++)
    this->_inventory[i] = NULL;
  cout << GRN "[Character] " W << " has appeared!" NC << endl;
}

Character::Character(Character const &origin) : _name(origin._name) {
  for (int i = 0; i < 4; i++)
    this->_inventory[i] = NULL;
  *this = origin;
  cout << GRN "[Character] " W << " has been copied!" NC << endl;
}

/*
 *            Destructor
 * */

Character::~Character() {
  for (int i = 0; i < 4; i++)
    delete this->_inventory[i];
  cout << RED "[Character] " W << this->_name << " disappeared!" NC << endl;
}

/*
 *            Overload operator
 * */

Character &Character::operator=(Character const &origin) {
  for (int i = 0; i < 4; i++)
    if (this->_inventory[i])
      delete this->_inventory[i];
  for (int i = 0; i < 4; i++) {
    if (origin._inventory[i])
      this->_inventory[i] = origin._inventory[i]->clone();
    else
      this->_inventory[i] = NULL;
  }
  this->_name = origin._name;
  return *this;
}

/*
 *            Getters
 * */

string const &Character::getName() const { return this->_name; }

/*
 *            Functions
 * */

void Character::equip(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] == NULL) {
      cout << MAG "[Character] " << this->_name << " equiped " << m->getType()
           << "!" NC << endl;
      this->_inventory[i] = m;
      return;
    }
  }
  cout << YEL "[Character] Inventory is full!" NC << endl;
  delete m;
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx <= 3) {
    if (this->_inventory[idx] == NULL)
      cout << YEL "[Character] There is nothing in the index " << idx << " of "
           << this->_name << "'s inventory!" NC << endl;
    else {
      cout << W "[Character] " << this->_name << " unequiped "
           << this->_inventory[idx]->getType() << "!" NC << endl;
      this->_inventory[idx] = NULL;
    }
  } else {
    cout << YEL "[Character] Index must between 0 and 3!" NC << endl;
  }
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx <= 3) {
    if (this->_inventory[idx] == NULL)
      cout << YEL "[Character] There is nothing in the index " << idx << " of "
           << this->_name << "'s inventory!" NC << endl;
    else {
      this->_inventory[idx]->use(target);
    }
  } else {
    cout << YEL "[Character] Index must between 0 and 3!" NC << endl;
  }
}
