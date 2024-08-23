#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Alice");
        PresidentialPardonForm pardon("Charlie");

        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        bob.signForm(shrubbery);
        bob.signForm(robotomy);
        bob.signForm(pardon);

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        bob.executeForm(shrubbery);
        bob.executeForm(robotomy);
        bob.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 150);
        ShrubberyCreationForm shrubbery("garden");

        std::cout << alice << std::endl;
        std::cout << shrubbery << std::endl;

        alice.signForm(shrubbery); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat charlie("Charlie", 1);
        RobotomyRequestForm robotomy("Bob");

        std::cout << charlie << std::endl;
        std::cout << robotomy << std::endl;

        charlie.signForm(robotomy);
        charlie.executeForm(robotomy);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat dave("Dave", 25);
        PresidentialPardonForm pardon("Eve");

        std::cout << dave << std::endl;
        std::cout << pardon << std::endl;

        dave.signForm(pardon);
        dave.executeForm(pardon); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
