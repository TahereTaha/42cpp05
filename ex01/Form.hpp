#pragma once

#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	protected:
	public:

		Form(void);
		Form(const Form & src);
		~Form(void);
		Form & operator = (const Form & src);

		Form(const std::string & name, const int gradeToSign, const int gradeToExecute);
		
		void	beSigned(const Bureaucrat & signee);

		std::string	getName(void) const ;
		int			getIsSigned(void) const ;
		int			getGradeToSign(void) const ;
		int			getGradeToExecute(void) const ;

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

std::ostream & operator << (std::ostream & out_s, const Form & obj);

