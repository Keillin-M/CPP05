/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:43:21 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/29 13:50:31 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

// Constructors and destructors
Intern::Intern() {}

Intern::Intern(const Intern& other) {(void)other;}

Intern& Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

// Member functions
AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			switch (i) {
				case 0: {
					AForm* form = new ShrubberyCreationForm(target);
					std::cout << "Intern creates " << name << std::endl;
					return form;
				}
				case 1: {
					AForm* form = new RobotomyRequestForm(target);
					std::cout << "Intern creates " << name << std::endl;
					return form;
				}
				case 2: {
					AForm* form = new PresidentialPardonForm(target);
					std::cout << "Intern creates " << name << std::endl;
					return form;
				}
			}
		}
	}
	std::cout << "Intern cannot create " << name << std::endl;
	return 0;
}
