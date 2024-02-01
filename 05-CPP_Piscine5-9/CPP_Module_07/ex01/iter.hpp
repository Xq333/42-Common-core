/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:44:21 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/09/30 21:44:22 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <iostream>

template <typename T> void iter(T *array, int length, void f(T &)) {
  for (int i = 0; i < length; i++)
    f(array[i]);
};

template <typename T> void iter(T *array, int length, void f(T const &)) {
  for (int i = 0; i < length; i++)
    f(array[i]);
};

template <typename T> void printer(T &d) { std::cout << d << ", "; }

template <typename T> void increment(T &d) { d++; }

template <typename T> void decrement(T &d) { d--; }
