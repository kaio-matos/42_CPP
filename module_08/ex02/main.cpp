/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/28 20:37:18 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int main()
{
	MutantStack<int> mstack;
	std::cout << "\nPDF \n" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top:  "<< mstack.top() << std::endl;
	mstack.pop();
	std::cout << "After pop -> Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "MutantStack: " << *it << std::endl;
			++it;
		}
    }
	{
		std::cout << "\n\nComparing stacks\n" << std::endl;
		std::stack<int> s(mstack);
		MutantStack<int> ms(mstack);
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		while (rit != rite)
		{
			std::cout << "Stack       MutantStack" << std::endl;
			std::cout << s.top() << "           " << *rit << std::endl;
			s.pop();
			++rit;
		}
	}
	return 0;
}
