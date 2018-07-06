#include "../../include/Serialise.h"
#include "JsonReader.h"
#include "JsonWriter.h"
#include "Pokemon.h"
#include <iostream>

int main()
{
    Pokemon pikachu = { "pikachu", 25, true };

    // Serialise pikachu.
    std::string ser = Serialise::To<JsonWriter>(pikachu);
    std::cout << ser << std::endl;

    // Expected output:
    // {"name":"pikachu","id":25,"likesBerries":true}

    // Deserialise and check that an equivalent pikachu was constructed.
    Pokemon target = Serialise::From<JsonReader, Pokemon>(ser);
    std::cout << "The same Pokemon? " << (target == pikachu ? "Y" : "N") << std::endl;

    return 0;
};
