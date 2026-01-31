/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2026/01/31 17:27:16 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <string>
#include <iostream>
#include <stdexcept>
#include <typeinfo>

#include "terminal_colors.h"

int	main(void)
{
	std::cout << "//" << std::endl;
	std::cout << "//\ttexsting the execute method." << std::endl;
	std::cout << "//" << std::endl;
	{
		std::cout  <<  "\n//\ttesting correct values.\n" << std::endl;
		Bureaucrat  employe4132("jef", 50);
		std::cout << employe4132 << std::endl;

		AForm *form_x = new ShrubberyCreationForm("home");
		std::cout << *form_x << std::endl;

		employe4132.signForm(*form_x);
		form_x->execute(employe4132);
	}
	{
		std::cout  <<  "\n//\ttesting form not signed.\n" << std::endl;
		Bureaucrat  employe4132("jef", 50);
		std::cout << employe4132 << std::endl;

		AForm *form_x = new ShrubberyCreationForm("home");
		std::cout << *form_x << std::endl;

		try
		{
			form_x->execute(employe4132);
		}
		catch (const std::exception &e)
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
		std::cout  <<  "\n//\ttesting form to high execution level.\n" << std::endl;
		Bureaucrat  employe4132("jef", 140);
		std::cout << employe4132 << std::endl;

		AForm *form_x = new ShrubberyCreationForm("home");
		std::cout << *form_x << std::endl;

		employe4132.signForm(*form_x);
		try
		{
			form_x->execute(employe4132);
		}
		catch (const std::exception &e)
		{
			std::cout << RED "EXCEPTION CAUGHT:" RESET << std::endl;
			std::cout 
				<< "\tthe type of the exception is:\t" 
				<< typeid(e).name() 
				<< std::endl;
			std::cout << "\tthe error msg is:\t\t" << e.what() << std::endl;
		}
	}

	

	return (0);
}
