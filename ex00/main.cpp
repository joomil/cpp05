#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.incrementGrade(); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 149);
        std::cout << alice << std::endl;

        alice.decrementGrade();
        std::cout << alice << std::endl;

        alice.decrementGrade(); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
