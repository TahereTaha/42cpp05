/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:23:00 by tatahere          #+#    #+#             */
/*   Updated: 2026/02/05 00:32:53 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

#define FORM_GRADE_HIGHEST				1
#define FORM_GRADE_LOWEST				150
#define FORM_NOT_SIGNED					0
#define FORM_SIGNED						1

#define FORM_DEFAULT_NAME				"no_name"
#define FORM_DEFAULT_GRADE_TO_SIGN		100
#define FORM_DEFAULT_GRADE_TO_EXECUTE	50


class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	protected:
	public:

		AForm(void);
		AForm(const AForm & src);
		virtual ~AForm(void);
		AForm & operator = (const AForm & src);

		AForm(const std::string & name, const int gradeToSign, const int gradeToExecute);
		
		void	beSigned(const Bureaucrat & signee);

		std::string	getName(void) const ;
		int			getIsSigned(void) const ;
		int			getGradeToSign(void) const ;
		int			getGradeToExecute(void) const ;

		void		execute(const Bureaucrat &executor) const ;

		virtual void	acction(void) const = 0 ;
		
		class GradeTooHighException : public std::range_error
		{
			public:
				GradeTooHighException(const std::string & msg);
		};
		class GradeTooLowException : public std::range_error
		{
			public:
				GradeTooLowException(const std::string & msg);
		};
};

std::ostream & operator << (std::ostream & out_s, const AForm & obj);

