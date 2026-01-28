/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:43:05 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/28 20:33:59 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

class Intern {
	public:
		Intern(const std::string& target);
		Intern(const Intern& other);
		Intern& operator=(const Intern &other);
		~Intern();

		AForm* makeForm(std::string name, std::string target);
};

#endif
