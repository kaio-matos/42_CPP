/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/09 20:58:16 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CPP
#define RPN_CPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN {

public:
	RPN(std::string expression);
	RPN(const RPN &value);
	RPN &operator=(const RPN &value);
	~RPN(void);


private:
	std::string _rawExpression;
};

#endif
