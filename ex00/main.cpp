/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2026/01/10 17:20:08 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "terminal_colors.h"

int	main(void)
{
	//	bureaucrat instatiation.
//	if (0)
	{
		std::cout << "\n";
		std::cout << "//" << std::endl;
		std::cout << "//\tburecrat instantiation." << std::endl;
		std::cout << "//" << std::endl;
		std::cout << std::endl;
		{
			std::cout << "\n//\tstandard constructor.\n" << std::endl;
			{
				Bureaucrat	bureaucrat_n3241;
				
				std::cout << "name: " << bureaucrat_n3241.getName() << std::endl;
				std::cout << "grade: " << bureaucrat_n3241.getGrade() << std::endl;
				std::cout << bureaucrat_n3241 << std::endl;
			}
		}
		{
			std::cout << "\n//\tname grade constructor.\n" << std::endl;
			{
				std::cout << "\n//\t\tmaking one without any incorect values.\n" << std::endl;
				Bureaucrat	bureaucrat_n3241("n3241", 50);

				std::cout << "name: " << bureaucrat_n3241.getName() << std::endl;
				std::cout << "grade: " << bureaucrat_n3241.getGrade() << std::endl;
				std::cout << bureaucrat_n3241 << std::endl;
			}
			{
				std::cout << "\n//\t\ttryng to make a burocrat with a grade of 0.\n" << std::endl;
				try
				{
					Bureaucrat	bureaucrat_n3241("n3241", 0);
				}
				catch (const std::exception& e)
				{
					std::cout << RED "EXCEPTION CAUGHT:" RESET << std::endl;
					std::cout 
						<< "\tthe type of the exception is:\t" 
						<< typeid(e).name() 
						<< std::endl;
					std::cout << "\the error msg is:\t\t" << e.what() << std::endl;
				}
				
				std::cout << "\n//\t\ttryng to make a burocrat with a grade of 200\n" << std::endl;
				try
				{
					Bureaucrat	bureaucrat_n3241("n3241", 200);
				}
				catch (const std::exception& e)
				{
					std::cout << RED "EXCEPTION CAUGHT:" RESET << std::endl;
					std::cout 
						<< "\tthe type of the exception is:\t" 
						<< typeid(e).name() 
						<< std::endl;
					std::cout << "\the error msg is:\t\t" << e.what() << std::endl;
				}
			}
		}
	}
	//	bureaucrat methods.
//	if (0)
	{
		std::cout << "\n";
		std::cout << "//" << std::endl;
		std::cout << "//\tmedthods." << std::endl;
		std::cout << "//" << std::endl;
		std::cout << std::endl;
		{
			std::cout << "\n//\tstandard use of the methods.\n" << std::endl;
			{
				std::cout << "\n//\t\tusing the incrementGrade().\n" << std::endl;
				Bureaucrat	bureaucrat_n3241("jef", 50);
				std::cout << bureaucrat_n3241 << std::endl;
				for (int i = 0; i < 5 ; i++)
				{
					bureaucrat_n3241.incrementGrade();
					std::cout << bureaucrat_n3241 << std::endl;
				}
			}
			{
				std::cout << "\n//\t\tusing the decrementGrade().\n" << std::endl;
				Bureaucrat	bureaucrat_n3241("bob", 50);
				std::cout << bureaucrat_n3241 << std::endl;
				for (int i = 0; i < 5 ; i++)
				{
					bureaucrat_n3241.decrementGrade();
					std::cout << bureaucrat_n3241 << std::endl;
				}
			}
		}
		{
			std::cout << "\n//\tforsing a exception with the methods.\n" << std::endl;
			{
				std::cout << "\n//\t\tusing the incrementGrade().\n" << std::endl;
				Bureaucrat	bureaucrat_n3241("jef", 5);
				std::cout << bureaucrat_n3241 << std::endl;
				try
				{
					for (int i = 0; i < 10 ; i++)
					{
						bureaucrat_n3241.incrementGrade();
						std::cout << bureaucrat_n3241 << std::endl;
					}
				}
				catch (const std::exception& e)
				{
					std::cout << RED "EXCEPTION CAUGHT:" RESET << std::endl;
					std::cout 
						<< "\tthe type of the exception is:\t" 
						<< typeid(e).name() 
						<< std::endl;
					std::cout << "\the error msg is:\t\t" << e.what() << std::endl;
				}
				
			}
			{
				std::cout << "\n//\t\tusing the decrementGrade().\n" << std::endl;
				Bureaucrat	bureaucrat_n3241("bob", 145);
				std::cout << bureaucrat_n3241 << std::endl;
				try
				{
					for (int i = 0; i < 10 ; i++)
					{
						bureaucrat_n3241.decrementGrade();
						std::cout << bureaucrat_n3241 << std::endl;
					}
				}
				catch (const std::exception& e)
				{
					std::cout << RED "EXCEPTION CAUGHT:" RESET << std::endl;
					std::cout 
						<< "\tthe type of the exception is:\t" 
						<< typeid(e).name() 
						<< std::endl;
					std::cout << "\the error msg is:\t\t" << e.what() << std::endl;
				}
				
			};
		}
	}
	return (0);
}
