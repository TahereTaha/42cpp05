/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:43:30 by tatahere          #+#    #+#             */
/*   Updated: 2025/12/08 19:59:52 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

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

#endif
