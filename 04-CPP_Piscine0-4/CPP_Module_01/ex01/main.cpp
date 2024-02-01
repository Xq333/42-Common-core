/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:45:45 by xq                #+#    #+#             */
/*   Updated: 2023/07/31 20:45:47 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
  Zombie sleeping("sleeping");
  Zombie *newZ = newZombie("newZ");

  randomChump("random");
  delete newZ;

  Zombie *H1 = zombieHorde(4, "Horde");
  Zombie *H2 = zombieHorde(-1, "Horde");
  Zombie *H3 = zombieHorde(0, "Horde");
  Zombie *H4 = zombieHorde(200001, "Horde");

  delete[] H1;
  delete[] H2;
  delete[] H3;
  delete[] H4;
  return 0;
}
