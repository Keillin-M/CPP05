/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:36:08 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/29 13:55:03 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    std::srand(std::time(0));
    Intern intern;
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 50);
    Bureaucrat charlie("Charlie", 146);

    // Test ShrubberyCreationForm
    std::cout << "\n=== Test: ShrubberyCreationForm via Intern ===\n";
    AForm* shrub = intern.makeForm("shrubbery creation", "Ana");
    if (shrub) {
        try {
            alice.signForm(*shrub);
            alice.executeForm(*shrub);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        delete shrub;
    }

    // Test RobotomyRequestForm
    std::cout << "\n=== Test: RobotomyRequestForm via Intern ===\n";
    AForm* robot = intern.makeForm("robotomy request", "Tania");
    if (robot) {
        try {
            bob.signForm(*robot);
            bob.executeForm(*robot);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        delete robot;
    }

    // Test PresidentialPardonForm
    std::cout << "\n=== Test: PresidentialPardonForm via Intern ===\n";
    AForm* pardon = intern.makeForm("presidential pardon", "Gab");
    if (pardon) {
        try {
            alice.signForm(*pardon);
            alice.executeForm(*pardon);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        delete pardon;
    }

    // Test with an invalid form name
    std::cout << "\n=== Test: Invalid Form via Intern ===\n";
    AForm* invalid = intern.makeForm("invalid form", "Nobody");
    if (invalid) delete invalid;

    // Test grade too low for signing/executing
    std::cout << "\n=== Test: Grade Too Low ===\n";
    AForm* shrub2 = intern.makeForm("shrubbery creation", "Kei");
    if (shrub2) {
        try {
            charlie.signForm(*shrub2);
            charlie.executeForm(*shrub2);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        delete shrub2;
    }

    return 0;
}

