/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2025/12/08 19:58:07 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	//	burecrat instantiation.
	{
		std::cout << "//\t\t\t\tburecrat instantiation." << std::endl;
		{
			std::cout << "\n\n\t\tstandard constructor." << std::endl;
			Bureaucrat	bureaucrat_n3241;
			
			std::cout << "name: " << bureaucrat_n3241.getName() << std::endl;
			std::cout << "grade: " << bureaucrat_n3241.getGrade() << std::endl;
			std::cout << bureaucrat_n3241 << std::endl;
		}
		{
			std::cout << "\n\n\t\tname grade constructor." << std::endl;
			{
				Bureaucrat	bureaucrat_n3241("n3241", 50);

				std::cout << "name: " << bureaucrat_n3241.getName() << std::endl;
				std::cout << "grade: " << bureaucrat_n3241.getGrade() << std::endl;
				std::cout << bureaucrat_n3241 << std::endl;
			}
			{
				std::cout << "tryng to make a burocrat with a grade of 0" << std::endl;
				try
				{
					Bureaucrat	bureaucrat_n3241("n3241", 0);
				}
				catch (const Bureaucrat::GradeTooLowException& e)
				{
					std::cout << "\tkind grade too low exception." << std::endl;
					std::cout << "\t" << e.what() << std::endl;
				}
				catch (const Bureaucrat::GradeTooHighException& e)
				{
					std::cout << "\tkind grade too high exception." << std::endl;
					std::cout << "\t" << e.what() << std::endl;
				}
				
				std::cout << "tryng to make a burocrat with a grade of 200" << std::endl;
				try
				{
					Bureaucrat	bureaucrat_n3241("n3241", 200);
				}
				catch (const Bureaucrat::GradeTooLowException& e)
				{
					std::cout << "\tkind grade too low exception." << std::endl;
					std::cout << "\t" << e.what() << std::endl;
				}
				catch (const Bureaucrat::GradeTooHighException& e)
				{
					std::cout << "\tkind grade too high exception." << std::endl;
					std::cout << "\t" << e.what() << std::endl;
				}

			}
		}
	}
	std::cout << "\n\n\n\n\t\t\t\tbureaucrat methods." << std::endl;
	{
		Bureaucrat	bureaucrat_n3241("jef", 5);
		try
		{
			for (int i = 0; i < 200 ; i++)
			{
				std::cout << bureaucrat_n3241 << std::endl;
				bureaucrat_n3241.incrementGrade();
			}
		}
		catch (const std::range_error & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Bureaucrat	bureaucrat_n3241("bob", 145);
		try
		{
			for (int i = 0; i < 200 ; i++)
			{
				std::cout << bureaucrat_n3241 << std::endl;
				bureaucrat_n3241.decrementGrade();
			}
		}
		catch (const std::range_error & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
