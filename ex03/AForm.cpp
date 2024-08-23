#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm::AForm(const AForm &other)
    : name(other.name), signedStatus(other.signedStatus), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->signedStatus = other.signedStatus;
    }
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return signedStatus;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

void AForm::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
