/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2026/01/11 16:28:22 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <string>
#include <iostream>
#include <stdexcept>
#include <typeinfo>

#include "terminal_colors.h"

int	main(void)
{
	// form instantiation.
	{
		std::cout << "\n";
		std::cout << "//" << std::endl;
		std::cout << "//\tform instantiation." << std::endl;
		std::cout << "//" << std::endl;
		std::cout << std::endl;
		{
			std::cout << "\n//\tstandard constructor.\n" << std::endl;
			{
				Form	form_3241;

				std::cout << "name: " << form_3241.getName() << std::endl;
				std::cout << "is signed: " << form_3241.getIsSigned() << std::endl;
				std::cout << "grade to sign: " << form_3241.getGradeToSign() << std::endl;
				std::cout << "grade to execute: " << form_3241.getGradeToExecute() << std::endl;
				std::cout << form_3241 << std::endl;
			}
		}
		{
			std::cout << "\n//\tcustom constructor.\n" << std::endl;
			{
				std::cout << "\n//\t\tmaking one without incorrect values.\n" << std::endl;
				Form	form_3241("form_3241", 50, 10);

				std::cout << "name: " << form_3241.getName() << std::endl;
				std::cout << "is signed: " << form_3241.getIsSigned() << std::endl;
				std::cout << "grade to sign: " << form_3241.getGradeToSign() << std::endl;
				std::cout << "grade to execute: " << form_3241.getGradeToExecute() << std::endl;
				std::cout << form_3241 << std::endl;
			}
			{
				std::cout << "\n//\t\tmaking the grade to sign -2.\n" << std::endl;
				try 
				{
					Form	form_3241("typo_form_3241", -2, 59);
				}
				catch (const std::exception& e)
				{
					std::cout << RED "EXCEPTION CAUGHT:" RESET << std::endl;
					std::cout 
						<< "\tthe type of the exception is:\t" 
						<< typeid(e).name() 
						<< std::endl;
					std::cout << "\tthe error msg is:\t\t" << e.what() << std::endl;
				}
			}
			{
				std::cout << "\n//\t\tmaking the grade to sign 200.\n" << std::endl;
				try 
				{
					Form	form_3241("typo_form_3241", 200, 59);
				}
				catch (const std::exception& e)
				{
					std::cout << RED "EXCEPTION CAUGHT:" RESET << std::endl;
					std::cout 
						<< "\tthe type of the exception is:\t" 
						<< typeid(e).name() 
						<< std::endl;
					std::cout << "\tthe error msg is:\t\t" << e.what() << std::endl;
				}
			}
			{
				std::cout << "\n//\t\tmaking the grade to execute -5.\n" << std::endl;
				try 
				{
					Form	form_3241("typo_form_3241", 20, -5);
				}
				catch (const std::exception& e)
				{
					std::cout << RED "EXCEPTION CAUGHT:" RESET << std::endl;
					std::cout 
						<< "\tthe type of the exception is:\t" 
						<< typeid(e).name() 
						<< std::endl;
					std::cout << "\tthe error msg is:\t\t" << e.what() << std::endl;
				}
			}
			{
				std::cout << "\n//\t\tmaking the grade to execute 500.\n" << std::endl;
				try 
				{
					Form	form_3241("typo_form_3241", 20, 500);
				}
				catch (const std::exception& e)
				{
					std::cout << RED "EXCEPTION CAUGHT:" RESET << std::endl;
					std::cout 
						<< "\tthe type of the exception is:\t" 
						<< typeid(e).name() 
						<< std::endl;
					std::cout << "\tthe error msg is:\t\t" << e.what() << std::endl;
				}
			}
		}
	}
	return (0);
}
