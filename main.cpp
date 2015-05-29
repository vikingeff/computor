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
	std::size_t		found=str.find("^");
	
	while (found<str.size())
	{
		if (found < str.size())
		{
			if (str[found+1]<48 || str[found+1]>51)
				throw Computor::PowerException();
		}
		found=str.find("^", found+1);
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
	std::cout<<"diff between parenthesis closed or open : "<<index<<std::endl;
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

void			check_operand(std::string &str)
{
	(void)str;
}

void			simplify(std::string &str)
{
	// int				xval=0;
	// int				x2val=0;
	// int				intval=0;
	std::size_t		found=0;
	//int				index=0;

	found=str.find("x^0");
	if (found < str.size())
	{
		std::cout<<"char after ^ simplified : "<<str[found+3]<<std::endl;
	}
}

int 			main(int argc, char **argv)
{
	
	std::string 	cleaned;
	int				vreturn = 0;

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
			//check_operand(cleaned);
			simplify(cleaned);
		}
		catch (std::exception &error)
		{
			std::cout << RED"Error : " << GRAY"This is not a valid equation : "<<error.what()<<NC << std::endl;
			try
			{
				Computor::EqualException &buffer = dynamic_cast<Computor::EqualException &>(error);
				(void)buffer;
				vreturn=2;
			}
			catch (std::exception &dcast)
			{
				try
				{
					Computor::ParenthesisException &buffer2 = dynamic_cast<Computor::ParenthesisException &>(error);
					(void)buffer2;
					vreturn=3;
				}
				catch (std::exception &dcast)
				{
					try
					{
						Computor::CharsException & buffer3 = dynamic_cast<Computor::CharsException &>(error);
						(void)buffer3;
						vreturn=4;
					}
					catch (std::exception &dcast)
					{
						try
						{
							Computor::PowerException & buffer4 = dynamic_cast<Computor::PowerException &>(error);
							(void)buffer4;
							vreturn=5;
						}
						catch (std::exception &dcast)
						{
							vreturn=6;
						}
					}
				}
			}
			return (vreturn);
		}
			std::cout << GREEN"Succes : " << GRAY"This is a valid equation."NC << std::endl;
	}
	// else
	// {
	// 	std::cout << RED"Usage : " << GRAY"./computor equation of maximum degree 2"NC << std::endl;
	// 	vreturn = 1;
	// }
	std::cout<<"vreturn : "<<vreturn<<std::endl;
	return (vreturn);
}
