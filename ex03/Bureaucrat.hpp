/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:43:30 by tatahere          #+#    #+#             */
/*   Updated: 2026/02/02 19:20:52 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class AForm;

#define BUREAUCRAT_GRADE_HIGHEST	1
#define BUREAUCRAT_GRADE_LOWEST		150

#define BUREAUCRAT_DEFAULT_NAME		"no_name"
#define BUREAUCRAT_DEFAULT_GRADE	50

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat(void);
		Bureaucrat(const Bureaucrat & src);
		~Bureaucrat(void);
		Bureaucrat & operator = (const Bureaucrat & src);

		Bureaucrat(std::string name, int grade);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);

		void	signForm(AForm &formToSign);
		void	executeForm(AForm &formToExecute);

		class GradeTooLowException : public std::range_error
		{
			public:
				GradeTooLowException(const std::string & msg);
		};
		class GradeTooHighException : public std::range_error
		{
			public:
				GradeTooHighException(const std::string & msg);
		};
};

std::ostream & operator << (std::ostream & out_s, const Bureaucrat & obj);
