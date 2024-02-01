/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:11:24 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/09/29 09:11:25 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
 *        Constructors
 * */

Serializer::Serializer(){};

Serializer::Serializer(Serializer const &origin) { static_cast<void>(origin); };

/*
 *        Destructor
 * */

Serializer::~Serializer(){};

/*
 *        Overload operator
 * */

Serializer &Serializer::operator=(Serializer const &origin) {
  static_cast<void>(origin);
  return *this;
};

/*
 *        Functions
 * */

uintptr_t Serializer::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
