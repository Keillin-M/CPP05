/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:29:02 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/28 18:13:23 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "../include/PresidentialPardonForm.hpp"
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

// Constructors and destructors
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) 
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// Member functions
void PresidentialPardonForm::pardon() const {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() < 1)
		throw AForm::GradeTooHighException();
	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	pardon();
}
