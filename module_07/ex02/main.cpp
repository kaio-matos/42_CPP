/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/05 20:30:01 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
void printArray(std::string name, Array<T> array) {
    std::cout << name << " ";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test cases
    try {
        // Default constructor: empty array
        Array<int> emptyArray;
        std::cout << "Empty Array size: " << emptyArray.size() << std::endl;
        printArray("Empty Array:", emptyArray);

        // Constructor with a parameter: array of 5 elements initialized by default
        Array<double> initializedArray(5);
        initializedArray[0] = 33.22;
        std::cout << "Initialized Array size: " << initializedArray.size() << std::endl;
        printArray("Initialized Array:", initializedArray);

        // Copy constructor
        Array<int> originalArray(3);
        originalArray[0] = 1;
        originalArray[1] = 2;
        originalArray[2] = 3;

        // Assignment operator
        Array<int> copiedArray = originalArray;
        copiedArray[1] = 99;

        printArray("Original Array:", originalArray);

        printArray("Copied Array:", copiedArray);

        // Trying to access an empty array should throw an error
        // std::cout << emptyArray[0] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
