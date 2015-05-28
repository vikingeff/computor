/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 13:03:09 by gleger            #+#    #+#             */
/*   Updated: 2015/05/28 13:03:11 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_CLASS_HPP
# define OPERATOR_CLASS_HPP

# include <iostream>
# include <string>

class Operator
{

public:
	Operator();
	Operator(Operator const & ref);
	~Operator();

	Operator &				operator=(Operator const & source);
	static int				getNbOperator();

private:
	static int				_nbOperator;

};

#endif
