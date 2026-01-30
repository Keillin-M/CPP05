/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:28:55 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/29 12:05:07 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../include/RobotomyRequestForm.hpp"
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

// Constructors and destructors
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) 
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
	: AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Member functions
void RobotomyRequestForm::requestRobotomy() const {
	std::cout << "Zrrr... (drilling noises)" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed on " << target << "." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	if (executor.getGrade() > getGradeExec())
		throw Bureaucrat::GradeTooLowException();
	requestRobotomy();
}
