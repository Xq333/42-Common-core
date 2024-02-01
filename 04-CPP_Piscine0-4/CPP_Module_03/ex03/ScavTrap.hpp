/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:45:51 by xq                #+#    #+#             */
/*   Updated: 2023/09/13 19:32:23 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string const &name);
  ScavTrap(ScavTrap const &name);
  ~ScavTrap();
  ScavTrap &operator=(ScavTrap const &name);
  void attack(const std::string &name);
  void guardGate();
};
