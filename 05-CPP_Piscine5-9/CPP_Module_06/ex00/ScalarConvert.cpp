/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:30:39 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/09/29 10:30:39 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
#include <cctype>
#include <stdexcept>

/*
 *        Constructors
 * */

ScalarConvert::ScalarConvert(){};

ScalarConvert::ScalarConvert(ScalarConvert const &origin) {
  static_cast<void>(origin);
};

/*
 *        Destructor
 * */

ScalarConvert::~ScalarConvert(){};

/*
 *        Overload operator
 * */

ScalarConvert &ScalarConvert::operator=(ScalarConvert const &origin) {
  static_cast<void>(origin);
  return *this;
};

/*
 *        Functions
 * */

void ScalarConvert::printGoodChar(char c) {
  std::cout << W "char: '" << c << "'" NC << std::endl;
}

void ScalarConvert::printWrongChar(std::string str) {
  std::cout << YEL "char: " << str << NC << std::endl;
}

void ScalarConvert::printGoodInt(int c) {
  std::cout << W "int: " << c << NC << std::endl;
}

void ScalarConvert::printWrongInt(std::string str) {
  std::cout << YEL "int: " << str << NC << std::endl;
}

void ScalarConvert::printGoodFloat(float c) {
  std::cout << W "float: " << c << "f" NC << std::endl;
}

void ScalarConvert::printGoodFloat2(float c) {
  std::cout << W "float: " << c << ".0f" NC << std::endl;
}

void ScalarConvert::printWrongFloat(std::string str) {
  std::cout << YEL "float: " << str << "" NC << std::endl;
}

void ScalarConvert::printExceptionFloat(std::string str) {
  std::cout << W "float: " << str << "f" NC << std::endl;
}

void ScalarConvert::printException2Float(int t) {
  std::cout << W "float: " << t << ".0f" NC << std::endl;
}

void ScalarConvert::printGoodDouble(double c) {
  std::cout << W "double: " << c << NC << std::endl;
}

void ScalarConvert::printGoodDouble2(double c) {
  std::cout << W "double: " << c << ".0" NC << std::endl;
}

void ScalarConvert::printWrongDouble(std::string str) {
  std::cout << YEL "double: " << str << NC << std::endl;
}

void ScalarConvert::printExceptionDouble(std::string str) {
  std::cout << W "double: " << str << NC << std::endl;
}

void ScalarConvert::printException2Double(int t) {
  std::cout << W "double: " << t << ".0" NC << std::endl;
}

void ScalarConvert::convert(std::string str) {
  printChar(str);
  printInt(str);
  printFloat(str);
  printDouble(str);
}

void ScalarConvert::printChar(std::string str) {
  if (str.length() > 1 && !isdigit(str[0]) && !isdigit(str[1]) &&
      str.compare("-inf") && str.compare("-inff") && str.compare("+inf") &&
      str.compare("+inff") && str.compare("nan") && str.compare("nanf"))
    printWrongChar("impossible");
  else if (str.length() == 1 && !isdigit(str[0])) {
    printGoodChar(static_cast<char>(str[0]));
  } else if (std::atol(str.c_str()) > 31 && std::atol(str.c_str()) < 127) {
    printGoodChar(std::atol(str.c_str()));
  } else {
    if (!str.compare("nan") || !str.compare("nanf"))
      printWrongChar("impossible");
    else if (!str.compare("-inf") || !str.compare("+inf") ||
             !str.compare("-inff") || !str.compare("+inff"))
      printWrongChar("impossible");
    else
      printWrongChar("non displayable");
  }
}

void ScalarConvert::printInt(std::string str) {
  if (str.length() > 1 && !isdigit(str[0]) && !isdigit(str[1]))
    printWrongInt("impossible");
  else if (str.length() == 1 && !isdigit(str[0])) {
    printGoodInt(static_cast<char>(str[0]));
  } else if (std::strtol(str.c_str(), NULL, 10) >= INT_MIN &&
             std::strtol(str.c_str(), NULL, 10) <= INT_MAX) {
    printGoodInt(std::strtol(str.c_str(), NULL, 10));
  } else {
    printWrongInt("impossible");
  }
}
void ScalarConvert::printFloat(std::string str) {
  if (str.length() == 0)
    printGoodFloat2(0);
  else if (str.length() > 1 && !isdigit(str[0]) && !isdigit(str[1]) &&
           str.compare("-inf") && str.compare("-inff") && str.compare("+inf") &&
           str.compare("+inff") && str.compare("nan") && str.compare("nanf"))
    printWrongFloat("impossible");
  else if (str.length() == 1 && !isdigit(str[0])) {
    printException2Float(static_cast<char>(str[0]));
  } else if (std::strtof(str.c_str(), NULL) >= -999999999999.0 &&
             std::strtof(str.c_str(), NULL) <= FLT_MAX) {
    if (str.find(".") == std::string::npos ||
        (str.length() == str.find(".") + 1))
      printGoodFloat2(std::strtof(str.c_str(), NULL));
    else
      printGoodFloat(std::strtof(str.c_str(), NULL));
  } else {
    if (!str.compare("-inf") || !str.compare("-inff"))
      printExceptionFloat("-inf");
    else if (!str.compare("+inf") || !str.compare("+inff"))
      printExceptionFloat("+inf");
    else if (!str.compare("nan") || !str.compare("nanf"))
      printExceptionFloat("nan");
    else
      printWrongFloat("impossible");
  }
}

void ScalarConvert::printDouble(std::string str) {
  if (str.length() == 0)
    printGoodDouble2(0);
  else if (str.length() > 1 && !isdigit(str[0]) && !isdigit(str[1]) &&
           str.compare("-inf") && str.compare("-inff") && str.compare("+inf") &&
           str.compare("+inff") && str.compare("nan") && str.compare("nanf")) {
    printWrongDouble("impossible");
  } else if (str.length() == 1 && !isdigit(str[0])) {
    { printException2Double(static_cast<char>(str[0])); }
  } else if (std::strtod(str.c_str(), NULL) >= -999999999999 &&
             std::strtod(str.c_str(), NULL) <= DBL_MAX) {
    if (str.find(".") == std::string::npos ||
        (str.length() == str.find(".") + 1))
      printGoodDouble2(std::strtod(str.c_str(), NULL));
    else
      printGoodDouble(std::strtod(str.c_str(), NULL));

  } else {
    if (!str.compare("-inf") || !str.compare("-inff"))
      printExceptionDouble("-inf");
    else if (!str.compare("+inf") || !str.compare("+inff"))
      printExceptionDouble("+inf");
    else if (!str.compare("nan") || !str.compare("nanf"))
      printExceptionDouble("nan");
    else
      printWrongDouble("impossible");
  }
}
