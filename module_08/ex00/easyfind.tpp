/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:30:47 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/06 20:32:51 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);

	if (it == container.end()) {
		throw std::runtime_error("Value not found");
	}
	return (it);
}

#endif
