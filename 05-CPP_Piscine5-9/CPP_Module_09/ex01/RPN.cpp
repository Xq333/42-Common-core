/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:02 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/10/18 15:24:03 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

/*
 *          Constructors
 * */

RPN::RPN() {}

RPN::RPN(RPN const &origin) { *this = origin; }

/*
 *          Destructors
 * */

RPN::~RPN() {}

/*
 *          overload operators
 * */

RPN &RPN::operator=(RPN const &origin) {
  *this = origin;
  return *this;
}

/*
 *          Functions
 * */

bool isoperator(char c) {
  return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool checker(std::string str) {
  int op = 0;
  int nb = 0;
  for (size_t i = 0; str[i]; i++) {
    if (isdigit(str[i]))
      nb++;
    else if (isoperator(str[i]))
      op++;
    else if (str[i] == ' ')
      continue;
    else
      return true;
  }
  if (nb - 1 != op)
    return true;
  return false;
}

int RPN::RPNcalc(std::string str) {
  int res = 0;
  if (checker(str))
    throw RPN::badCalc();
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == ' ')
      continue;
    else if (isdigit(str[i])) {
      this->_stack.push(str[i] - 48);
    } else if (isoperator(str[i])) {
      int tmp = this->_stack.top();
      this->_stack.pop();
      switch (str[i]) {
      case '+':
        this->_stack.top() = this->_stack.top() + tmp;
        break;
      case '-':
        this->_stack.top() = this->_stack.top() - tmp;
        break;
      case '/':
        if (tmp == 0)
          throw RPN::div0();
        this->_stack.top() = this->_stack.top() / tmp;
        break;
      case '*':
        this->_stack.top() = this->_stack.top() * tmp;
        break;
      }
    }
  }
  res = this->_stack.top();
  return res;
}
