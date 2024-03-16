/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/14 19:40:01 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CPP
#define RPN_CPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include <dirent.h>

class RPN {

public:
	RPN(std::string expression);
	RPN(const RPN &value);
	RPN &operator=(const RPN &value);
	~RPN(void);


private:
	std::string _rawExpression;

	bool _assert(bool exp) const;
	bool _getNumber(std::string::iterator &ch, std::string::iterator end, int &value) const;
};

#endif
