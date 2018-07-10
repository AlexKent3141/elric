#ifndef __POKEMON_H__
#define __POKEMON_H__

#include "../../include/MetaProperty.h"

struct Pokemon
{
    std::string name;
    int id;
    bool likesBerries;
    int battlesPerDayLastWeek[7];

    bool operator==(const Pokemon& other) const
    {
        bool equal = name == other.name && id == other.id && likesBerries == other.likesBerries;
        for (int i = 0; i < 7; i++)
        {
            equal &= (battlesPerDayLastWeek[i] == other.battlesPerDayLastWeek[i]);
        }

        return equal;
    }

    constexpr static auto metaProperties = std::make_tuple(
        MetaProperty(&Pokemon::name, "name"),
        MetaProperty(&Pokemon::id, "id"),
        MetaProperty(&Pokemon::likesBerries, "likesBerries"),
        MetaProperty(&Pokemon::battlesPerDayLastWeek, "battlesPerDayLastWeek")
    );
};

#endif // __POKEMON_H__
