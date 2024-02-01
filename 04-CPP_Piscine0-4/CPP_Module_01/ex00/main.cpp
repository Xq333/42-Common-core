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
  Zombie base;
  Zombie *newZ = newZombie("newZ");

  randomChump("random");
  delete newZ;
  return 0;
}
