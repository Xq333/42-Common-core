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

int main(void) {
  std::cout << "\033[1;97m";
  Harl harl;

  std::cout << "\033[1;96m";
  harl.complain("DEBUG");
  std::cout << "\033[1;90m";
  harl.complain("INFO");
  std::cout << "\033[1;93m";
  harl.complain("WARNING");
  std::cout << "\033[1;31m";
  harl.complain("ERROR");
  std::cout << "\033[1;97m";
  return 0;
}
