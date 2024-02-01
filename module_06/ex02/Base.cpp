/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/31 22:37:37 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base::~Base(void)
{
}

Base *Base::generate(void) {
    std::srand(time(NULL));
    int random = std::rand() % 3 + 1;

    if (random == 1) {
        // std::cout << "Generating A" << std::endl;
        return new A();
    }
    if (random == 2) {
        // std::cout << "Generating B" << std::endl;
        return new B();
    }
    // std::cout << "Generating C" << std::endl;
    return new C();
}

void Base::identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "By Pointer   -> Type: A class " << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p) != NULL) {
    std::cout << "By Pointer   -> Type: B class " << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "By Pointer   -> Type: C class " << std::endl;
        return;
    }
}

void Base::identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "By Reference -> Type: A class " << std::endl;
    } catch (std::exception &e) {}
    try {
        dynamic_cast<B&>(p);
        std::cout << "By Reference -> Type: B class" << std::endl;
    } catch (std::exception &e) {}
    try {
        dynamic_cast<C&>(p);
        std::cout << "By Reference -> Type: C class" << std::endl;
    } catch (std::exception &e) {}
}
