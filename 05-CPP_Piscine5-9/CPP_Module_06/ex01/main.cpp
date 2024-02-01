/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:34:18 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/09/29 09:34:19 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
  Data *d = new Data;
  Data *d2 = NULL;
  uintptr_t ptr;

  d->name = "Pedro";
  d->luckyNumber = 12;
  std::cout << GRN "[Data] " W " Data d(" << d
            << ") has been created. Name: " << d->name
            << " , lucky number = " << d->luckyNumber << std::endl;

  ptr = Serializer::serialize(d);

  d2 = Serializer::deserialize(ptr);
  std::cout << MAG "[Data] " W " uintptr_t ptr(" << ptr
            << ") has been deserialize: d2(" << d2 << ")" NC << std::endl;

  std::cout << GRN "[Data] " W " Data d2(" << d2
            << ") has been created. Name: " << d2->name
            << " , lucky number = " << d2->luckyNumber << std::endl;
  delete d;
  return 0;
}
