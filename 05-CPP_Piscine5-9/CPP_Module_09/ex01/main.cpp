/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:23:46 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/18 15:23:48 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
  if (ac != 2)
    return 1;
  try {
    RPN a;
    std::cout << a.RPNcalc(av[1]) << std::endl;
  } catch (RPN::div0 &e) {
    std::cout << e.what() << std::endl;
  } catch (RPN::badCalc &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
