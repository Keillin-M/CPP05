/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:14:02 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/26 18:51:07 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Form;

class Bureaucrat {
	private:
		std::string const name;
		int grade;
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
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		// Member functions
		std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
