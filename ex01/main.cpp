#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        Form formA("FormA", 1, 10);

        std::cout << bob << std::endl;
        std::cout << formA << std::endl;

        bob.signForm(formA);
        std::cout << formA << std::endl;

        bob.incrementGrade();
        bob.signForm(formA); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 149);
        Form formB("FormB", 150, 150);

        std::cout << alice << std::endl;
        std::cout << formB << std::endl;

        alice.signForm(formB);
        std::cout << formB << std::endl;

        alice.decrementGrade();
        alice.signForm(formB); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat charlie("Charlie", 1);
        Form formC("FormC", 0, 10); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat dave("Dave", 150);
        Form formD("FormD", 151, 150); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
