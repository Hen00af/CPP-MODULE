#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "form.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        public:
        // canonical
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);  
}

#endif
