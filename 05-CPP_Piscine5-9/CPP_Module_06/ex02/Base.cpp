/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 07:58:23 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/09/29 07:58:23 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base() {
  std::cout << GRN "[Base] " W "A Base has been created!" NC << std::endl;
}

Base::~Base() {
  std::cout << RED "[Base] " W "A Base has been destroyed!" NC << std::endl;
}
