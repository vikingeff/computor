/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 13:02:59 by gleger            #+#    #+#             */
/*   Updated: 2015/05/28 13:03:04 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Operator.class.hpp>

Operator::Operator()
{
	Operator::_nbOperator++;
	std::cout << "Operator Default constructor called." << std::endl;
}

Operator::Operator(Operator const & ref)
{
	Operator::_nbOperator++;
	std::cout << "Operator Copy constructor called." << std::endl;
	*this = ref;
}

Operator::~Operator()
{
	Operator::_nbOperator--;
	std::cout << "Operator Destructor called." << std::endl;
}

Operator &			Operator::operator=(Operator const & source)
{

	std::cout << "Operator Assignation operator called" << std::endl;
	(void)source;
	//do some stuff
	return (*this);
}

int			Operator::getNbOperator()
{
	return(Operator::_nbOperator);
}

int	Operator::_nbOperator=0;
