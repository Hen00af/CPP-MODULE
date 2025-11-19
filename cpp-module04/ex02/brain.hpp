#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
    Brain();
    Brain(const Brain &other);
    Brain& operator=(const Brain &other);
    ~Brain();

    const std::string& getIdea(int idx) const;
    void setIdea(int idx, const std::string& str);

private:
    std::string ideas[100];
};

#endif
