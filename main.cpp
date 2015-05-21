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

void			check_eq(std::string& str)
{
	std::size_t		found=0;
	found=str.find("=");
	found=str.find("=", found+1);
	if (found<str.size())
		throw Computor::EqualException();
}

void			check_pa(std::string& str)
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

int				check_constistancy(std::string& str)
{
	(void)str;
	return 0;
}

int main(int argc, char **argv)
{
	std::string authorised[]={"x", "X", "²", "^", "=", "(", ")", "+", "-", "*", "/", " "};
	std::string cleaned;

	if (argc==2)
	{
		std::string equation=argv[1];
		int loop=0;

		equation = trim_inplace(equation);
		cleaned = equation;
		cleaned.erase(remove_if(cleaned.begin(), cleaned.end(), isspace), cleaned.end());
		std::cout << YELLOW"Your entry : " << GRAY<<equation<<NC << std::endl;
		std::cout << CYAN"Cleaned entry : " << GRAY<<cleaned<<NC << std::endl;
		for (loop=0; loop<(int)equation.size(); loop++)
		{
			int index=0;
			if (equation[loop]>=48 && equation[loop]<=57)
				continue;
			for (index=0; index<12; index++)
			{
//				std::cout<<equation[loop]<< " - "<<authorised[index][0]<<std::endl;
				if (equation[loop]==authorised[index][0])
				{
//					std::cout<<"ok"<<std::endl;
					break;
				}	
			}
			if (index==12)
			{
				std::cout << RED"Error : " << GRAY"This is not a valid equation."NC << std::endl;
				return 1;
			}
		}
		try
		{
			check_eq(cleaned);
			check_pa(cleaned);
		}
		catch (Computor::EqualException &e)
		{
			std::cout << RED"Error : " << GRAY"This is not a valid equation : "<<e.what()<<NC << std::endl;
			return 2;
		}
		catch (Computor::ParenthesisException &e)
		{
			std::cout << RED"Error : " << GRAY"This is not a valid equation : "<<e.what()<<NC << std::endl;
			return 2;
		}
		if (loop==(int)equation.size())
			std::cout << GREEN"Succes : " << GRAY"This is a valid equation."NC << std::endl;
	}
	else
		std::cout << RED"Usage : " << GRAY"./computor equation of maximum degree 2"NC << std::endl;
	return 0;
}
