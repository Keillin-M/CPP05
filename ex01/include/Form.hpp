/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:36:45 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/26 19:08:22 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
	private:
		std::string const name;
		bool sign;
		int const grade_sign;
		int const grade_exec;
	public:
		// Exception classes
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
	
		// Constructors and destructors
		Form(std::string const &name, int grade_sign, int grade_exec);
		Form(const Form& other);
		Form& operator=(const Form &other);
		~Form();

		// Member functions
		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSigned() const;
		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
