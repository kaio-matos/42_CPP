/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/05 20:23:06 by kmatos-s         ###   ########.fr       */
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

    Array<T>(unsigned int n) {
        this->_list = new T[n];
        this->_length = n;
        for (size_t i = 0; i < this->_length; i++) {
            this->_list[i] = T();
        }
    }

    Array<T>(const Array<T> &value) {
        const size_t valueLength = value.size();
        this->_list = new T[valueLength];
        for (size_t i = 0; i < valueLength; i++) {
            this->_list[i] = value[i];
        }
        this->_length = valueLength;
    }

    Array<T> &operator=(const Array<T> &value){
        if (this->_list) delete [] this->_list;

        const size_t valueLength = value.size();
        this->_list = new T[valueLength];
        for (size_t i = 0; i < valueLength; i++) {
            this->_list[i] = value[i];
        }
        this->_length = valueLength;
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
