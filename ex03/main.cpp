/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:36:08 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/28 19:37:02 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(std::time(0));
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 50);
    Bureaucrat charlie("Charlie", 146);
	Bureaucrat david("David", 1);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Robotomy Request");
    PresidentialPardonForm pardon("Gab");

    // Shrubbery
         std::cout << "\n=== Test 1: ShrubberyCreationForm - Not signed ===\n";
    try {
        alice.executeForm(shrub);
    } 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	
		std::cout << "\n=== Test 2: ShrubberyCreationForm - Signed ===\n";
    try {
        alice.signForm(shrub);
        alice.executeForm(shrub);
    } 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Robotomy
	        std::cout << "\n=== Test 3: RobotomyRequestForm  - Not signed ===\n";
    try {
        bob.executeForm(robot); 
    } 
	catch (std::exception &e) {
    	std::cout << e.what() << std::endl;
    }
	
        std::cout << "\n=== Test 4: RobotomyRequestForm - Signed ===\n";
    try {
		bob.signForm(robot);
        bob.executeForm(robot);
		david.executeForm(robot);
    } 
	catch (std::exception &e) {
    	std::cout << e.what() << std::endl;
    }

    // Presidential Pardon
        std::cout << "\n=== Test 5: PresidentialPardonForm ===\n";
    try {
    	alice.signForm(pardon);
        alice.executeForm(pardon);
    } 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Test grade too low
        std::cout << "\n=== Test 6: Grade Too Low Test ===\n";
    try {
        charlie.signForm(shrub);
        charlie.executeForm(shrub);
    } 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
