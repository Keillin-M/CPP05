/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:36:54 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/27 18:53:01 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";	
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form not signed";
}
	
// Constructors and destructors
AForm::AForm(std::string const &name, int grade_sign, int grade_exec) : name(name), sign(false), 
	grade_sign(grade_sign), grade_exec(grade_exec) {
	if (grade_sign < 1 || grade_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), sign(other.sign), grade_sign(other.grade_sign), grade_exec(other.grade_exec) {}

AForm& AForm::operator=(const AForm &other) {
	if (this != &other)
		this->sign = other.sign;
	return *this;
}

AForm::~AForm() {}

// Member functions
std::string AForm::getName() const {
	return name;
}

int AForm::getGradeSign() const {
	return grade_sign;
}

int AForm::getGradeExec() const {
	return grade_exec;
}

bool AForm::getSigned() const {
	return sign;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > grade_sign)
		throw AForm::GradeTooLowException();
	sign = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
	    out << "Form: " << form.getName()
        << "\nSigned: " << (form.getSigned() ? "yes" : "no")
        << "\nGrade to sign: " << form.getGradeSign()
        << "\nGrade to exec: " << form.getGradeExec() << std::endl;
    return out;
}
