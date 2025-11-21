#include "brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    for (int i = 0; i<100; i++){
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain &other)
{
    if(this != &other){
        for (int i = 0; i<100; i++){
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

const std::string& Brain::getIdea(int idx) const
{
    if (idx >= 0 && idx < 100) {
        return ideas[idx];
    }
    static std::string empty = "";
    return empty;
}

void Brain::setIdea(int idx, const std::string& str)
{
    if (idx >= 0 && idx < 100) {
        ideas[idx] = str;
    }
}
