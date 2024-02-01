/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:30:35 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/09/29 10:30:36 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cfloat>
#include <climits>
#include <cstdlib>
#include <iostream>
#define RED "\033[1;31m" // FOR DESTRUCTORS
#define GRN "\033[1;32m" // FOR CONSTRUCTORS
#define YEL "\033[1;33m" // FOR ERRORS
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define W "\033[1;97m"
#define NC "\033[1;0m"
#define I "\033[1;3m"
#define U "\033[1;4m"

class ScalarConvert {
public:
  static void convert(std::string str);
  static void printChar(std::string str);
  static void printInt(std::string str);
  static void printFloat(std::string str);
  static void printDouble(std::string str);
  static void printGoodChar(char c);
  static void printWrongChar(std::string str);
  static void printGoodInt(int c);
  static void printWrongInt(std::string str);
  static void printGoodFloat(float c);
  static void printGoodFloat2(float c);
  static void printExceptionFloat(std::string str);
  static void printException2Float(int t);
  static void printWrongFloat(std::string str);
  static void printGoodDouble(double c);
  static void printGoodDouble2(double c);
  static void printExceptionDouble(std::string str);
  static void printException2Double(int t);
  static void printWrongDouble(std::string str);

private:
  ScalarConvert();
  ScalarConvert(ScalarConvert const &origin);
  ~ScalarConvert();

  ScalarConvert &operator=(ScalarConvert const &origin);
};
