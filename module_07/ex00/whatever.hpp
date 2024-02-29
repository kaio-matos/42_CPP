/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/28 21:18:53 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

template<typename T>
T const &max(T const & a, T const & b) {
    if (a > b) {
        return a;
    } else if (a == b) {
		return b;
	}
    return b;
}

template<typename T>
T const &min(T const & a, T const & b) {
    if (a < b) {
        return a;
    } else if (a == b) {
		return b;
	}
    return b;
}

template<typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

#endif
