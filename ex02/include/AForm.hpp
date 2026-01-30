/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:36:45 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/30 10:52:01 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		std::string const name;
		bool sign;
		int const grade_sign;
		int const grade_exec;
	public:
		// Exception classes
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
	
		// Constructors and destructors
		AForm(std::string const &name, int grade_sign, int grade_exec);
		AForm(const AForm& other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

		// Member functions
		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSigned() const;
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
