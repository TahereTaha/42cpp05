/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2026/01/30 21:11:08 by tatahere         ###   ########.fr       */
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

	//	form methods.
	{
		std::cout << "\n";
		std::cout << "//" << std::endl;
		std::cout << "//\tmedthods." << std::endl;
		std::cout << "//" << std::endl;
		std::cout << std::endl;
		{
			std::cout << "\n//\tusing the method beSigned.\n" << std::endl;
			{
				std::cout << "\n//\t\t\tstandard use of the method.\n" << std::endl;
				{
					Bureaucrat	employe4132("martin", 50);
					std::cout << employe4132 << std::endl;
					
					Form		form4132("church tax deductions", 100, 70);
					std::cout << form4132 << std::endl;

					form4132.beSigned(employe4132);
				}
				std::cout << "\n//\t\t\teronius us of the method, ";
				std::cout << "trying to sign a form with grade to low.\n" << std::endl;
				{
					Bureaucrat	employe4132("martin", 120);
					std::cout << employe4132 << std::endl;
					
					Form		form4132("church tax deductions", 100, 70);
					std::cout << form4132 << std::endl;

					try
					{
						form4132.beSigned(employe4132);
					}
					catch (std::exception &e)
					{
						std::cout << RED "EXCEPTION CAUGHT:" RESET << std::endl;
						std::cout 
							<< "\tthe type of the exception is:\t" 
							<< typeid(e).name() 
							<< std::endl;
						std::cout << "\tthe error msg is:\t\t" << e.what() << std::endl;
					}
				}
				std::cout << "\n//\t\t\teronius us of the method, ";
				std::cout << "trying to sign a form twice.\n" << std::endl;
				{
					Bureaucrat	employe4132("martin", 50);
					std::cout << employe4132 << std::endl;
					
					Form		form4132("church tax deductions", 100, 70);
					std::cout << form4132 << std::endl;

					form4132.beSigned(employe4132);
					try
					{
						form4132.beSigned(employe4132);
					}
					catch (std::exception &e)
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
	}
	return (0);
}
