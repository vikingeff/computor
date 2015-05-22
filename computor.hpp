/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:04:15 by gleger            #+#    #+#             */
/*   Updated: 2015/04/19 17:51:48 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COMPUTOR_HPP_
# define _COMPUTOR_HPP_

# include <list>
# include <vector>
# include <string>
# include <iostream>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define ORANGE "\033[0;33m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[0;35m"
# define GRAY "\033[1;30m"
# define NC "\033[0m"

class Computor
{

	public : class EqualException : public std::exception
	{
	public:
		//GradeTooHighException();
		//GradeTooHighException(GradeTooHighException const & ref);
		//virtual ~GradeTooHighException() throw();

		//GradeTooHighException & 		operator=(GradeTooHighException const & source);
		virtual const char* what() const throw ()
		{
			return ("There is more than 1 equal characters.");
		}
	};

	public : class ParenthesisException : public std::exception
	{
	public:
		//GradeTooLowException();
		//GradeTooLowException(GradeTooLowException const & ref);
		//virtual ~GradeTooLowException() throw();

		//GradeTooLowException &			operator=(GradeTooLowException const & source);
		virtual const char* what() const throw ()
		{
			return ("One parenthesis or more is open without being closed or closed without being opened.");
		}
	};

	public : class CharsException : public std::exception
	{
	public:
		//GradeTooLowException();
		//GradeTooLowException(GradeTooLowException const & ref);
		//virtual ~GradeTooLowException() throw();

		//GradeTooLowException &			operator=(GradeTooLowException const & source);
		virtual const char* what() const throw ()
		{
			return ("One character at least isn't authorised.");
		}
	};

	public : class PowerException : public std::exception
	{
	public:
		//GradeTooLowException();
		//GradeTooLowException(GradeTooLowException const & ref);
		//virtual ~GradeTooLowException() throw();

		//GradeTooLowException &			operator=(GradeTooLowException const & source);
		virtual const char* what() const throw ()
		{
			return ("The equation can't be of third degree or more.");
		}
	};
};

#endif