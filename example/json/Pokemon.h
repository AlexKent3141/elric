#ifndef __POKEMON_H__
#define __POKEMON_H__

#include "../../include/MetaProperty.h"

struct Pokemon
{
    std::string name;
    int id;

    constexpr static auto metaProperties = std::make_tuple(
        MetaProperty(&Pokemon::name, "name"),
        MetaProperty(&Pokemon::id, "id")
    );
};

#endif // __POKEMON_H__
