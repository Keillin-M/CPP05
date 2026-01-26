/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:29:59 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/26 19:56:19 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Bureaucrat.hpp"

#include "include/Form.hpp"

int main() {
	std::cout << "=== Test 1: Normal construction ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 2: Grade too high (0) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 3: Grade too low (151) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 4: Increment ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 5);
		std::cout << alice << std::endl;
		alice.increment();
		std::cout << "After increment: " << alice << std::endl;
		alice.increment();
		std::cout << "After increment: " << alice << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 5: Decrement ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 148);
		std::cout << charlie << std::endl;
		charlie.decrement();
		std::cout << "After decrement: " << charlie << std::endl;
		charlie.decrement();
		std::cout << "After decrement: " << charlie << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 6: Increment at grade 1 (should throw) ===" << std::endl;
	try {
		Bureaucrat top("Boss", 1);
		std::cout << top << std::endl;
		top.increment();
		std::cout << "After increment: " << top << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 7: Decrement at grade 150 (should throw) ===" << std::endl;
	try {
		Bureaucrat bottom("Intern", 150);
		std::cout << bottom << std::endl;
		bottom.decrement();
		std::cout << "After decrement: " << bottom << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 8: Copy constructor ===" << std::endl;
	try {
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 9: Assignment operator ===" << std::endl;
	try {
		Bureaucrat a("PersonA", 10);
		Bureaucrat b("PersonB", 100);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
		b = a;
		std::cout << "After b = a:" << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
		std::cout << "(Note: B keeps its name, only grade changes)" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 10: Getters ===" << std::endl;
	try {
		Bureaucrat dave("Dave", 75);
		std::cout << "Name: " << dave.getName() << std::endl;
		std::cout << "Grade: " << dave.getGrade() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 11: Form creation and info ===" << std::endl;
	try {
		Form f1("TaxForm", 100, 50);
		std::cout << f1 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 12: Form signing success ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 50);
		Form f2("Permit", 100, 50);
		std::cout << f2 << std::endl;
		bob.signForm(f2); // Should succeed
		std::cout << f2 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 13: Form signing failure ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		Form secret("TopSecret", 1, 1);
		intern.signForm(secret); // Should fail
		std::cout << secret << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

		std::cout << std::endl << "=== Test 14: Form signing even if execute is lower ===" << std::endl;
	try {
		Bureaucrat intern("Analyst", 50);
		Form secret("Papers", 50, 20);
		intern.signForm(secret); // Should fail
		std::cout << secret << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
