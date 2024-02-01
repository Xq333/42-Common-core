/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:27:04 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/09/30 21:27:04 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T> const T &min(T const &x, T const &y) {
  return y <= x ? y : x;
};

template <typename T> const T &max(T const &x, T const &y) {
  return y >= x ? y : x;
};

template <typename T> void swap(T &x, T &y) {
  T tmp = x;
  x = y;
  y = tmp;
};
