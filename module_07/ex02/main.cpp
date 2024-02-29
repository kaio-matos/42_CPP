/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/28 19:58:24 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <ostream>

template<typename T>
void printArray(std::string name, Array<T> array) {
    std::cout << name << " ";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

typedef struct Complex {
    std::string name;
    int         age;
} Complex;

std::ostream& operator<<(std::ostream& os, Complex complex) {
    os << "[Name: '" << complex.name << "' Age: '" << complex.age << "']";
    return os;
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

        Array<int> originalArray(3);
        originalArray[0] = 1;
        originalArray[1] = 2;
        originalArray[2] = 3;

        // Copy constructor
        Array<int> copiedArray(originalArray);
        copiedArray[1] = 112;
        // Assignment operator
        Array<int> assignedArray = originalArray;
        assignedArray[1] = 99;

        printArray("Original Array:", originalArray);
        printArray("Copied Array:", copiedArray);
        printArray("Assigned Array:", assignedArray);

        Array<Complex> complexArray(3);
        Complex bobby = { .name = "Bobby", .age = 33 };
        complexArray[2] = bobby;
        printArray("Complex Array:", complexArray);

        // Trying to access an empty array should throw an error
        // std::cout << emptyArray[0] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
