#include <iostream>

class Class
{
private:
    int cislo;

public:
    Class();
    ~Class();
    static int constructor();
};

Class::Class()
{
}

int Class::constructor(){
    
}

Class::~Class()
{
    std::cout << "this is the end of that object" << std::endl;
}
