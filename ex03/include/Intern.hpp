/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:43:05 by kmaeda            #+#    #+#             */
/*   Updated: 2026/03/25 16:39:15 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern &other);
		~Intern();

		AForm* makeForm(const std::string& name, const std::string& target);
};

#endif
