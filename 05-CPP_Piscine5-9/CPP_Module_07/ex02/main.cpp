/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:11:15 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/01 16:11:16 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
  try {
    std::cout << std::endl
              << BLU "[Array] BASIC & outOfBounds TESTS: " << std::endl;
    Array<int> intArray(4);
    std::cout << MAG "[Array] " W "intArray[3] is " << intArray[3] << std::endl;
    intArray[0] = 2;
    std::cout << MAG "[Array] " W "intArray[0] = 2" << std::endl;
    intArray[0]++;
    std::cout << MAG "[Array] " W "intArray[0]++" << std::endl;
    std::cout << MAG "[Array] " W "intArray[0] is " << intArray[0] << std::endl;
    std::cout << MAG "[Array] " W "intArray[4] is ?" NC << std::endl;
    std::cout << intArray[4] << std::endl;
  } catch (Array<int>::outOfBounds &e) {
    std::cout << YEL "[Array] " << e.what() << std::endl;
  }

  std::cout << std::endl << BLU "[Array] COPY TESTS: " << std::endl;
  Array<char> charArray(3);
  charArray[0] = 'a';
  charArray[1] = 'b';
  charArray[2] = 'c';
  std::cout << MAG "[Array] " W "charArray[0] = " << charArray[0] << std::endl;
  std::cout << MAG "[Array] " W "charArray[1] = " << charArray[1] << std::endl;
  std::cout << MAG "[Array] " W "charArray[2] = " << charArray[2] << std::endl;
  Array<char> charArray2(charArray);
  std::cout << MAG "[Array] " W "charArray2[0] = " << charArray2[0]
            << std::endl;
  std::cout << MAG "[Array] " W "charArray2[1] = " << charArray2[1]
            << std::endl;
  std::cout << MAG "[Array] " W "charArray2[2] = " << charArray2[2]
            << std::endl;

  std::cout << std::endl
            << MAG "[Array] " W "Changing charArray[2] to 'd'" << std::endl;
  charArray[2] = 'd';
  std::cout << MAG "[Array] " W "charArray[2] = " << charArray[2] << std::endl;
  std::cout << MAG "[Array] " W "charArray2[2] = " << charArray2[2]
            << std::endl;
  std::cout << std::endl
            << MAG "[Array] " W "charArray2 = charArray" << std::endl;
  charArray2 = charArray;
  std::cout << MAG "[Array] " W "charArray2[0] = " << charArray2[0]
            << std::endl;
  std::cout << MAG "[Array] " W "charArray2[1] = " << charArray2[1]
            << std::endl;
  std::cout << MAG "[Array] " W "charArray2[2] = " << charArray2[2]
            << std::endl;
  return 0;
}
