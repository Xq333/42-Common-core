/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:30:42 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/09/29 10:30:42 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << YEL
        "[Error]: ScalarConvert must have one and only one argument, exemple:"
              << std::endl
              << "./ScalarConvert [argument]" NC << std::endl;
    return 1;
  }
  ScalarConvert::convert(av[1]);
  return 0;
}
