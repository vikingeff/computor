/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:04:11 by gleger            #+#    #+#             */
/*   Updated: 2015/04/19 19:04:31 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computor.hpp>

std::string		&trim_right_inplace(std::string &s, const std::string& delimiters = " \f\n\r\t\v")
{
	return s.erase(s.find_last_not_of(delimiters) + 1);
}

std::string		&trim_left_inplace(std::string &s, const std::string& delimiters = " \f\n\r\t\v")
{
	return s.erase(0, s.find_first_not_of(delimiters));
}

std::string		&trim_inplace(std::string& s, const std::string& delimiters = " \f\n\r\t\v")
{
	return trim_left_inplace(trim_right_inplace(s, delimiters), delimiters);
}

void			check_pow(std::string &str)
{
	std::size_t		found=0;

	found=str.find("^");
	if (found < str.size())
	{
		if (str[found+1]<48 || str[found+1]>50)
			throw Computor::PowerException();
	}
}

void			check_equals(std::string &str)
{
	std::size_t		found=0;

	found=str.find("=");
	found=str.find("=", found+1);
	if (found<str.size())
		throw Computor::EqualException();
}

void			check_parenthesis(std::string &str)
{
	std::size_t		found=0;
	int				index=0;

	found=str.find("(");
	while (found<str.size())
	{
		index++;
		found=str.find("(", found+1);
	}
	found=0;
	found=str.find(")");
	while (found<str.size())
	{
		index--;
		found=str.find(")", found+1);
	}
	std::cout<<index<<std::endl;
	if (index!=0)
		throw Computor::ParenthesisException();
}

void			check_constistancy(std::string &str)
{
	std::string 	authorised[]={"x", "X", "²", "^", "=", "(", ")", "+", "-", "*", "/", " "};
	int 			loop=0;

	for (loop=0; loop<(int)str.size(); loop++)
	{
		int index=0;
		if (str[loop]>=48 && str[loop]<=57)
			continue;
		for (index=0; index<12; index++)
		{
			if (str[loop]==authorised[index][0])
				break;
		}
		if (index==12)
			throw Computor::CharsException();
	}

}

int main(int argc, char **argv)
{
	
	std::string cleaned;

	if (argc==2)
	{
		std::string equation=argv[1];

		equation = trim_inplace(equation);
		cleaned = equation;
		cleaned.erase(remove_if(cleaned.begin(), cleaned.end(), isspace), cleaned.end());
		std::cout << YELLOW"Your entry : " << GRAY<<equation<<NC << std::endl;
		std::cout << CYAN"Cleaned entry : " << GRAY<<cleaned<<NC << std::endl;
		
		try
		{
			check_constistancy(cleaned);
			check_equals(cleaned);
			check_parenthesis(cleaned);
			check_pow(cleaned);
		}
		catch (Computor::EqualException &e)
		{
			std::cout << RED"Error : " << GRAY"This is not a valid equation : "<<e.what()<<NC << std::endl;
			return 2;
		}
		catch (Computor::ParenthesisException &e)
		{
			std::cout << RED"Error : " << GRAY"This is not a valid equation : "<<e.what()<<NC << std::endl;
			return 3;
		}
		catch (Computor::CharsException &e)
		{
			std::cout << RED"Error : " << GRAY"This is not a valid equation : "<<e.what()<<NC << std::endl;
			return 4;
		}
		catch (Computor::PowerException &e)
		{
			std::cout << RED"Error : " << GRAY"This is not a valid equation : "<<e.what()<<NC << std::endl;
			return 5;
		}
		//if (loop==(int)equation.size())
			std::cout << GREEN"Succes : " << GRAY"This is a valid equation."NC << std::endl;
	}
	else
		std::cout << RED"Usage : " << GRAY"./computor equation of maximum degree 2"NC << std::endl;
	return 0;
}
