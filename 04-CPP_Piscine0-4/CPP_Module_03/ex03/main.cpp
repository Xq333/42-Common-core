/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:35:58 by xq                #+#    #+#             */
/*   Updated: 2023/09/14 11:38:56 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
  ClapTrap a("Pichu");
  ClapTrap b("Togepi");

  a.attack(b.getName());
  if (a.getEP() > 0)
    b.takeDamage(a.getAD());
  b.beRepaired(0);

  b.setHP(10);
  b.setEP(0);
  b.beRepaired(1);
  b.attack(a.getName());
  if (b.getEP() > 0)
    a.takeDamage(b.getAD());
  b.setEP(10);
  b.setHP(0);
  b.beRepaired(1);
  b.attack(a.getName());
  if (b.getEP() > 0)
    a.takeDamage(b.getAD());
  a.setEP(0);
  a.setHP(0);
  a.beRepaired(1);
  a.attack(b.getName());
  if (a.getEP() > 0)
    b.takeDamage(a.getAD());

  ScavTrap c("Pikachu");
  c.attack(b.getName());
  if (c.getEP() > 0)
    b.takeDamage(c.getAD());
  b.beRepaired(1);
  c.guardGate();
  FragTrap d("Raichu");
  d.attack(b.getName());
  if (d.getEP() > 0)
    b.takeDamage(d.getAD());
  b.beRepaired(1);
  d.highFivesGuys();
  DiamondTrap e("Togekiss");
  // e.attack(b.getName());
  // if (e.getEP() > 0)
  //   b.takeDamage(e.getAD());
  // b.beRepaired(1);
  // e.highFivesGuys();
  e.whoAmI();
  return 0;
}
