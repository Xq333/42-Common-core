/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 07:45:23 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/03 07:45:24 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main() {
  std::cout << BLU "main subject tests with mutant stack" W << std::endl;
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  std::cout << BLU "main subject tests with list" W << std::endl;
  MutantStack<int> list;
  list.push(5);
  list.push(17);
  std::cout << list.top() << std::endl;
  list.pop();
  std::cout << list.size() << std::endl;
  list.push(3);
  list.push(5);
  list.push(737);
  list.push(0);
  MutantStack<int>::iterator itl = list.begin();
  MutantStack<int>::iterator itel = list.end();
  ++itl;
  --itl;
  while (itl != itel) {
    std::cout << *itl << std::endl;
    ++itl;
  }
  return 0;
}
