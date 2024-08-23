#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

Form::Form(const Form &other)
    : name(other.name), signedStatus(other.signedStatus), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->signedStatus = other.signedStatus;
    }
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return signedStatus;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

void Form::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
