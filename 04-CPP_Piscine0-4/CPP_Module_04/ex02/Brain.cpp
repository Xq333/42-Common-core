/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:08:52 by xq                #+#    #+#             */
/*   Updated: 2023/09/19 08:08:53 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
 *          CONSTRUCTORS
 * */

Brain::Brain() {
  cout << GRN "[Brain] " W "A new brain has been created!" NC << endl;
}

Brain::Brain(Brain const &origin) {
  *this = origin;
  cout << GRN "[Brain] " W "A new brain has been copied!" NC << endl;
}

/*
 *          DESTRUCTOR
 * */

Brain::~Brain() {
  cout << RED "[Brain] " W " A brain has been destoyed!" NC << endl;
}

/*
 *          COPY OPERATOR
 * */

Brain &Brain::operator=(Brain const &origin) {
  for (int i = 0; i < 100; i++)
    this->ideas[i] = origin.ideas[i];
  return *this;
}
