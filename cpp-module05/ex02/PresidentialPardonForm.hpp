#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "form.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
public:
    // canonical
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
    void executeAction() const;
};

#endif
