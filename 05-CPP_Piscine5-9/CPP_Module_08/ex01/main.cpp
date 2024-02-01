/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:12:26 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/02 15:12:26 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  std::cout << BLU "--- Exceptions ---" NC << std::endl;
  try {
    Span notEnough = Span(3);
    notEnough.addNumber(1);
    notEnough.longestSpan();
  } catch (Span::notEnoughValues &e) {
    std::cout << YEL << e.what() << NC << std::endl;
  }
  try {
    Span full = Span(1);
    full.addNumber(1);
    full.addNumber(2);
  } catch (Span::isFull &e) {
    std::cout << YEL << e.what() << NC << std::endl;
  }
  return 0;
}
