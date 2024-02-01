/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:56:38 by xq                #+#    #+#             */
/*   Updated: 2023/08/08 13:56:40 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  if (N < 0) {
    std::cout << "\033[1;96mYou cannot create an horde with a negative number "
                 "of zombies ):!\033[1;0m"
              << std::endl;
    return NULL;
  } else if (N == 0) {
    std::cout << "\033[1;96mYou cannot create an horde with zero zombies "
                 "of zombies ):!\033[1;0m"
              << std::endl;
    return NULL;
  } else if (N > 200000) {
    std::cout << "\033[1;31mMaybe too much zombies for your computer.\033[1;0m"
              << std::endl;
    return NULL;
  }
  Zombie *h = new Zombie[N]();
  for (int i = 0; i < N; i++)
    h[i].setname(name);
  return h;
}
