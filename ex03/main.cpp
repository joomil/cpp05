#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        Intern someRandomIntern;
        AForm* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            bob.signForm(*rrf);
            bob.executeForm(*rrf);
            delete rrf;
        }

        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
        if (scf) {
            bob.signForm(*scf);
            bob.executeForm(*scf);
            delete scf;
        }

        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Alice");
        if (ppf) {
            bob.signForm(*ppf);
            bob.executeForm(*ppf);
            delete ppf;
        }

        AForm* invalidForm = someRandomIntern.makeForm("invalid form", "target");
        if (invalidForm) {
            delete invalidForm;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
