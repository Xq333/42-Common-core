/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:09:19 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/18 18:09:19 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
 *          Constructors
 * */

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &origin) { *this = origin; }

/*
 *          Destructors
 * */

PmergeMe::~PmergeMe() {}

/*
 *          Overload operator
 * */

PmergeMe &PmergeMe::operator=(PmergeMe const &origin) {
  *this = origin;
  return *this;
}
