/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/06 20:35:32 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void printInt(int i) {
	std::cout << i << std::endl;
}

int main(void)
{
	std::vector<int> vector;
	std::list<int> list;
	std::deque<int> deque;

    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);

	list.insert(list.begin(), 0);
	list.insert(list.begin(), 1);
	list.insert(list.begin(), 2);

	deque.push_back(99);
	deque.push_back(200);
	deque.push_back(300);

	std::cout << "Vector elements: " << std::endl;
	std::for_each(vector.begin(), vector.end(), printInt);
	std::cout << "--------------" << std::endl;
    std::cout << "List elements: " << std::endl;
	std::for_each(list.begin(), list.end(), printInt);
	std::cout << "--------------" << std::endl;
    std::cout << "Deque elements: " << std::endl;
	std::for_each(deque.begin(), deque.end(), printInt);
	std::cout << "--------------" << std::endl;


	std::cout << "Vector " << *easyfind(vector, 20) << std::endl;
	std::cout << "List   " << *easyfind(list, 2) << std::endl;
	std::cout << "Deque  " << *easyfind(deque, 200) << std::endl;

	// error
	// std::cout << *easyfind(list, 33) << std::endl;

	return 0;
}
