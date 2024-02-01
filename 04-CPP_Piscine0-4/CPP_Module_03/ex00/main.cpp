/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:35:58 by xq                #+#    #+#             */
/*   Updated: 2023/08/10 09:35:59 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap a("Pichu");
  ClapTrap b("Togepi");

  a.attack(b.getName());
  if (a.getEP() > 0)
    b.takeDamage(a.getAD());
  b.beRepaired(1);

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
  return 0;
}
