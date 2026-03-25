/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:36:08 by kmaeda            #+#    #+#             */
/*   Updated: 2026/03/25 15:59:43 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(std::time(0));
    
    std::cout << "\n=== Creation of Bureaucrats ===\n";

    Bureaucrat alice("Alice", 1);
    std::cout << alice << std::endl;
    Bureaucrat bob("Bob", 50);
    std::cout << bob << std::endl;
    Bureaucrat charlie("Charlie", 146);
    std::cout << charlie << std::endl;
	Bureaucrat david("David", 45);
    std::cout << david << std::endl;
    
    std::cout << "\n=== Creation of Forms ===\n";
    ShrubberyCreationForm shrub("home");
    std::cout << shrub << std::endl;
    RobotomyRequestForm robot("Robotomy Request");
    std::cout << robot << std::endl;
    PresidentialPardonForm pardon("Gab");
    std::cout << pardon << std::endl;

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
        bob.executeForm(pardon);
    	alice.signForm(pardon);
        bob.executeForm(pardon);
        alice.executeForm(pardon);
    } 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Test grade too low
        std::cout << "\n=== Test 6: Form already signed and Grade Too Low Test ===\n";
    try {
        charlie.signForm(shrub);
        
        ShrubberyCreationForm shrub1("home1");
        std::cout << shrub1 << std::endl;
        charlie.signForm(shrub1);
        charlie.executeForm(shrub);
    } 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
