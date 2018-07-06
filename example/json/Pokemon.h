#ifndef __POKEMON_H__
#define __POKEMON_H__

#include "../../include/MetaProperty.h"

struct Pokemon
{
    std::string name;
    int id;
    bool likesBerries;

    constexpr static auto metaProperties = std::make_tuple(
        MetaProperty(&Pokemon::name, "name"),
        MetaProperty(&Pokemon::id, "id"),
        MetaProperty(&Pokemon::likesBerries, "likesBerries")
    );
};

#endif // __POKEMON_H__
