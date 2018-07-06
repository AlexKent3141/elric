#include "../../include/Serialise.h"
#include "Json.h"
#include "Pokemon.h"
#include <iostream>

int main()
{
    Pokemon pikachu = { "pikachu", 25, true };
    std::cout << Serialise::To<Json>(pikachu) << std::endl;

    // Expected output:
    // {"name":"pikachu","id":25}

    return 0;
};
