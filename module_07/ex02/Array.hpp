/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/29 20:09:33 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>
#include <iomanip>
#include <iostream>

template<typename T>
class Array {
public:
    Array<T>(void): _list(NULL), _length(0) {}

    Array<T>(unsigned int n): _list(new T[n]()), _length(n) {}

    Array<T>(const Array<T> &value): _list(new T[value._length]()), _length(value._length) {
        for (size_t i = 0; i < value._length; i++) {
            this->_list[i] = value[i];
        }
    }

    Array<T> &operator=(const Array<T> &value){
        if (this->_list) delete [] this->_list;

        this->_list = new T[value._length];
        this->_length = value._length;
        for (size_t i = 0; i < this->_length; i++) {
            this->_list[i] = value[i];
        }
        return *this;
    }

    ~Array<T>(void){
        if (this->_list) delete [] this->_list;
        this->_length = 0;
    }

    T &operator[](size_t index) const {
        if (index >= this->_length) {
            throw std::exception();
        }
        return this->_list[index];
    }

    size_t size(void) const {
        return this->_length;
    }

private:
    T      *_list;
    size_t _length;
};

#endif
