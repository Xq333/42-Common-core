/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:34:32 by xq                #+#    #+#             */
/*   Updated: 2023/08/09 14:34:32 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <stdio.h>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error: ./HarlFilter \"Filter\"" << std::endl;
    return 1;
  }
  std::cout << "\033[1;97m";
  std::string str = av[1];
  Harl harl(str);
  harl.complain();
  std::cout << "\033[1;97m";
  return 0;
}
