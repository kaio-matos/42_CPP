/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/06 20:33:56 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <vector>
# include <deque>
# include <list>
# include <iostream>
# include <algorithm>
# include <string>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int n);

#include "easyfind.tpp"

#endif

