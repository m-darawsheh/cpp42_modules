#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#define PPF_SIGN_GRADE 25
#define PPF_EXEC_GRADE 5
#include "AForm.hpp"



// virtual void execute(Bureaucrat const & executor) const = 0 ;




class PresidentialPardonForm : public AForm
{
    public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &obj);

    PresidentialPardonForm(const std::string &target);
    void execute(Bureaucrat const & executor) const;
};

#endif