/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:23:00 by tatahere          #+#    #+#             */
/*   Updated: 2026/01/31 16:13:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <stdexcept>


class ShrubberyCreationForm : public AForm
{
	private:
	protected:
	public:

		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm & src);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator = (const ShrubberyCreationForm & src);

		ShrubberyCreationForm(const std::string &target);

		void	acction(void) const ;
};


