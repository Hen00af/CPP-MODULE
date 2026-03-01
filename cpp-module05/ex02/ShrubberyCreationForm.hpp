#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "form.hpp"
#include <string>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        // canonical
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
}
#endif
