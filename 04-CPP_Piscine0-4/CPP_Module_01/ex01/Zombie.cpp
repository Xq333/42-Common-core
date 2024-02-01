/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:46:06 by xq                #+#    #+#             */
/*   Updated: 2023/07/31 20:46:07 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _nom("baseZombie") {}

Zombie::Zombie(std::string nom) : _nom(nom) { announce(); }

Zombie::~Zombie(void) { std::cout << "Bye bye " << this->_nom << std::endl; }

void Zombie::announce(void) {
  std::cout << this->_nom << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name) { return (new Zombie(name)); }

void randomChump(std::string name) { Zombie Zombie(name); }

void Zombie::setname(std::string name) {
  this->_nom = name;
  this->announce();
}
