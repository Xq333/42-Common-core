/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:20:58 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/02 14:20:58 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main() {
  {
    std::list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    std::list<int>::iterator res = easyfind(list, 3);
    if (res != list.end())
      std::cout << "Searching 3..." << std::endl
                << "3 is on the index " << std::distance(list.begin(), res)
                << std::endl;
    else
      std::cout << "3 not found" << std::endl;
    std::list<int>::iterator res2 = easyfind(list, 6);
    if (res2 != list.end())
      std::cout << "Searching 6..." << std::endl
                << "6 is on the index " << std::distance(list.begin(), res2)
                << std::endl;
    else
      std::cout << "6 not found" << std::endl;
  }
  std::vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);
  std::vector<int>::iterator res = easyfind(vector, 3);
  if (res != vector.end())
    std::cout << "Searching 3..." << std::endl
              << "3 is on the index " << std::distance(vector.begin(), res)
              << std::endl;
  else
    std::cout << "3 not found" << std::endl;
  std::vector<int>::iterator res2 = easyfind(vector, 6);
  if (res2 != vector.end())
    std::cout << "Searching 6..." << std::endl
              << "6 is on the index " << std::distance(vector.begin(), res2)
              << std::endl;
  else
    std::cout << "6 not found" << std::endl;
  return 0;
}
