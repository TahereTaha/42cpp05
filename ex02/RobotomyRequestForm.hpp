/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:23:00 by tatahere          #+#    #+#             */
/*   Updated: 2026/02/04 19:50:11 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <stdexcept>


class RobotomyRequestForm : public AForm
{
	private:
	protected:
	public:

		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm & src);
		~RobotomyRequestForm(void);
		RobotomyRequestForm & operator = (const RobotomyRequestForm & src);

		RobotomyRequestForm(const std::string &target);

		void	acction(void) const ;
};


