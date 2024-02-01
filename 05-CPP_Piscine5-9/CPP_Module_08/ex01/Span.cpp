/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:12:21 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/02 15:12:22 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
 *          Constructors
 * */

Span::Span() {
  this->_N = 5;
  this->_vector.reserve(this->_N);
  std::cout << GRN "[Span] " W "A Span has been created with " << this->_N
            << " available ints" NC << std::endl;
}

Span::Span(size_t N) {
  this->_N = N;
  this->_vector.reserve(this->_N);
  std::cout << GRN "[Span] " W "A Span has been created with " << this->_N
            << " available ints" NC << std::endl;
}

Span::Span(Span const &origin) {
  this->_N = origin._N;
  this->_vector = origin._vector;
  std::cout << GRN "[Span] " W "A Span has been copied with " << this->_N
            << " available ints" NC << std::endl;
}

/*
 *          Destructors
 * */

Span::~Span() {
  this->_vector.clear();
  std::cout << RED "[Span] " W "A Span has been destroyed with " << this->_N
            << " ints" NC << std::endl;
}

/*
 *          Operator overload
 * */

Span &Span::operator=(Span const &origin) {
  this->_vector.clear();
  this->_N = origin._N;
  this->_vector = origin._vector;
  return *this;
}

/*
 *          Functions
 * */

void Span::addNumber(int nb) {
  if (this->_vector.size() >= this->_N)
    throw Span::isFull();
  this->_vector.push_back(nb);
}

int Span::shortestSpan() const {
  if (this->_vector.size() < 2)
    throw Span::notEnoughValues();
  std::vector<int> tmp = this->_vector;
  std::sort(tmp.begin(), tmp.end());
  long span = tmp[1] - tmp[0];
  for (size_t i = 2; i < this->_vector.size(); i++)
    span = span > (tmp[i] - tmp[i - 1]) ? tmp[i] - tmp[i - 1] : span;
  return span;
}

int Span::longestSpan() const {
  if (this->_vector.size() < 2)
    throw Span::notEnoughValues();
  std::vector<int> tmp = this->_vector;
  std::sort(tmp.begin(), tmp.end());
  long span = tmp[tmp.size() - 1] - tmp[0];
  return span;
}

void Span::generateRange(size_t N) {
  srand(std::time(0));
  for (size_t i = 0; i < N; i++)
    addNumber(rand());
}
