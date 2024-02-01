/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:36:04 by xq                #+#    #+#             */
/*   Updated: 2023/08/10 09:36:05 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
  this->_name = "Unnamed";
  this->_hp = 10;
  this->_ep = 10;
  this->_ad = 0;
  std::cout << "\033[1;94mClapTrap " << this->_name << " appeared!\033[1;0m"
            << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
  this->_name = name;
  this->_hp = 10;
  this->_ep = 10;
  this->_ad = 0;
  std::cout << "\033[1;94mClapTrap " << this->_name << " appeared!\033[1;0m"
            << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clap) { *this = clap; }

ClapTrap::~ClapTrap(void) {
  std::cout << "\033[1;31mClapTrap " << this->_name << " left!\033[1;0m"
            << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clap) {
  this->_name = clap._name;
  this->_ad = clap._ad;
  this->_hp = clap._hp;
  this->_ep = clap._ep;
  return *this;
}

std::string ClapTrap::getName(void) { return this->_name; }

unsigned int ClapTrap::getAD(void) { return this->_ad; }

unsigned int ClapTrap::getEP(void) { return this->_ep; }

void ClapTrap::setEP(unsigned int amout) {
  this->_ep = amout;
  std::cout << "\033[1;34mClapTrap " << this->_name << " has now " << this->_ep
            << " ep!\033[1;0m" << std::endl;
}

void ClapTrap::setHP(unsigned int amout) {
  this->_hp = amout;
  std::cout << "\033[1;34mClapTrap " << this->_name << " has now " << this->_hp
            << " hp!\033[1;0m" << std::endl;
}

void ClapTrap::attack(const std::string &name) {
  if (this->_hp == 0) {
    std::cout << "\033[1;91mClapTrap " << this->_name
              << " is dead, so he cannot attack " << name << "\033[1;0m!"
              << std::endl;
  } else if (this->_ep == 0) {
    std::cout << "\033[1;93mClapTrap " << this->_name
              << " doesn't have enough energy to attack " << name
              << "!\033[1;0m" << std::endl;
  } else {
    std::cout << "\033[1;92mClapTrap " << this->_name << " attacks " << name
              << ", causing " << this->_ad << " points of damage!\033[1;0m"
              << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->_ep == 0)
    return;
  else if (this->_hp == 0) {
    this->_ep--;
    std::cout << "\033[1;93mClapTrap " << this->_name
              << " is already dead, but he continues to get hit!\033[1;0m"
              << std::endl;
  } else {
    std::cout << "\033[1;92mClapTrap " << this->_name << " took " << amount
              << " points of damage!\033[1;0m" << std::endl;
    this->_hp -= amount;
    this->_ep--;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_hp == 0) {
    std::cout << "\033[1;91mClapTrap " << this->_name
              << " is dead, he cannot be repaired!\033[1;0m" << std::endl;
  } else if (this->_ep == 0) {
    std::cout << "\033[1;93mClapTrap " << this->_name
              << " doesn't have enough energy to be repaired!\033[1;0m"
              << std::endl;
  } else {
    this->_ep--;
    std::cout << "\033[1;92mClapTrap " << this->_name
              << " is being repaired, he went from " << this->_hp << " to "
              << (this->_hp + amount) << "ep!\033[1;0m" << std::endl;
    this->_hp += amount;
  }
}
