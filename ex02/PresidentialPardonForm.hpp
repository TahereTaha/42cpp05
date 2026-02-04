/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:23:00 by tatahere          #+#    #+#             */
/*   Updated: 2026/02/04 20:42:55 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <stdexcept>


class PresidentialPardonForm : public AForm
{
	private:
	protected:
	public:

		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm & src);
		~PresidentialPardonForm(void);
		PresidentialPardonForm & operator = (const PresidentialPardonForm & src);

		PresidentialPardonForm(const std::string &target);

		void	acction(void) const ;
};


