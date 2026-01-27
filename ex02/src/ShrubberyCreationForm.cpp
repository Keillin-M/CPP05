/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:28:47 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/27 18:27:11 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

// Constructors and destructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) 
	: AForm("SchrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Member functions
void ShrubberyCreationForm::createShrubbery() const {
	std::ofstream file(target + "_shrubbery");
	if (!file.is_open()) {
		std::cerr << "Error: cannot create file " << target << std::endl;
		return ;
	}
	file << "      /\\         /\\         /\n"
			"     /**\\       /**\\       /**\\n"
			"    /****\\     /****\\     /****\\n"
			"   /******\\   /******\\   /******\\n"
			"  /********\\ /********\\ /********\\n"
			"      ||         ||         ||\n"
			"      ||         ||         ||\n\n";
	file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() < 1)
		throw AForm::GradeTooHighException();
	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	createShrubbery();
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > grade_sign)
		throw AForm::GradeTooLowException();
	sign = true;
}
