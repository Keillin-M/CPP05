/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:36:54 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/26 19:51:23 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";	
}
	
// Constructors and destructors
Form::Form(std::string const &name, int grade_sign, int grade_exec) : name(name), sign(false), 
	grade_sign(grade_sign), grade_exec(grade_exec) {
	if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), sign(other.sign), grade_sign(other.grade_sign), grade_exec(other.grade_exec) {}

Form& Form::operator=(const Form &other) {
	if (this != &other)
		this->sign = other.sign;
	return *this;
}

Form::~Form() {}

// Member functions
std::string Form::getName() const {
	return name;
}

int Form::getGradeSign() const {
	return grade_sign;
}

int Form::getGradeExec() const {
	return grade_exec;
}

bool Form::getSigned() const {
	return sign;
}

void Form::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > grade_sign)
		throw Form::GradeTooLowException();
	sign = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	    out << "Form: " << form.getName()
        << "\nSigned: " << (form.getSigned() ? "yes" : "no")
        << "\nGrade to sign: " << form.getGradeSign()
        << "\nGrade to exec: " << form.getGradeExec() << std::endl;
    return out;
}
