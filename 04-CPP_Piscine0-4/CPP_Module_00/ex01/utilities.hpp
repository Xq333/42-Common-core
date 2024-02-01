/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xq <pfaria-d@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:27:39 by xq                #+#    #+#             */
/*   Updated: 2023/07/27 15:27:41 by xq               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>

class Utilities {
public:
  Utilities();
  ~Utilities();
  std::string getString(std::string printString);
  bool strdigit(std::string str);
  void printsearch(int index);
  void printvalues(std::string str);
  void printsearchedvalues(std::string str, std::string contact);
};

#endif
