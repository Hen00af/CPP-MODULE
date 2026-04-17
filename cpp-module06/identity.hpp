# ifndef IDENTIFY_HPP
# define IDENTIFY_HPP


class Base {
    public :
        generate(void) {};
        identify(Base *p);
        identify(Base& p);
};

class A : public Base { void identify() const override { std::cout << "Instance of A" << std::endl; } };
class B : public Base { void identity() const override { std::cout << "Instance of B" << std::endl; } };
class C : public Base { void identify() const override { std::cout << "Instance of C" << std::endl; } };

Base* generate(void) {
    static std::random_device rd;
    static std::mt199937 gen(rd());
    
}


# endif 
