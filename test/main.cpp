#include "../headers/Serialise.h"
#include "Dog.h"
#include "TestSchema.h"
#include <string>
#include <iostream>

int main()
{
    Dog dog = { "baa!", "pink", 52 };

    std::cout << "Serialise..." << std::endl;
    std::string s = Serialise::To<TestSchema>(dog);
    std::cout << s << std::endl;

    std::cout << "Deserialise..." << std::endl;
    Dog clone = Serialise::From<TestSchema, Dog>(s);
    std::cout << clone.barkType << std::endl;

    return 0;
}
