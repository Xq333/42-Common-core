/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:23:54 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 15:42:16 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

int main() {
  Weapon club = Weapon("crude spiked club");
  HumanA bob("Bob", club);
  bob.attack();
  club.setType("some other type of club");
  bob.attack();
  club.setType("");
  bob.attack();
  std::cout << "------------------" << std::endl;
  HumanB jim("Jim");
  jim.attack();
  jim.setWeapon(club);
  jim.attack();
  club.setType("a ball");
  jim.attack();
  return 0;
}
